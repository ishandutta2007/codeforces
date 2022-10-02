#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int a[1005][1005],b[1005][1005];
int nx=1,ny=0,ans;
int n,m,q;
inline void add(int x,int y)
{
	ans-=a[x][y]^b[x][y];
	a[x][y]^=1;
	ans+=a[x][y]^b[x][y];
	if(ny==n) ++nx,ny=0;
	++ny;
	ans-=a[ny][nx]^b[ny][nx];
	b[ny][nx]=1;
	ans+=a[ny][nx]^b[ny][nx];
}
inline void del(int x,int y)
{
	ans-=a[x][y]^b[x][y];
	a[x][y]^=1;
	ans+=a[x][y]^b[x][y];
	ans-=a[ny][nx]^b[ny][nx];
	b[ny][nx]=0;
	ans+=a[ny][nx]^b[ny][nx];
	if(ny==1) --nx,ny=n+1;
	--ny;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin >> c;
			if(c=='*') add(i,j); 
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		if(a[x][y]) del(x,y);
		else add(x,y);
		cout << ans/2 << "\n";
	/*	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout << a[i][j];
			cout << "\n";
		}
		cout << "\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout << b[i][j];
			cout << "\n";
		}
		cout << "\n\n\n";*/
	}
	return 0;
}