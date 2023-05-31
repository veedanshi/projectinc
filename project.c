#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[50];
	int train_num;
	int num_of_seats;
	int clas;
}pd;
char src[10];
char dest[10];




/FUNCTION PROTOTYPE*/
//function prototypes to be used
void reservation(char[], char[]);							//main reservation function
void viewdetails(char[], char[]);							//view details of all the trains
void cancel(void);
void printticket(char name[], int, int, float);	//print ticket
void specifictrain(int);						//print data related to specific train
float charge(int, int, int);							//charge automatically w.r.t number of seats and train
void login();


/*FUNCTION DECLARATION*/



int main()

{
	system("cls");
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|              BROUGHT TO YOU BY                |\n");
	printf("\t\t|           |       GROUP 7         |             |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");


	printf(" \n Press any key to continue:");

	getch();
	system("cls");
	login();
	int menu_choice, choice_return;
start:
	system("cls");
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Exit");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d", &menu_choice);
	switch (menu_choice)
	{
	case 1:

		printf("The source codes for metropolitan stations are:\n");
		printf("New Delhi: NDLS\n");
		printf("Mumbai: MUM\n");
		printf("Chennai: CHN\n");
		printf("Kolkata: KLK\n");
		printf("Enter source  to view details of trains");
		scanf("%s", src);
		printf("Enter destination to view details of trains");


		scanf("%s", dest);
		reservation(src, dest);		//Fucntion still not added
		break;
	case 2:
		printf("The source codes for metropolitan stations are:\n");
		printf("New Delhi: NDLS\n");
		printf("Mumbai: MUM\n");
		printf("Chennai: CHN\n");
		printf("Kolkata: KLK\n");
		printf("Enter source  to view details of trains");
		scanf("%s", src);
		printf("Enter destination to view details of trains");


		scanf("%s", dest);


		viewdetails(src, dest);
		printf("\n\nPress any key to go to Main Menu..");
		getch();
		break;
	case 3:
		cancel();

		break;
	case 4:
		return(0);
	default:
		printf("\nInvalid choice");
	}
	goto start;
	return(0);
}


