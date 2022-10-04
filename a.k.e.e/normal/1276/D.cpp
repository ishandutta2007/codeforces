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
const int MAXN=200005,MOD=998244353;

int n;
vector<pii> G[MAXN];
ll f[MAXN][4],pre[MAXN],suf[MAXN];
void dfs(int u,pii pa)
{
//cerr<<"Visit "<<u<<endl;
	for(auto p:G[u])
	{
		int v=p.x,c=p.y;
		if(!v || v==pa.x)continue;
		dfs(v,mp(u,c));
	}
	int k=0;
	vector<int> v;v.pb(0);
	int pos=-1;
	for(int i=1;i<G[u].size();++i)
	{
		if(G[u][i].x==pa.x)continue;
		++k;
		v.pb(G[u][i].x);
		if(G[u][i].y>pa.y && pos==-1)pos=k-1;
	}
	if(pos<0)pos=k;
	pre[0]=suf[k+1]=1;
	for(int i=1;i<=k;++i)
		pre[i]=pre[i-1]*(f[v[i]][1]+f[v[i]][3])%MOD;
	for(int i=k;i;--i)
		suf[i]=suf[i+1]*(f[v[i]][0]+f[v[i]][1]+f[v[i]][2])%MOD;
	f[u][0]=pre[k];
	for(int i=1;i<=k;++i)
	{
		if(i<=pos)f[u][1]=(f[u][1]+pre[i-1]*(f[v[i]][0]+f[v[i]][2])%MOD*suf[i+1])%MOD;
		else f[u][2]=(f[u][2]+pre[i-1]*(f[v[i]][0]+f[v[i]][2])%MOD*suf[i+1])%MOD;
	}
	f[u][3]=pre[pos]*suf[pos+1]%MOD;
//cerr<<u<<":"<<k<<","<<pos<<endl;
//for(int i=1;i<=k;++i)cerr<<v[i]<<" ";cerr<<endl;
//cerr<<f[u][0]<<" "<<f[u][1]<<" "<<f[u][2]<<" "<<f[u][3]<<endl<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n);
	for(int i=1;i<=n;++i)G[i].pb(mp(0,0));
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v);
		G[u].pb(mp(v,i)),G[v].pb(mp(u,i));
	}
	dfs(1,mp(-1,n+1));
	cout<<(f[1][0]+f[1][1]+f[1][2])%MOD<<endl;
	return 0;
}