#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1005][1005],b[1005][1005],ans,n;
inline bool check(int x,int y)
{
	return !(b[x-1][y]|b[x+1][y]|b[x][y+1]|b[x][y-1]);
}
inline void op(int x,int y)
{
//	cout << x << " " << y << "\n";
	ans^=a[x][y]^a[n-x+1][y];
	b[x-1][y]^=1;
	b[x+1][y]^=1;
	b[x][y-1]^=1;
	b[x][y+1]^=1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=0;i<=n+3;i++)
		{
			for(int j=0;j<=n+3;j++)
				b[i][j]=0;
		}
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin >> a[i][j];
		for(int i=1;i<n;i++)
		{
			if(i%2==1&&check(1,i+1))
			{
				op(1,i+1);
			}
		}
		for(int i=1;i<n;i++)
		{
			if(i%2==0&&check(i+1,n))
			{
				op(i+1,n);
			}
		}
		for(int i=n-1;i>=1;i--)
		{
			if(i%2==0&&check(n,i+1))
			{
				op(n,i+1);
			}
		}
		for(int i=n-1;i>=1;i--)
		{
			if(i%2==1&&check(i+1,1))
			{
				op(i+1,1);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i+j&1)
				{
					if(check(i,j)) op(i,j);
				}
			}
		}
	/*	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout << b[i][j] << " ";
			cout << "\n";
		}*/
		cout << ans << "\n";
	}
	return 0;
}