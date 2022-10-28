#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2005;

int n, m, k;
char a[N][N];
int b[N][N], c[N][N];

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='.')
				b[i][j]=b[i][j-1]+1;
			else
				b[i][j]=0;
			ans+=(b[i][j]>=k);
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='.')
				c[i][j]=c[i-1][j]+1;
			else
				c[i][j]=0;
			ans+=(c[i][j]>=k);
		}
	}
	if(k==1)
		ans/=2;
	cout<<ans;
	return 0;
}