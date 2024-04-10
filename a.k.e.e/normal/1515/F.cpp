#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=300005;
typedef pair<ll,int> pli;
int n;
ll x,a[MAXN];
vector<pii> G[MAXN];
int fa[MAXN];
ll sum[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
priority_queue<pli,vector<pli>,less<pli> > pq;
bool vis[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E;
	readint(n),readint(E),readint(x);
	ll s=0;
	for(int i=1;i<=n;++i)readint(a[i]),a[i]-=x,s+=a[i];
	if(s<-x)return 0*printf("NO\n");
	printf("YES\n");
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=E;++i)
	{
		int u,v;
		readint(u),readint(v);
		if(getfa(u)==getfa(v))continue;
		G[u].pb(mp(v,i)),G[v].pb(mp(u,i));
		fa[getfa(u)]=getfa(v);
	}
	for(int i=1;i<=n;++i)fa[i]=i,sum[i]=a[i],pq.push(mp(sum[i],i));
	for(int t=1;t<n;++t)
	{
		int u;
		while(1)
		{
			pli pr=pq.top();
			pq.pop();
			if(pr.x==sum[pr.y] && !vis[pr.y])
				{u=pr.y;break;}
		}
		while(getfa(G[u].back().x)==u)G[u].pop_back();
		int v=G[u].back().x,i=G[u].back().y;
		v=getfa(v);
		if(G[u].size()<G[v].size())swap(u,v);
		for(auto p:G[v])
			if(getfa(p.x)!=v)
				G[u].pb(p);
		fa[v]=u;sum[u]+=sum[v];
		pq.push(mp(sum[u],u));
		vis[v]=1;
		printf("%d\n",i);
	}
	return 0;
}