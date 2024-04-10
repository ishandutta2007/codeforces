#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5205;

int n, ans=1;
bool a[N][N];
int pr[N][N], pc[N][N];

bool checkrow(int idx, int x)
{
	for(int i=1;i<=n;i+=x)
	{
		int sum=pr[idx][i+x-1]-pr[idx][i-1];
		if(sum!=a[idx][i]*x)
			return 0;
	}
	return 1;
} 

bool checkcol(int idx, int x)
{
	for(int i=1;i<=n;i+=x)
	{
		int sum=pc[i+x-1][idx]-pc[i-1][idx];
		if(sum!=a[i][idx]*x)
			return 0;
	}
	return 1;
} 
	
bool check(int x)
{
	for(int i=1;i<=n;i++)
		if(!checkrow(i, x))
			return 0;
	for(int i=1;i<=n;i++)
		if(!checkcol(i, x))
			return 0;
	return 1;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j+=4)
		{
			char ch;
			cin>>ch;
			int val;
			if(isdigit(ch))
				val=ch-'0';
			else
				val=ch-'A'+10;
			int cur=8;
			for(int k=j;k<=j+3;k++)
			{
				if(val>=cur)
				{
					val-=cur;
					a[i][k]=1;
				}
				cur/=2;
			}
		}	
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			pr[i][j]+=pr[i][j-1]+a[i][j];
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			pc[i][j]+=pc[i-1][j]+a[i][j];
	for(int i=n;i>=2;i--)
	{
		if(n%i==0)
		{
			if(check(i))
			{
				cout<<i;
				return 0;
			}
		}
	}
	cout<<1;
	return 0;
}