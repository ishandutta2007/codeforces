#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 54
#define ll long long
int n,k;
ll s[N][2],v[N],dp[N][N][N][2][2][2][2];
ll dfs(int l,int r,int a,int l1,int l2,int r1,int r2)
{
	if(a==k)return l==r+1?0:1e18;
	if(dp[l][r][a][l1][l2][r1][r2]!=-1)return dp[l][r][a][l1][l2][r1][r2];
	ll as=(l>1&&r<n&&(((s[l-1][l1]>>a)&1)^((s[r+1][r1]>>a)&1)^l2^r2))*v[a]+dfs(l,r,a+1,l1,0,r1,0);
	for(int i=l;i<=r;i++)
	for(int t=0;t<2;t++)
	{
		if(a==0)as=min(as,dfs(l,i-1,a,l1,l2,t,0)+dfs(i+1,r,a,t,0,r1,r2));
		if(s[i][0]<=((s[i][t]^(1ll<<a))&(~((1ll<<a)-1)))&&((s[i][t]^(1ll<<a))|((1ll<<a)-1))<=s[i][1])as=min(as,dfs(l,i-1,a,l1,l2,t,1)+dfs(i+1,r,a,t,1,r1,r2));
	}
	return dp[l][r][a][l1][l2][r1][r2]=as;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&s[i][0],&s[i][1]);
	for(int i=0;i<k;i++)scanf("%lld",&v[i]);
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",dfs(1,n,0,0,0,0,0));
}