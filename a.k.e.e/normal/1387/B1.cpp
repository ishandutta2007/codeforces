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
vector<int> G[MAXN],b[MAXN];
ll f[MAXN],g[MAXN];//f select
int fa[MAXN],res[MAXN],to[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
void dfs1(int u,int pa)
{
	int t=1<<30;
	for(auto v:G[u])
	{
		if(v==pa)continue;
		dfs1(v,u);
		g[u]+=f[v];
		f[u]+=min(g[v]+1,f[v]);
		int s=min(g[v],f[v])+1-min(g[v]+1,f[v]);
		if(s<t)to[u]=v,t=s;
	}
	f[u]+=t;
//cerr<<u<<": "<<f[u]<<" "<<g[u]<<" "<<to[u]<<endl;
}
void dfs2(int u,int pa,int ty)
{
	for(auto v:G[u])
	{
		if(v==pa)continue;
		if(ty==0)dfs2(v,u,1);
		else
		{
			if(v==to[u] || g[v]+1<=f[v])fa[getfa(u)]=getfa(v);
			if(g[v]+1<=f[v] || (v==to[u] && g[v]<=f[v]))dfs2(v,u,0);
			else dfs2(v,u,1);
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n);
	for(int i=1;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	for(int i=1;i<=n;++i)fa[i]=i;
	dfs1(1,-1);
	dfs2(1,-1,1);
	for(int i=1;i<=n;++i)b[getfa(i)].pb(i);
	for(int i=1;i<=n;++i)
		if(getfa(i)==i)
		{
			for(int j=1;j<b[i].size();++j)
				res[b[i][j]]=b[i][j-1];
			res[b[i][0]]=b[i].back();
		}
	printf("%d\n",2*f[1]);
	for(int i=1;i<=n;++i)printf("%d ",res[i]);
	return 0;
}