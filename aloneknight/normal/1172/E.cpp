#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
#define ls ch[x][0]
#define rs ch[x][1]
inline int rd()
{
	int x=0,w=1;char c=getchar();while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();while(isdigit(c))x=x*10+c-48,c=getchar();return x*w;
}
const int N=400005;
int n,m,cc,c[N],hd[N],f[N],a[N],fa[N],s[N],sz[N],ch[N][2],tp[N];ll sq[N],ans[N];vector<pii>g[N];
//s(size under the chain),sz(size of virtual sons' subtree)
struct E{int v,nxt;}e[N*2];
inline void add(int u,int v){e[++cc]=(E){v,hd[u]};hd[u]=cc;e[++cc]=(E){u,hd[v]};hd[v]=cc;}
void dfs(int x,int p){f[x]=p;for(int i=hd[x],y;i;i=e[i].nxt)if((y=e[i].v)!=p)dfs(y,x);}
inline ll sqr(int x){return 1ll*x*x;}
inline int S(int x){return s[x]+sz[x];}
inline int wh(int x){return ch[fa[x]][1]==x;}
inline int isrt(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
inline void up(int x){s[x]=S(ls)+S(rs)+1;tp[x]=ls?tp[ls]:x;}
inline void rot(int x)
{
	int y=fa[x],z=fa[y],w=wh(x),t=ch[x][w^1];
	if(!isrt(y))ch[z][wh(y)]=x;fa[x]=z;
	if(t)fa[t]=y;ch[y][w]=t;fa[y]=x;
	ch[x][w^1]=y;up(y);
}
inline void splay(int x){for(int y;!isrt(x);rot(x))if(!isrt(y=fa[x]))rot(wh(x)^wh(y)?x:y);up(x);}
inline void access(int x){for(int y=0;x;x=fa[y=x])splay(x),sz[x]+=S(rs)-S(y),sq[x]+=sqr(S(rs))-sqr(S(y)),rs=y,up(x);}
inline ll qry(int x){splay(x);return sq[x]+sqr(S(rs));}
inline void mkrt(int x){access(x);splay(x);}
inline ll link(int x)
{
	a[x]=0;int y=f[x];mkrt(x);mkrt(y);
	int t=tp[y];ll res=-qry(x)-qry(t);
	splay(y);fa[x]=y;sz[y]+=S(x);sq[y]+=sqr(S(x));
	res+=qry(t);return res;
}
inline ll cut(int x)
{
	a[x]=1;int y=f[x];access(x);splay(y);
	int t=tp[y];ll res=-qry(t);
	splay(y);fa[x]=0;ch[y][1]=0;up(y);
	res+=qry(x)+qry(t);return res;
}
int main()
{
	n=rd();m=rd();a[n+1]=1;
	rep(i,1,n)c[i]=rd(),g[c[i]].pb(mp(i,0));
	rep(i,1,n-1)add(rd(),rd());dfs(1,n+1);
	rep(i,1,m){int x=rd(),v=rd();g[c[x]].pb(mp(x,i));g[c[x]=v].pb(mp(x,i));}
	rep(i,1,n)up(i);rep(i,1,n)link(i);
	rep(i,1,n)
	{
		ans[0]+=1ll*n*n;
		fore(j,g[i])
		{
			int x=g[i][j].X;
			ans[g[i][j].Y]+=a[x]?link(x):cut(x);
		}
		fore(j,g[i])if(a[g[i][j].X])link(g[i][j].X);
	}
	rep(i,1,m)ans[i]+=ans[i-1];
	rep(i,0,m)printf("%lld\n",1ll*n*n*n-ans[i]);
	return 0;
}