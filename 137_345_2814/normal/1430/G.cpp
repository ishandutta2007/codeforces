#include<cstdio>
using namespace std;
#define N 19
#define M 270010
int n,m,a,b,c,v[N][N],dp[M],fr[M],is2[M],is[M],f[M],as[N];
bool check1(int s)
{
	for(int i=1;i<=n;i++)if(s&(1<<i-1))
	for(int j=1;j<=n;j++)if(s&(1<<j-1))
	if(v[i][j])return 0;
	return 1;
}
bool check2(int s)
{
	for(int i=1;i<=n;i++)if(s&(1<<i-1))
	for(int j=1;j<=n;j++)if(~s&(1<<j-1))
	if(v[i][j])return 0;
	return 1;
}
int calcf(int s)
{
	int as=0;
	for(int i=1;i<=n;i++)if(~s&(1<<i-1))
	for(int j=1;j<=n;j++)if(s&(1<<j-1))
	as+=v[i][j];
	return as;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a,&b,&c),v[a][b]=c;
	for(int i=0;i<1<<n;i++)is[i]=check1(i),is2[i]=check2(i),f[i]=calcf(i);
	for(int i=1;i<1<<n;i++)dp[i]=1e9+1;
	for(int i=0;i<1<<n;i++)if(is2[i])
	{
		dp[i]+=f[i];
		int tp=((1<<n)-1)^i;
		for(int j=tp;j;j=(j-1)&tp)
		if(is[j]&&is2[i+j]&&dp[i+j]>dp[i])dp[i+j]=dp[i],fr[i+j]=i;
	}
	int tp=(1<<n)-1,st=n;
	while(tp)
	{
		int rt=fr[tp];
		for(int i=1;i<=n;i++)if((tp&(1<<i-1))&&!(rt&(1<<i-1)))as[i]=st;
		st--,tp=rt;
	}
	for(int i=1;i<=n;i++)printf("%d ",as[i]);
}