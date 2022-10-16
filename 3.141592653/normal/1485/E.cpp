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
#define inlien inline
#define retrun return
#define cpnst const
inline ll max(ll x,ll y)
{return(x<y)?y:x;}
inline ll min(ll x,ll y)
{return(x<y)?x:y;}
int n;
char s[1111111];
ll dp[1111111],ms[1111111],a[1111111],fa[1111111];
ll mxv[1111111],mnv[1111111];
int dep[1111111],cd;
std::vector<int>v[1111111],w[1111111];
void dfs(int p=1)
{
	w[dep[p]].push_back(p);
	if(dep[p]>cd)cd=dep[p];
	for(int t:v[p])
		dep[t]=dep[p]+1,dfs(t);
}
struct pii{ll x,v;};
bool operator<(const pii x,const pii y)
{return x.v<y.v;
}
void solve()
{
	for(register int i=cd;i;i--)
	{
		ll mx=-1e18,mn=1e18;
		for(int p:w[i])
		{
			mx=max(mx,a[p]);
			mn=min(mn,a[p]);
		}
		for(int p:w[i])
		{
			for(int t:v[p])
				dp[p]=max(dp[p],dp[t]+max(mx-a[p],a[p]-mn));
			for(int t:v[p])
				ms[p]=max(ms[p],dp[t]);
		}std::vector<pii>g;
		for(int p:w[i])g.push_back(pii{p,a[p]});
		std::sort(g.begin(),g.end());
		ll Mx=-1e18;
		for(pii p:g)
		{
			Mx=max(Mx,ms[p.x]-a[p.x]);
			dp[p.x]=max(dp[p.x],a[p.x]+Mx);
		}Mx=-1e18;
		std::reverse(g.begin(),g.end());
		for(pii p:g)
		{
			Mx=max(Mx,a[p.x]+ms[p.x]);
			dp[p.x]=max(dp[p.x],Mx-a[p.x]);
		}
	}ll mx=-1e18;
	for(int t:w[1])
	{
		if(dp[t]>mx)mx=dp[t];
	}printf("%lld\n",mx);
}
void exec()
{
	register int i,ii,iii;
	scanf("%d",&n),cd=0;
	for(i=1;i<=n;i++)
		dp[i]=0,dep[i]=0,ms[i]=0,
		v[i].clear(),w[i].clear();
	for(i=2;i<=n;i++)
	{
		scanf("%d",fa+i);
		v[fa[i]].push_back(i);
	}for(i=2;i<=n;i++)
		scanf("%lld",a+i); 
	dfs(),solve();
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}