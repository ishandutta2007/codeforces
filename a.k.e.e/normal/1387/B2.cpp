#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
/*const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=100005;

int n;
vector<int> G[MAXN];
int size[MAXN],w[MAXN];
ll ans;
vector<int> b[MAXN];
priority_queue<pii,vector<pii>,less<pii> > pq;
int prm[MAXN],res[MAXN];
void dfs1(int u,int pa)
{
	size[u]=1;
	for(auto v:G[u])
	{
		if(v==pa)continue;
		dfs1(v,u);
		size[u]+=size[v];
		chkmax(w[u],size[v]);
		ans+=2*min(size[v],n-size[v]);
	}
	chkmax(w[u],n-size[u]);
}
void dfs2(int u,int pa,int r)
{
	b[r].pb(u);
	for(auto v:G[u])
	{
		if(v==pa)continue;
		dfs2(v,u,r);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u,v,rt=1,las=0;
	pii p,q;
	readint(n);
	for(int i=1;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	dfs1(1,-1);
	for(int i=2;i<=n;++i)if(w[i]<w[rt])rt=i;
	u=rt;for(auto v:G[rt])chkmax(u,v);
	b[rt].pb(rt);
	if(u==rt)las=rt,prm[1]=b[rt].back(),b[rt].pop_back();
	pq.push(mp(b[rt].size(),rt));
	for(auto v:G[rt])
	{
		dfs2(v,rt,v);
		if(u==v)las=v,prm[1]=b[v].back(),b[v].pop_back();
		pq.push(mp(b[v].size(),v));
	}
	for(int i=2;i<=n;++i)
	{
		q=mp(0,0),p=pq.top(),pq.pop();
		if(p.y==las)q=p,p=pq.top(),pq.pop();
		las=p.y,prm[i]=b[p.y].back(),b[p.y].pop_back();
		if(q.x)pq.push(q);
		if(p.x)pq.push(mp(p.x-1,p.y));
	}
	printf("%lld\n",ans);
	for(int i=1;i<n;++i)res[prm[i]]=prm[i+1];
	res[prm[n]]=prm[1];
	for(int i=1;i<=n;++i)printf("%d ",res[i]);
	return 0;
}