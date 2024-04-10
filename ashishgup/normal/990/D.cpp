#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, a, b;
int g[N][N];

int32_t main()
{
    IOS;
 	cin>>n>>a>>b;
 	if(a>1 && b>1)
 	{
 		cout<<"NO";
 		return 0;
 	}
 	int sta=a, stb=b;
 	if(sta==1)
 		swap(sta, stb);
 	if(n==1)
 	{
		cout<<"YES"<<endl;
		cout<<"0";
		return 0;
 	}
 	if(n==2)
 	{
 		if(sta==1)
 		{
 			cout<<"NO";
 			return 0;
 		}
 		else
 		{
 			cout<<"YES"<<endl;
 			if(a==2)
 				cout<<"00\n00";
 			else
 				cout<<"01\n10";
 			return 0;
 		}
 	}
 	if(n==3)
 	{
 		if(sta==1)
 		{
 			cout<<"NO";
 			return 0;
 		}
 	}
 	for(int i=1;i<=n-sta;i++)
 	{
 		g[i][i+1]=1;
 		g[i+1][i]=1;
 	}
 	if(a!=sta)
 	{
 		for(int i=1;i<=n;i++)
 		{
 			for(int j=1;j<=n;j++)
 			{
 				g[i][j]^=1;
 			}
 		}
 	}
 	cout<<"YES"<<endl;
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			if(i==j)
 				g[i][j]=0;
 			cout<<g[i][j];
 		}
 		cout<<endl;
 	}
    return 0;
}