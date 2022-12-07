#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include <assert.h>
using namespace std;
typedef long long LL;
int T;
string ss;
bool Done ()
{
	return ss[0]=='D'&&ss[3]=='e';
}
int cnt;
bool Up ()
{
	return ss[0]=='U';
}
bool Down ()
{
	return ss[0]=='D'&&ss[2]=='w';
}
void solve (int TT)
{
	cout<<"1 2"<<endl;cin>>ss;	if (Done()) return ; 
	cnt=0;
	bool op=1;
	for (int u=1;u<=8;u++)
	{
		if (cnt>=10) 
		{
			cout<<"FUCK!";
			return ;
		}
		if (op)
		{
			for (int i=1;i<=8;i++)
			{
				cout<<u<<" "<<i<<endl;
				cin>>ss;
				if (Done()) return ; 
				if (Up()) 
				{
					u--;cnt++;
					if (i==1) op^=1;
					break;
				}
				if (Down()) 
				{
					if (u==8) {printf("GG\n");return ;}
					cout<<u+1<<" "<<i<<endl;
					cin>>ss;if (Done()) return ; 
					while (Down()) 
					{
						if (u==8) {printf("GG\n");return ;}
						u++;
						cout<<u+1<<" "<<i<<endl;
						cin>>ss;if (Done()) return ; 
					}
					if (i==1) op^=1;
					break;
				}
				if (i==8) op^=1;
			}
		}
		else 
		{
			for (int i=8;i>=1;i--)
			{
				cout<<u<<" "<<i<<endl;
				cin>>ss;
				if (Done()) return ; 
				if (Up()) 
				{
					u--;
					cnt++;
					if (i==8) op^=1;
					break;
				}
				if (Down()) 
				{
					if (u==8) {printf("GG\n");return ;}
					cout<<u+1<<" "<<i<<endl;
					cin>>ss;if (Done()) return ; 
					while (Down()) 
					{
						if (u==8) {printf("GG\n");return ;}
						u++;
						cout<<u+1<<" "<<i<<endl;
						cin>>ss;if (Done()) return ; 
					}
					if (i==8) op^=1;
					break;
				}
				if (i==1) op^=1;
			}
		}
	}
	printf("now:%d\n",TT);
}
int main()
{
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)	solve(TT);
	return 0;
}