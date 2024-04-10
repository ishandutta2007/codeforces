#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=1000005;
int n,m,i,j,t[3005];
int a[N];
long long s[N],g[3005][3005],dp[3005],ans;
void dfs(int l,int r)
{
	int i;
	if(l==r)
	{
		for(i=m;i>=0;--i)
			ans=max(ans,g[l][min(m-i,t[l])]+dp[i]);
		return;
	}
	int mid=l+r>>1;
	long long tmp[3005];
	memcpy(tmp,dp,sizeof(tmp));
	for(i=l;i<=mid;++i)
		for(j=m;j>=t[i];--j)
			dp[j]=max(dp[j],dp[j-t[i]]+g[i][t[i]]);
	dfs(mid+1,r);
	memcpy(dp,tmp,sizeof(dp));
	for(i=mid+1;i<=r;++i)
		for(j=m;j>=t[i];--j)
			dp[j]=max(dp[j],dp[j-t[i]]+g[i][t[i]]);
	dfs(l,mid);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&t[i]);
		for(j=1;j<=t[i];++j)
		{
			scanf("%d",&a[j]);
			s[j]=s[j-1]+a[j];
		}
		t[i]=min(t[i],3000);
		for(j=1;j<=t[i];++j)
			g[i][j]=s[j];
	}
	dfs(1,n);
	cout<<ans;
}