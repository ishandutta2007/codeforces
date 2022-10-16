#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,g[1005],dp[1005][2];
char k[1005][1005];
int main()
{
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>k[i][j];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)
			g[i]+=(k[j][i]=='.');
		g[i]+=g[i-1];
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=m;i++){
		for(int j=max(0,i-y);j<=i-x;j++)
			dp[i][0]=min(dp[i][0],dp[j][1]+g[i]-g[j]),
			dp[i][1]=min(dp[i][1],dp[j][0]+(i-j)*n-g[i]+g[j]);
	}
	cout<<min(dp[m][0],dp[m][1]);
	return 0;
}