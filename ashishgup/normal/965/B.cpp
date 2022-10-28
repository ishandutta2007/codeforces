#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k, max1=0;
char a[N][N];
int b[N][N];

void placehori(int i, int j)
{
	if(j+k-1>n)
		return;
	int check=0;
	for(int p=j;p<=j+k-1;p++)
	{
		if(a[i][p]=='#')
			check=1;
	}
	if(check)
		return;
	for(int p=j;p<=j+k-1;p++)
	{
		b[i][p]++;
		max1=max(max1, b[i][p]);
	}
}

void placeverti(int i, int j)
{
	if(i+k-1>n)
		return;
	int check=0;
	for(int p=i;p<=i+k-1;p++)
	{
		if(a[p][j]=='#')
			check=1;
	}
	if(check)
		return;
	for(int p=i;p<=i+k-1;p++)
	{
		b[p][j]++;
		max1=max(max1, b[p][j]);
	}
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			placehori(i, j);
			placeverti(i, j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==max1)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}