void viewdetails(char s[10], char d[10])
{
	system("cls");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------");

	printf("\nTr.No\tTrain Name\tDeparture and Arrival Destination\t\t Class\tCharges\t\tTime Departure\t\tTime Arrival\n");
	printf("-------------------------------------------------------------------------------------------------------------------------------------------");
	if (strcmp(s, "NDLS") == 0 && strcmp(d, "MUM") == 0)
	{
		printf("\n22222\tCsmt Rajdhani\t H Nizamuddin to C Shivaji Mah T\t\t1AC\tRs.5,360\t\t16:55\t\t11:15");
		printf("\n22222\tCsmt Rajdhani\t H Nizamuddin to C Shivaji Mah T\t\t 2AC\tRs.4,423\t\t16:55\t\t11:15");

		printf("\n12472\t Swaraj Express\t New delhi to Bandra Terminus\t\t\t1AC\tRs. 3,910\t\t21:40\t\t16:10");
		printf("\n12472\t Swaraj Express\t New delhi to Bandra Terminus\t\t\t2AC\tRs. 2,980\t\t21:40\t\t16:10");
	}
	else if (strcmp(s, "NDLS") == 0 && strcmp(d, "KLK") == 0)
	{
		printf("\n12314\tSealdah Rajdhni \tNew Delhi to Sealdah\t\t1AC\tRs.5210\t\t 16:30\t\t10:10");
		printf("\n12314\tSealdah Rajdhni \tNew Delhi to Sealdah\t\t2AC\tRs.4490\t\t 16:30\t\t10:10");
	}
	else if (strcmp(s, "KLK") == 0 && strcmp(d, "NDLS") == 0)
	{


		printf("\n12311\tNetaji Express\tHowrah Jn to Subzi Mandi\t\t\t1AC\tRs.4045\t\t21:55\t\t21:24");
		printf("\n12311\tNetaji Express\tHowrah Jn to Subzi Mandi\t\t\t2AC\tRs.3780\t\t21:55\t\t21:24");
	}
	//delhi to chennai
	else if (strcmp(s, "NDLS") == 0 && strcmp(d, "CHN") == 0)
	{


		printf("\n12622\tTamilnadu Exp\t\tNew delhi to Chennai Central \t\t1AC\tRs.3625\t\t21:05\t\t6:15(33hrs 10mins)");
		printf("\n12622\tTamilnadu Exp\t\tNew delhi to Chennai Central \t\t2AC\tRs.2134\t\t21:05\t\t6:15(33hrs 10mins)");
	}
	else if (strcmp(s, "CHN") == 0 && strcmp(d, "NDLS") == 0)
	{
		printf("\n12615\tGrand Trunk Exp\tChennai Central to Hazrat Nizamuddin \t\t1AC\tRs.3100\t\t18:50\t\t4:40(33hrs 50mins)");
		printf("\n12615\tGrand Trunk Exp\tChennai Central to Hazrat Nizamuddin \t\t2AC\tRs.2189\t\t18:50\t\t4:40(33hrs 50mins)");
	}

	//kolkata to chennai
	else if (strcmp(s, "KLK") == 0 && strcmp(d, "CHN") == 0)
	{
		printf("\n12841\tCoromandal Express \tKolkata Shalima to Chennai Central \t1AC\tRs.4460\t\t 15:20\t\t4:50(25 hrs 30 mins)");
		printf("\n12841\tCoromandal Express \tKolkata Shalima to Chennai Central \t2AC\tRs.3890\t\t 15:20\t\t4:50(25 hrs 30 mins)");
	}
	else if (strcmp(s, "CHN") == 0 && strcmp(d, "KLK") == 0)
	{
		printf("\n12507\tAronai Express \t Chennai Central to Dankuni \t\t\t1AC\tRs.2048\t\t 9:15\t\t11:36(26hrs 21 min)");
		printf("\n12507\tAronai Express \t Chennai Central to Dankuni \t\t\t2AC\tRs.1888\t\t 9:15\t\t11:36(26hrs 21 min)");
	}

	//kolkata to mumbai
	else if (strcmp(s, "MUM") == 0 && strcmp(d, "KLK") == 0)
	{


		printf("\n12809\tHowrah Mail \tKalyan Junction to Kolkata Shalima \t\t1AC\tRs.2885\t\t 22:10\t\t6:00(31hrs 50 mins)");
		printf("\n12809\tHowrah Mail \tKalyan Junction to Kolkata Shalima \t\t2AC\tRs.2385\t\t 22:10\t\t6:00(31hrs 50 mins)");
	}
	else if (strcmp(s, "KLK") == 0 && strcmp(d, "MUM") == 0)
	{



		printf("\n12321\tMumbai Mail \tKolkata howrah to Kalyan Junction \t\t1AC\tRs.5200\t\t 11:35\t\t11:37(36 hrs 2min)");
		printf("\n12321\tMumbai Mail \tKolkata howrah to Kalyan Junction \t\t2AC\tRs.3890\t\t 11:35\t\11:37(36 hrs 2min)");
	}
	//mumbai chennai
	else if (strcmp(s, "MUM") == 0 && strcmp(d, "CHN") == 0)
	{

		printf("\n12163\tLtt Mas exp\tMumbai Lokmanya Tilak Terminus to Chennai Central \t1AC \tRs.2725\t\t6:45\t \t16:30(21 hrs 45 mins)");
		printf("\n12163\tLtt Mas exp\tMumbai Lokmanya Tilak Terminus to Chennai Central \t2AC \tRs.2400\t\t6:45\t \t16:30(21 hrs 45 mins)");
	}
	else if (strcmp(s, "CHN") == 0 && strcmp(d, "MUM") == 0)
	{

		printf("\n12164\tAdi Humsafar \t \tChennai Central to Vasai Road \t\t 1AC\tRs. 2200\t \t16:00\t\t14:20(22 hrs 20 mins)");
		printf("\n12164\tAdi Humsafar \t \tChennai Central to Vasai Road \t\t 2AC\tRs. 1234\t \t16:00\t\t14:20(22 hrs 20 mins)");
	}

	//mumbai to delhhi
	else if (strcmp(s, "MUM") == 0 && strcmp(d, "NDLS") == 0)
	{
		printf("\n12431\tRajdhani Exp \t \tPanvel to Hazrat Nizamuddin\t\t1AC\tRs.4915 \t\t18:05\t\t12:30(18 hrs 25 mins)");
		printf("\n12431\tRajdhani Exp \t \tPanvel to Hazrat Nizamuddin\t\t2AC\tRs.2341 \t\t18:05\t\t12:30(18 hrs 25 mins)");
	}

	else
	{
		printf("invalid");
	}


}



