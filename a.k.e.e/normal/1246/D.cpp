#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define k first
#define b second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(register int i=(x);i<=(y);++i)
#define try(i,x,y) for(register int i=(x);i>=(y);--i)
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

int n,dep[MAXN],size[MAXN],fa[MAXN];
vector<int> G[MAXN];
inline bool cmp_dep(int u,int v){return dep[u]<dep[v];}
void dfs1(int u)
{
	size[u]=1;
	for(auto v:G[u])
	{
		dfs1(v);
		chkmax(dep[u],dep[v]+1);
		size[u]+=size[v];
	}
}
int res[MAXN];
vector<int> ops;
void dfs2(int u,int l,int r)
{
	res[l]=u;++l;
	for(auto v:G[u])
	{
		dfs2(v,l,l+size[v]-1);
		l+=size[v];
	}
}
void dfs3(int u)
{
	for(auto v:G[u])
	{
		dfs3(v);
		while(fa[v]!=u)fa[v]=fa[fa[v]],ops.pb(v);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	int x;
	readint(n);
	enum(i,1,n-1)
	{
		readint(x);
		G[x].pb(i);
	}
	dfs1(0);
	enum(i,0,n-1)
		sort(G[i].begin(),G[i].end(),cmp_dep);
	dfs2(0,0,n-1);
	enum(i,0,n-1)printf("%d ",res[i]);putchar('\n');
	enum(i,1,n-1)fa[res[i]]=res[i-1];
	dfs3(0);
	printf("%d\n",(int)ops.size());
	for(auto i:ops)printf("%d ",i);
    return 0;
}