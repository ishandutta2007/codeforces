#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=3005;

int n;
vector<int> G[MAXN];
int size[MAXN][MAXN],pa[MAXN][MAXN];
ll f[MAXN][MAXN];
void dfs(int u,int rt)
{
	size[rt][u]=1;
	for(auto v:G[u])
	{
		if(v==pa[rt][u])continue;
		pa[rt][v]=u;
		dfs(v,rt);
		size[rt][u]+=size[rt][v];
	}
}
ll dp(int u,int v)
{
	if(f[u][v]>0)return f[u][v];
	if(f[v][u]>0)return f[u][v]=f[v][u];
	ll ans=0;
	for(auto x:G[u])
		if(x!=pa[v][u])
			chkmax(ans,dp(x,v));
	for(auto y:G[v])
		if(y!=pa[u][v])
			chkmax(ans,dp(u,y));
	return f[u][v]=ans+size[u][v]*size[v][u];
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n);
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v);
		G[u].pb(v),G[v].pb(u); 
	}
	for(int i=1;i<=n;++i)dfs(i,i);
	ll ans=0;
	for(int i=1;i<=n;++i)
		for(auto v:G[i])
			chkmax(ans,dp(i,v));
	cout<<ans<<endl;
	return 0;
}