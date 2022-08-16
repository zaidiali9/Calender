#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
string convertToString(char a[])
{
	int i;
	string s = "";
	for (i = 0; a[i] != '\0'; i++)
	{
		s = s + a[i];
	}
	return s;
}
void menu()
{
	cout << "Press 1 for the activities of the user" << endl;
	cout << "Press 2 to list 5 important activites" << endl;
	cout << "Press 3 for the availibility of the user" << endl;
	cout << "Press 4 to enter the user activity" << endl;
	cout << "Press 5 to get the month calender" << endl;
	cout << "Press 6 to get the hourly slots of the user" << endl;
	cout << "Press 7 to delete the user" << endl;
	cout << "Press 8 to exit" << endl;
	cout << "Press 9 to print calender stats" << endl;
	cout << "Press 10 to print the months stats" << endl;
}
void calenderprint()
{
	int countday = 0;
	string monthnames[12] = { "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC" };
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char daysname[7] = { 'S','M','T','W','T','F','S' };
	int year = 2022;
	int daystart;
	
	int a, b, c;
	a = (year - 1) / 4;
	b = (year - 1) / 100;
	c = (year - 1) / 400;
	daystart = (year + a - b + c) % 7;
	for (int i = 0;i < 12;i++)
	{
		cout << "--------" << monthnames[i] << "--------" << endl;
		for (int j = 0;j < 7;j++)
		{
			cout << daysname[j] << "  ";
		}
		cout << endl;
		for (int l = 0;l < daystart;l++)
		{
			cout << "   ";
		}
		countday = daystart;
		for (int k = 0;k < days[i];k++)
		{
			if (k + 1 <= 9)
			{
				cout << k + 1 << "  ";
			}
			else
			{
				cout << k + 1 << " ";
			}
			if (countday == 6)
			{
				cout << endl;
				countday = 0;
			}
			else
			{
				countday++;
			}

		}
		daystart = countday;
		cout << endl;
	}

}
struct activity 
{
	double priority;
	string userid;
	string actid;
	string title;
	int duration;
	int startingtime,endingtime;
	int monthnumber;
	int date;
	activity()
	{
		priority = 0.9;
		userid = "ALi hassan";
		title = "gym";
		startingtime = 1;
		endingtime = 0;
		monthnumber = 2;
		date = 1;
	}
	activity(double a, string userid1, string title1, int startingtime1, int endindtime1, int monthnumber1, int date1,string actid1)
	{
		priority = a;
		userid = userid1;
		title = title1;
		startingtime = startingtime1;
		endingtime = endindtime1;
		monthnumber = monthnumber1;
		date = date1;
		actid = actid1;
	}
	void print()
	{
		string monthnames[12] = { "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC" };
		cout << endl;
		cout <<"The userid is " << userid << endl;
		cout <<"The title is " << title << endl;
		cout <<"The actid of the user is " << actid << endl;
		cout <<"The month is " << monthnames[monthnumber-1] << endl;
		cout <<"The starting time of the activity is " << startingtime << endl;
		cout <<"The ending time of the user is " << endingtime << endl;
		cout <<"The duration of the activity is " << endingtime - startingtime << endl;
		cout <<"The priority of the activity is " << priority << endl;
	}
};
void fileread(activity***** a)
{
	
}
int main()
{
	activity***** calender,*obj,x;
	string userid4;
	int d=0;
	string monthnames[12] = { "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC" };
	obj = &x;
	char days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	calender = new activity ****[12];
	int a;
	for (int i = 0;i < 12;i++)
	{
		calender[i] = new activity***[days[i]];
		for (int j = 0;j<days[i];j++)
		{
			calender[i][j] = new activity * *[24];
			for (int k = 0;k < 24;k++)
			{
				calender[i][j][k] = new activity * [5];
				for (int l = 0;l < 5;l++)
				{
					calender[i][j][k][l] = nullptr;
				}
			}
		}
	}
	for (int i = 0;i < 12;i++)
	{
		for (int j = 0;j < days[i];i++)
		{
			for (int k = 0;k < 24;k++)
			{
				for (int l = 0;l < 5;l++)
				{
					calender[i][j][k][l] = nullptr;
				}
			}
		}
	}
	fstream file;string dat;char data[200];
	file.open("calendardat.txt", ios::in);
	if (!file)
	{
		cout << "NOT FOUND";
	}
	else
	{
		while (!file.eof())
		{
			int i = 0, month = 0, starttime = 0, endtime = 0;double a=0;
			char userid[10],title[100];
			char actid[10];
			string userid1, actid1, title1;
			file.getline(data,200);
			for (;data[i] != '/';i++)
			{
				d = (d * 10) + (data[i]-48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				month = (month * 10) + (data[i]-48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				starttime = (starttime * 10) + (data[i]-48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				endtime = (endtime * 10) + (data[i]-48);
			}
			i++;
			int j = 0;
			for (;data[i] != ',';i++)
			{
				userid[j] = data[i];
				j++;
			}
			userid[j] = '\0';
			j = 0;
			i++;
			for (;data[i] != ',';i++)
			{
				actid[j] = data[i];
				j++;
			}
			actid[j] = '\0';
			j = 0;
			i++;
			for (;data[i] != ',';i++)
			{
				title[j] = data[i];
				j++;
			}
			title[j] = '\0';
			i++;
			for (;data[i] != '\0';i++)
			{
				if (data[i] != '.')
				{
					a = (a / 10) + (data[i] - 48);
				}
			}
			userid1 = convertToString(userid);
			actid1 = convertToString(actid);
			title1 = convertToString(title);
			calender[month-1][d-1][starttime][0] = new activity(0.9, userid1, title1, starttime, endtime, month, d, actid1);
			d = 0;
			starttime = 0;
			month = 0;
			endtime = 0;
		}
		file.close();
	}
	menu();
	a = 0;
	while (a != 8)
	{
		cout << "ENTER YOUR CHOICE " << endl;
		cin >> a;
		if (a == 1)
		{
			int check = 0;
			string user_id1;
			cout << "Enter the userid of which you want to list activities" << endl;
			cin >> user_id1;
			for (int i = 0;i < 12;i++)
			{
				for (int j = 0;j < days[i];j++)
				{
					for (int k = 0;k < 24;k++)
					{
						for (int l = 0;l < 5;l++)
						{
							if (calender[i][j][k][l] != nullptr && calender[i][j][k][l]->userid ==user_id1)
							{
								calender[i][j][k][l]->print(); 
								check = 1;
							}
							
						}


					}

				}
				
			}
			if (check == 0)
			{
				cout << "User Not Found" << endl;
			}
		}
		if (a == 2)
		{
			int startdate = 0;
			int enddate = 0;
			int month = 0;
			cout << "Enter the startdate" << endl;
			cin >> startdate;
			cout << "Enter the enddate" << endl;
			cin >> enddate;
			cout << "Enter the month " << endl;
			cin >> month;
			for (int j = startdate;j <= enddate;j++)
			{
				for (int k = 0;k < 24;k++)
				{
					if (calender[month][j][k][0] != nullptr)
					{
						
					}
				}

			}
		}
		if (a == 3)
		{
			int month = 0;
			string user_id;
			cout << "Enter the userid" << endl;
			cin >> user_id;
			int count = 0,count2=0;
			cout << "Enter the month " << endl;
			cin >> month;
			cout << monthnames[month-1] << endl;
			for (int j = 0;j < days[month-1];j++)
			{
				for (int k = 0;k < 24;k++)
				{
					if (calender[month-1][j][k][0] == nullptr || calender[month-1][j][k][0]->userid!=user_id)
					{
						count++;
					}
				}
				if (count2 == 4)
				{
					cout << endl;
					count2 = 0;
				}
				if (count == 24)
				{
					count2++;
					cout << j+1<<" ";
				}
				count = 0;

			}
		}
		if (a == 4)
		{
			obj = new activity();
			cout << "Enter the userid" << endl;
			cin >> (*obj).userid;
			cout << "Enter the title of the activity" << endl;
			cin >> (*obj).title;
			cout << "Enter the starting time of the activity" << endl;
			cin >> (*obj).startingtime;
			cout << "Enter the ending time of the activity" << endl;
			cin >> (*obj).endingtime;
			(*obj).duration = (*obj).endingtime - (*obj).startingtime;
			cout << "Enter the month" << endl;
			cin >> (*obj).monthnumber;
			cout << "Enter the date" << endl;
			cin >> (*obj).date;
			cout << "Enter the actid" << endl;
			cin >> (*obj).actid;
			calender[(*obj).monthnumber-1][(*obj).date-1][(*obj).startingtime][0] = new activity(0.9,(*obj).userid,(*obj).title,(*obj).startingtime,(*obj).endingtime,(*obj).monthnumber,(*obj).date,(*obj).actid);
			file.open("calendardat.txt", ios::app);
			if (file)
			{
				file <<endl<< (*obj).date << "/"<< (*obj).monthnumber<<","<< (*obj).startingtime<<","<< (*obj).endingtime<<","<< (*obj).userid<<","<< (*obj).actid<<","<< (*obj).title<<","<<"0.9";
			}
			file.close();
		}
		if (a == 5)
		{
			calenderprint();
		}
		if (a == 6)
		{
			int startdate = 0;
			int enddate = 0;
			int month = 0;
			string user_id2;
			cout << "Enter the userid" << endl;
			cin >> user_id2;
			cout << "Enter the startdate" << endl;
			cin >> startdate;
			cout << "Enter the enddate" << endl;
			cin >> enddate;
			cout << "Enter the month " << endl;
			cin >> month;
			for (int j = startdate;j<=enddate;j++)
			{
					for (int k = 0;k < 24;k++)
					{
						if (calender[month][j][k][0] == nullptr || calender[month][j][k][0]->userid!=user_id2)
						{
							cout << j << "/" << month << "/" << " hourly slots" << " " << k << endl;
						}
					}

			}
		}
		if (a == 7)
		{
			string userid_3;
			cout << "Enter the userid you want to delete" << endl;
			cin >> userid_3;
			for (int i = 0;i < 12;i++)
			{
				for (int j = 0;j < days[i];j++)
				{
					for (int k = 0;k < 24;k++)
					{
						if (calender[i][j][k][0] !=nullptr && calender[i][j][k][0]->userid == userid_3)
						{
								calender[i][j][k][0] = nullptr;
								cout << "User deleated" << endl;
						}

					}

				}

			}
			file.open("calendardat.txt", ios::out);
			if (file)
			{
				for (int i = 0;i < 12;i++)
				{
					for (int j = 0;j < days[i];j++)
					{
						for (int k = 0;k < 24;k++)
						{
							for (int l = 0;l < 5;l++)
							{
								if (calender[i][j][k][l]!=nullptr)
								{
									file << calender[i][j][k][l]->date << "/" << calender[i][j][k][l]->monthnumber << "," << calender[i][j][k][l]->startingtime << "," << calender[i][j][k][l]->endingtime << "," << calender[i][j][k][l]->userid << "," << calender[i][j][k][l]->actid << "," << calender[i][j][k][l]->title << "," << calender[i][j][k][l]->priority<<endl;
								}

							}


						}

					}

				}
			}
			file.close();			
		}
		if (a == 9)
		{
			double yearcount = 0,average;
			double busiestmonth[12];
			for (int i = 0;i < 12;i++)
			{
				for (int j = 0;j < days[i];j++)
				{
					for (int k = 0;k < 24;k++)
					{
						if (calender[i][j][k][0] != nullptr)
						{
							yearcount++;

						}


					}

				}
				busiestmonth[i] = yearcount;
				yearcount = 0;

			}
			double sum = 0;
			for (int i = 0;i < 12;i++)
			{
				sum = sum + busiestmonth[i];
			}
			int size,idx6;
			size = busiestmonth[0];
			for (int i = 1;i < 12;i++)
			{
				if (busiestmonth[i] >= size)
				{
					size = busiestmonth[i];
					idx6 = i;
				}
			}
			average = sum / 12;
			cout << "The average activities per year is" << average << endl;
			cout << "The busiest month is " << monthnames[idx6] << endl;
			int monthcount = 0;
			for (int i = 0;i < days[idx6];i++)
			{
				for (int j = 0;j < 24;j++)
				{
					if (calender[idx6][i][j][0] != nullptr)
					{
						monthcount++;
					}
				}
			}
			cout << "The number of activities in the busiest month is " << monthcount << endl;
		}
		if (a == 10)
		{
			double month1,activity1=0,avearage1;
			cout << "Enter the month number you want to find the stats" << endl;
			cin >> month1;
			month1 = month1 - 1;
			int c = month1;
			for (int i = 0;i < days[c];i++)
			{
				for (int j = 0;j < 24;j++)
				{
					if (calender[c][i][j][0] != nullptr)
					{
						activity1++;
					}
				}
			}
			avearage1 = activity1 / days[c];
			cout << "The average activities per day is " << avearage1 << endl;
			cout << "The total number of activities in this month is equel to " << activity1 << endl;

		}
		menu();
		cout << "Do you want to procede" << endl;
		cin >> a;
	}
}
