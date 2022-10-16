#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
#include<vector>
using std::vector;
#include<cstdlib>
#include<queue>
using std::queue;
using std::priority_queue;
#include<cmath>
typedef long long ll;
typedef double db;
inline ll max(ll x,ll y)
{return(x<y)?y:x;}
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
char s[1111111];
ll a[1111111];
const int mod=998244353;
ll dp[1111111];
int n,m;
char str[1111111];
int len[1111111];
int qpow(int x,int k){int r=1;for(;k;k>>=1,x=x*1ll*x%mod)if(k&1)r=r*1ll*x%mod;return r;}
void exec()
{
	register int i,ii,iii;
	scanf("%d%d",&n,&m);
	const int iv2=qpow(2,mod-2);
	for(i=2;i<=300000;i++)
	{
		dp[i]=(dp[i-2]+dp[i-1]+1)*iv2%mod;
	}
	long long ans=0,cnt=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		int le=0;
		for(ii=1;ii<=m;ii++)
		{
			if(str[ii]=='*')
			{
				ans+=dp[len[ii]]+dp[le];
				len[ii]=0,le=0;
			}
			else
			{
				cnt++,le++,len[ii]++;
			}
		}ans+=dp[le];
	}for(i=1;i<=m;i++)ans+=dp[len[i]];
	if(!cnt){puts("0");return;}
	printf("%lld\n",ans%mod*qpow(2,cnt-1)%mod);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}