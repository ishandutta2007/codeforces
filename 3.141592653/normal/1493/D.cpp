#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
#include<vector>
using std::vector;
#include<cstdlib>
#include<queue>
#include<map>
using std::queue;
using std::priority_queue;
#include<cmath>
typedef long long ll;
typedef double db;
#define inlien inline
#define retrun return
#define cpnst const
inline ll max(ll x,ll y)
{return(x<y)?y:x;}
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
int n,q;
char s[1111111];
ll a[1111111];
const ll mod=1e9+7;
std::vector<int>d[1111111];
ll ans[1111111],k[1111111],b[1111111];
int cnt[3333333];
std::map<int,int>c[1111111];
bool isp[1111111];
int qpow(int x,int k)
{
	int r=1;for(;k;k>>=1,x=x*1ll*x%mod)
	if(k&1)r=r*1ll*x%mod;
	return r;
} 
void exec()
{
	scanf("%d%d",&n,&q);
	register int i,ii,iii;
	for(i=2;i<=2e5;i++)
		if(!d[i].size())
		{
			isp[i]=1;
			for(ii=i;ii<=2e5;ii+=i)
				d[ii].push_back(i);
		}
	for(i=1;i<=n;i++)scanf("%lld",a+i);
	for(i=1;i<=n;i++)
	{
		int w=a[i];
		for(int t:d[a[i]])
		{
			while(w%t==0)
			{
				w/=t,c[i][t]++;
			}
		}
	}
	for(i=1;i<=q;i++)
	{
		scanf("%lld%lld",k+i,b+i);
		int w=b[i];
		for(int t:d[b[i]])
		{
			while(w%t==0)
			{
				w/=t,c[k[i]][t]++;
			}
		}
	}int g=1;
	for(i=2;i<=2e5;i++)if(isp[i])
	{
		int t=1e9;
		for(ii=1;ii<=n;ii++)
		{
			int w=c[ii][i];
			if(!w){t=0;break;}
			if(w<t)t=w;
		}cnt[i]=t,g=g*1ll*qpow(i,t)%mod;
	}
	for(i=q;i;i--)
	{
		ans[i]=g;
		int w=b[i],iv=1;
		for(int t:d[b[i]])
		{
			while(w%t==0)
			{
				w/=t;
				c[k[i]][t]--;
				int r=c[k[i]][t];
				if(r<cnt[t])cnt[t]--,iv=iv*1ll*t%mod;
			}
		}g=g*1ll*qpow(iv,mod-2)%mod;
	}for(i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}