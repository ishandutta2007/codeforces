#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,int> pii;
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
const int MAXN=250005;
 
int n;
vector<int> G[MAXN];
int size[MAXN],dfn[MAXN],dfn_cnt,q[MAXN],pa[MAXN];
void dfs(int u)
{
	q[dfn[u]=++dfn_cnt]=u;
	size[u]=1;
	for(auto v:G[u])
	{
		if(v==pa[u])continue;
		pa[v]=u;
		dfs(v);
		size[u]+=size[v];
	}
}
 
namespace LCT
{
	int ch[MAXN][2],fa[MAXN],rev[MAXN],Min[MAXN],Max[MAXN];
	bool nroot(int x){return ch[fa[x]][0]==x || ch[fa[x]][1]==x;}
	bool sonr(int x){return ch[fa[x]][1]==x;}
	void reverse(int x){rev[x]^=1;swap(ch[x][0],ch[x][1]);}
	void pushdown(int x){if(rev[x])reverse(ch[x][0]),reverse(ch[x][1]),rev[x]=0;}
	void update(int x)
	{
		Min[x]=min(min(Min[ch[x][0]],Min[ch[x][1]]),dfn[x]);
		Max[x]=max(max(Max[ch[x][0]],Max[ch[x][1]]),dfn[x]);
	}
	void pushall(int x){if(nroot(x))pushall(fa[x]);pushdown(x);}
	void rotate(int x)
	{
		int y=fa[x],z=fa[y],ty=sonr(x),s=ch[x][ty^1];
		if(nroot(y))ch[z][sonr(y)]=x;
		ch[x][ty^1]=y,ch[y][ty]=s;
		fa[x]=z,fa[y]=x;
		if(s)fa[s]=y;
		update(y),update(x);
	}
	void splay(int x)
	{
		pushall(x);
		while(nroot(x))
			if(!nroot(fa[x]))rotate(x);
			else if(sonr(x)==sonr(fa[x]))rotate(fa[x]),rotate(x);
			else rotate(x),rotate(x);
	}
	void access(int x){for(int y=0;x;x=fa[y=x])splay(x),ch[x][1]=y,update(x);}
	void makeroot(int x){access(x),splay(x),reverse(x);}
	void link(int x,int y)
	{
		makeroot(x);makeroot(y);
		if(fa[x])return;
		fa[x]=y;
	}
	void cut(int x,int y)
	{
		makeroot(x),access(y),splay(x);
		if(fa[y]!=x)return;
		fa[y]=ch[x][sonr(y)]=0;
		update(x);
	}
	int findfir(int u,int l,int r)
	{
		pushdown(u);
		if(Min[ch[u][0]]<l || Max[ch[u][0]]>r)return findfir(ch[u][0],l,r);
		if(dfn[u]<l || dfn[u]>r)return u;
		return findfir(ch[u][1],l,r);
	}
};
 
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	LCT::Min[0]=1<<30;
	int u,v;
	readint(n);
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v);
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1);
	for(int i=1;i<=n;++i)LCT::Min[i]=LCT::Max[i]=dfn[i];
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v);
		LCT::link(u,v);
	}
	printf("%d\n",n-1);
	for(int i=n;i>1;--i)
	{
		u=q[i];
		LCT::makeroot(u);
		LCT::access(pa[u]);
		LCT::splay(u);
		int x=LCT::findfir(u,dfn[u],dfn[u]+size[u]-1),y;
		LCT::access(x);
		LCT::splay(x);
		LCT::pushdown(x);
		for(y=LCT::ch[x][0];LCT::ch[y][1];y=LCT::ch[y][1])LCT::pushdown(y);
		LCT::cut(x,y);
		LCT::link(u,pa[u]);
		printf("%d %d %d %d\n",u,pa[u],x,y);
	}
	return 0;
}