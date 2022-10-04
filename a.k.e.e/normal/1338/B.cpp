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
const int MAXN=100005;

int n,rt;
vector<int> G[MAXN];
int dep[MAXN],f[MAXN];
void dfs1(int u,int pa)
{
	for(auto v:G[u])
	{
		if(v==pa)continue;
		dep[v]=dep[u]+1;
		dfs1(v,u);
	}
}
void dfs2(int u,int pa)
{
	bool hl=0;
	for(auto v:G[u])
	{
		if(v==pa)continue;
		if(G[v].size()>1)
		{
			dfs2(v,u);
			f[u]+=f[v]+1;
		}
		else hl=1;
	}
	f[u]+=hl;
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
	for(int i=1;i<=n;++i)if(G[i].size()==1){rt=i;break;}
	dfs1(rt,-1);
	int res_min=1;
	for(int i=1;i<=n;++i)
		if(G[i].size()==1 && (dep[i]&1)){res_min=3;break;}
	printf("%d ",res_min);
	for(int i=1;i<=n;++i)if(G[i].size()>1){rt=i;break;}
	dfs2(rt,-1);
	printf("%d\n",f[rt]);
	return 0;
}