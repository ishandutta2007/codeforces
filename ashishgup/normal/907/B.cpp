#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define mp make_pair

const int N=2e5+5;

char a[100][100];

int32_t main()
{
	int x, y;
 	for(int i=1;i<=9;i++)
 	{
 		for(int j=1;j<=9;j++)
 		{
 			cin>>a[i][j];
 		}
 	}
 	cin>>x>>y;
 	map<pair<int, int>, int> m;
 	for(int i=1;i<=9;i++)
 	{
 		if(i%3==1)
 		{
 			m[mp(i, 1)]=1;
	 		m[mp(i, 4)]=1;
	 		m[mp(i, 7)]=1;
	 		m[mp(i, 2)]=2;
	 		m[mp(i, 5)]=2;
	 		m[mp(i, 8)]=2;
	 		m[mp(i, 3)]=3;
	 		m[mp(i, 6)]=3;
	 		m[mp(i, 9)]=3;
 		}
 		else if(i%3==2)
 		{
			m[mp(i, 1)]=1;
	 		m[mp(i, 4)]=1;
	 		m[mp(i, 7)]=1;
	 		m[mp(i, 2)]=2;
	 		m[mp(i, 5)]=2;
	 		m[mp(i, 8)]=2;
	 		m[mp(i, 3)]=3;
	 		m[mp(i, 6)]=3;
	 		m[mp(i, 9)]=3;
	 		for(int j=1;j<=9;j++)
	 		{
	 			m[mp(i, j)]+=3;
	 		}
 		}
 		else
 		{
 			m[mp(i, 1)]=1;
	 		m[mp(i, 4)]=1;
	 		m[mp(i, 7)]=1;
	 		m[mp(i, 2)]=2;
	 		m[mp(i, 5)]=2;
	 		m[mp(i, 8)]=2;
	 		m[mp(i, 3)]=3;
	 		m[mp(i, 6)]=3;
	 		m[mp(i, 9)]=3;
	 		for(int j=1;j<=9;j++)
	 		{
	 			m[mp(i, j)]+=6;
	 		}
 		}
 	}
 	int curmat=m[mp(x,y)];
 	if(curmat<=3)
 	{
 		int ans=0;
 		for(int i=1;i<=3;i++)
 		{
 			for(int j=1+(curmat-1)*3;j<=3+(curmat-1)*3;j++)
 			{
 				if(a[i][j]=='.')
 				{
 					a[i][j]='!';
 					ans++;
 				}
 			}
 		}	
 		if(ans==0)
 		{
 			for(int i=1;i<=9;i++)
	 		{
	 			for(int j=1;j<=9;j++)
	 			{
	 				if(a[i][j]=='.')
	 					a[i][j]='!';
	 			}
	 		}	
 		}
 		for(int i=1;i<=9;i++)
 		{
 			for(int j=1;j<=9;j++)
 			{
 				cout<<a[i][j];
 				if(j%3==0)
 					cout<<" ";
 			}
 			cout<<endl;
 			if(i%3==0)
 				cout<<endl;
 		}
 	}
 	else if(curmat<=6)
 	{
 		int ans=0;
 		for(int i=4;i<=6;i++)
 		{
 			for(int j=1+(curmat-4)*3;j<=3+(curmat-4)*3;j++)
 			{
 				if(a[i][j]=='.')
 				{
 					a[i][j]='!';
 					ans++;
 				}
 			}
 		}	
 		if(ans==0)
 		{
 			for(int i=1;i<=9;i++)
	 		{
	 			for(int j=1;j<=9;j++)
	 			{
	 				if(a[i][j]=='.')
	 					a[i][j]='!';
	 			}
	 		}	
 		}
 		for(int i=1;i<=9;i++)
 		{
 			for(int j=1;j<=9;j++)
 			{
 				cout<<a[i][j];
 				if(j%3==0)
 					cout<<" ";
 			}
 			cout<<endl;
 			if(i%3==0)
 				cout<<endl;
 		}
 	}
 	else
 	{
 		int ans=0;
 		for(int i=7;i<=9;i++)
 		{
 			for(int j=1+(curmat-7)*3;j<=3+(curmat-7)*3;j++)
 			{
 				if(a[i][j]=='.')
 				{
 					a[i][j]='!';
 					ans++;
 				}
 			}
 		}	
 		if(ans==0)
 		{
 			for(int i=1;i<=9;i++)
	 		{
	 			for(int j=1;j<=9;j++)
	 			{
	 				if(a[i][j]=='.')
	 					a[i][j]='!';
	 			}
	 		}	
 		}
 		for(int i=1;i<=9;i++)
 		{
 			for(int j=1;j<=9;j++)
 			{
 				cout<<a[i][j];
 				if(j%3==0)
 					cout<<" ";
 			}
 			cout<<endl;
 			if(i%3==0)
 				cout<<endl;
 		}
 	}
}