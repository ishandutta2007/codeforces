#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=301;
const int inf=-(1e9+1);

int n;
int a[N][N];
int cache[2*N][N][N];

int dp(int idx, int i1, int i2)
{
	if(i1>n || i2>n)
		return -1e9;
	int j1=idx-i1;
	int j2=idx-i2;
	if(j1>n || j2>n)
		return -1e9;
	if(idx==2*n)
		return a[i1][j1];
	int &ans=cache[idx][i1][i2];
	if(ans!=inf)
		return ans;
	if(i1==i2)
		ans=a[i1][j1];
	else
		ans=a[i1][j1] + a[i2][j2];
	int best=-1e9;
	for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
			best=max(best, dp(idx+1, i1+i, i2+j));
	ans+=best;
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				cache[i][j][k]=inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	int ans=dp(2, 1, 1);
	cout<<ans;
	return 0;
}