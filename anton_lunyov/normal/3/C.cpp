#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <algorithm>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

const long n=3;
char a[n][n+1];

bool valid()
{
	long i,j;
	for(i=0;i<n;i++)
	{
		if(a[i][0]!='.')
		{
			for(j=0;j<n && a[i][j]==a[i][0];j++);
			if(j==n) return false;
		}
		if(a[0][i]!='.')
		{
			for(j=0;j<n && a[j][i]==a[0][i];j++);
			if(j==n) return false;
		}
	}
	if(a[1][1]!='.')
	{
		for(j=0;j<n && a[j][j]==a[1][1];j++);
		if(j==n) return false;
		for(j=0;j<n && a[j][2-j]==a[1][1];j++);
		if(j==n) return false;
	}
	return true;
}

#define illegal 0
#define first 1
#define second 2
#define draw 3
#define first_win 4
#define second_win 5

int main()
{
	//ifstream cin("in.txt");
	while(cin >> a[0])
	{
		cin >> a[1] >> a[2];
		long i,j;
		long o=0,x=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) 
			{
				if(a[i][j]=='0') o++;
				if(a[i][j]=='X') x++;
			}
		int status=illegal;
		if(o<=x && x<=o+1)
		{
			if(o==x)
			{
				if(valid()) status=first; else
				{
					for(i=0;i<n;i++)
						for(j=0;j<n;j++)
							if(a[i][j]=='0')
							{
								a[i][j]='.';
								if(valid()) status=second_win;
								a[i][j]='0';
							}
				}
			}
			else
			{
				if(valid())
				{
					if(o+x==n*n) status=draw; else status=second;
				}
				else
				{
					for(i=0;i<n;i++)
						for(j=0;j<n;j++)
							if(a[i][j]=='X')
							{
								a[i][j]='.';
								if(valid()) status=first_win;
								a[i][j]='X';
							}
				}
			}
		}
		switch(status)
		{
			case illegal:puts("illegal");break;
			case first:puts("first");break;
			case second:puts("second");break;
			case draw:puts("draw");break;
			case first_win:puts("the first player won");break;
			case second_win:puts("the second player won");break;
		}
	}
	return 0;
}