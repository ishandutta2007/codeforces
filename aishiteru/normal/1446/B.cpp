#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,i,j,m,T,ans;
int dp[5005][5005];
char a[N],b[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	scanf("%s",a+1);
	scanf("%s",b+1);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			if(a[i]==b[j])
				dp[i][j]=dp[i-1][j-1]+2;
			else
				dp[i][j]=max(0,max(dp[i-1][j]-1,dp[i][j-1]-1));
			ans=max(ans,dp[i][j]);
		}
	cout<<ans;
}