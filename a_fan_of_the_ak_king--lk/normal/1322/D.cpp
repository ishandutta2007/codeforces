#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,P=998244353;
const int N=500005,E=262144;
#define inf 2147483647
int n,i,j,l[N],t[N],c[N],p[N],m;
int dp[2005][40005];
int dfs(int i,int a,int b)
{
	if(i>n&&b==0)
		return 0;
	if(a>n+m)
		return 0;
	if(dp[i][p[a-1]+b]!=dp[0][0])
		return dp[i][p[a-1]+b];
	int s=dfs(i,a+1,b/2)+b/2*c[a+1];
	if(i<=n)
	{
		s=max(s,dfs(i+1,a,b));
		if(l[i]==a)
			s=max(s,dfs(i+1,a,b+1)+c[l[i]]-t[i]);
	}
	return dp[i][p[a-1]+b]=s;
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
		scanf("%d",&l[i]);
		++p[l[i]];
	}
	for(i=1;i<=n;++i)
		scanf("%d",&t[i]);
	reverse(l+1,l+1+n);
	reverse(t+1,t+1+n);
	for(i=1;i<=n+m;++i)
		scanf("%d",&c[i]);
	memset(dp,0x7f,sizeof(dp));
	for(i=n+m;i>=1;--i)
	{
		int s=2;
		double as=p[i];
		for(j=i-1;j>=1&&j>=i-20;--j)
		{
			as+=1.0*p[j]/s;
			s*=2;
		}
		p[i]=(int)(as+1.5);
	}
	for(i=1;i<=n+m;++i)
		p[i]+=p[i-1];
	cout<<dfs(1,1,0);
}