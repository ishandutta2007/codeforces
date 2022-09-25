#include<cstdio>
using namespace std;
#define N 1070000
int n,cnt,head[N],a,b,fa[N],v[N],head2[N],s[33][33],m;
long long ans=0,dp[N][21];
struct edge{int t,next;}ed[500001],ed2[501];
void adde(int f,int t){ed[++cnt]=(edge){t,head[f]};head[f]=cnt;ed[++cnt]=(edge){f,head[t]};head[t]=cnt;}
int bitc(int k){int ans=0;while(k)ans+=k&1,k>>=1;return ans;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d",&a,&b),adde(a,b),s[a][b]=s[b][a]=1;
	for(int i=1;i<=n;i++)
	dp[1<<(i-1)][i]=1;
	for(int i=1;i<1<<n;i++)
	for(int j=1;j<=n;j++)
	if(dp[i][j])
	{
		int lbit=0;
		for(int k=1;k<=n;k++)
		if(i&(1<<(k-1))){lbit=k;break;}
		if(s[j][lbit]&&bitc(i)>2)
		ans+=dp[i][j];
		for(int k=lbit+1;k<=n;k++)
		if(!(i&(1<<(k-1)))&&s[k][j])dp[i|(1<<(k-1))][k]+=dp[i][j];
	}
	printf("%lld\n",ans/2);
}