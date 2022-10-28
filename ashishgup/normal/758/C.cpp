#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, m, k, x, y;
int a[N][N];

void work()
{
	if(n==1)
	{
		int tot=k/m, rem=k%m;
		for(int i=1;i<=m;i++)
			a[1][i]+=tot;
		for(int i=1;i<=rem;i++)
			a[1][i]++;
	}
	else
	{
		int period=n*m + (n-2)*m;
		int tot=k/period;
		k%=period;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==1 || i==n)
					a[i][j]+=tot;
				else
					a[i][j]+=2*tot;
			}
		}
		for(int i=1;i<=n&&k>0;i++)
		{
			for(int j=1;j<=m&&k>0;j++)
			{
				a[i][j]++;
				k--;
			}
		}
		for(int i=n-1;i>=1&&k>0;i--)
		{
			for(int j=1;j<=m&&k>0;j++)
			{
				a[i][j]++;
				k--;
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k>>x>>y;
	work();
	int mx=0, mn=1e18;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mx=max(mx, a[i][j]);
			mn=min(mn, a[i][j]);
		}
	}
	cout<<mx<<" "<<mn<<" "<<a[x][y];
	return 0;
}