void reservation(char s[10], char d[10])
{
	char confirm;
	int i = 0;

	float charges;
	pd passdetails;
	FILE* fp;
	fp = fopen("seats_reserved.txt", "a");
	system("cls");

	printf("\nEnter Your Name:> ");


	fflush(stdin);
	gets(passdetails.name);
	//error here have to take input of the name
	printf("\nEnter Number of seats:> ");
	scanf("%d", &passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails(s, d);
	printf("\n\nEnter train number:> ");

	scanf("%d", &passdetails.train_num);
	printf("Enter class you want reservation in\n ");
	scanf("%d", &passdetails.clas);


	charges = charge(passdetails.train_num, passdetails.num_of_seats, passdetails.clas);
	printticket(passdetails.name, passdetails.num_of_seats, passdetails.train_num, charges);



	printf("\n\nConfirm Ticket (y/n):>");
start:
	scanf(" %c", &confirm);
	if (confirm == 'y')
	{
		fprintf(fp, "%s\t\t%d\t\t%d\t\t%.2f\n", passdetails.name, passdetails.num_of_seats, passdetails.train_num, charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if (confirm == 'n') {
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	getch();
}

float charge(int train_num, int num_of_seats, int clas)
{
	if (train_num == 22222 && clas == 1)
	{
		return(5360.0 * num_of_seats);
	}
	if (train_num == 22222 && clas == 2)
	{
		return(4423.0 * num_of_seats);
	}
	if (train_num == 12472 && clas == 1)
	{
		return(3910.0 * num_of_seats);
	}
	if (train_num == 12472 && clas == 2)
	{
		return(2980.0 * num_of_seats);
	}
	if (train_num == 1005)
	{
		return(4000.0 * num_of_seats);
	}
	if (train_num == 12314 && clas == 1)
	{
		return(5210.0 * num_of_seats);
	}
	if (train_num == 12314 && clas == 2)
	{
		return(4490.0 * num_of_seats);
	}
	if (train_num == 12311 && clas == 1)
	{
		return(4045.0 * num_of_seats);
	}
	if (train_num == 12311 && clas == 2)
	{
		return(3780.0 * num_of_seats);
	}
	if (train_num == 12622 && clas == 1)
	{
		return(3625.0 * num_of_seats);
	}
	if (train_num == 12622 && clas == 2)
	{
		return(2134.0 * num_of_seats);
	}
	if (train_num == 12615 && clas == 1)
	{
		return(3100.0 * num_of_seats);
	}
	if (train_num == 12615 && clas == 2)
	{
		return(2189.0 * num_of_seats);
	}
	if (train_num == 12841 && clas == 1)
	{
		return(4460.0 * num_of_seats);
	}
	if (train_num == 12841 && clas == 2)
	{
		return(3890.0 * num_of_seats);
	}
	if (train_num == 12507 && clas == 1)
	{
		return(2048.0 * num_of_seats);
	}
	if (train_num == 12507 && clas == 2)
	{
		return(1888.0 * num_of_seats);
	}
	if (train_num == 12321 && clas == 1)
	{
		return(5200.0 * num_of_seats);
	}
	if (train_num == 12321 && clas == 2)
	{
		return(3890.0 * num_of_seats);
	}
	if (train_num == 12809 && clas == 1)
	{
		return(2885.0 * num_of_seats);
	}
	if (train_num == 12809 && clas == 2)
	{
		return(2385.0 * num_of_seats);
	}
	if (train_num == 12163 && clas == 1)
	{
		return(2725.0 * num_of_seats);
	}
	if (train_num == 12163 && clas == 2)
	{
		return(2400.0 * num_of_seats);
	}
	if (train_num == 12164 && clas == 1)
	{
		return(2200.0 * num_of_seats);
	}if (train_num == 12164 && clas == 2)
	{
		return(1234.0 * num_of_seats);
	}
	if (train_num == 12431 && clas == 1)
	{
		return(4915.0 * num_of_seats);
	}
	if (train_num == 12431 && clas == 2)
	{
		return(2341.0 * num_of_seats);
	}
}




void printticket(char name[], int num_of_seats, int train_num, float charges)
{
	system("cls");
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	printf("Name:\t\t\t%s", name);
	printf("\nNumber Of Seats:\t%d", num_of_seats);
	printf("\nTrain Number:\t\t%d", train_num);

	printf("\nCharges:\t\t%.2f", charges);
}





void login()
{
	int a = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	char user[10] = "user";
	char pass[10] = "pass";
	do
	{

		printf("\n  =======================  LOGIN FORM  =======================\n  ");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &uname);
		printf(" \n                       ENTER PASSWORD:-");
		while (i < 10)
		{
			pword[i] = getch();
			c = pword[i];
			if (c == 13) break;
			else printf("*");
			i++;
		}
		pword[i] = '\0';
		//char code=pword;
		i = 0;
		//scanf("%s",&pword);
		if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
		{
			printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
			printf("\n\n\n\t\t\t\tPress any key to continue...");
			getch();//holds the screen
			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			a++;

			getch();//holds the screen
			system("cls");
		}
	} while (a <= 2);
	if (a > 2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

	}
	system("cls");
}

void cancel()
{
	char name[50];
	int found = 0;
	FILE* fp1, * fp2;
	fp1 = fopen("seats_reserved.txt", "r");
	fp2 = fopen("temp.txt", "w");

	printf("\nEnter the name of the passenger to cancel the reservation: ");
	fflush(stdin);
	gets(name);

	char temp_name[50];
	int temp_seats, temp_train;
	float temp_charges;

	while (fscanf(fp1, "%s %d %d %f", temp_name, &temp_seats, &temp_train, &temp_charges) != EOF)
	{
		if (strcmp(temp_name, name) == 0)
		{
			found = 1;
			printf("\nReservation Details Cancelled:\n");
			printf("Name: %s\nNumber of Seats: %d\nTrain Number: %d\nCharges: %.2f\n", temp_name, temp_seats, temp_train, temp_charges);
		}
		else
		{
			fprintf(fp2, "%s %d %d %.2f\n", temp_name, temp_seats, temp_train, temp_charges);
		}
	}

	if (!found)
	{
		printf("\nNo reservation found with the given name.\n");
	}

	fclose(fp1);
	fclose(fp2);

	remove("seats_reserved.txt");
	rename("temp.txt", "seats_reserved.txt");
}
