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
const int N=250005;
int n,cc,tt,a[N],b[N],hd[N],f[N],fa[N],ch[N][2],rev[N];
struct E{int v,nxt;}e[N*2]; 
inline void add(int u,int v){e[++cc]=(E){v,hd[u]};hd[u]=cc;e[++cc]=(E){u,hd[v]};hd[v]=cc;} 
int fnd(int x){return f[x]==x?x:f[x]=fnd(f[x]);}
void uni(int u,int v){u=fnd(u);v=fnd(v);f[u]=v;}
int dfs(int x,int p){for(int i=hd[x],y;i;i=e[i].nxt)if((y=e[i].v)!=p){dfs(y,x);a[++tt]=y;b[tt]=x;}}
inline int wh(int x){return ch[fa[x]][1]==x;}
inline int isrt(int x){return ch[fa[x]][0]!=x&&ch[fa[x]][1]!=x;}
inline void dn(int x)
{
	if(!rev[x])return;rev[x]=0;swap(ls,rs);
	if(ls)rev[ls]^=1;if(rs)rev[rs]^=1;
}
inline void rot(int x)
{
	int y=fa[x],z=fa[y],w=wh(x),t=ch[x][w^1];
	if(!isrt(y))ch[z][wh(y)]=x;fa[x]=z;
	ch[x][w^1]=y;fa[y]=x;ch[y][w]=t;if(t)fa[t]=y;
}
inline void psh(int x){if(!isrt(x))psh(fa[x]);dn(x);}
inline void splay(int x){psh(x);for(int y;!isrt(x);rot(x))if(!isrt(y=fa[x]))rot(wh(x)^wh(y)?x:y);}
inline void access(int x){for(int y=0;x;x=fa[y=x]){splay(x);rs=y;}}
inline void split(int x){access(x);splay(x);}
inline void mkrt(int x){split(x);rev[x]^=1;}
inline void link(int x,int y){mkrt(x);fa[x]=y;}
inline void cut(int x,int y){mkrt(x);split(y);ch[y][0]=fa[x]=0;}
inline void qry(int x,int y)
{
	mkrt(x);split(y);int u=x,v=y,t;x=fnd(x);
	while(y)
	{
		dn(t=y);
		if(fnd(y)==x)u=y,y=ch[y][1];else v=y,y=ch[y][0];
	}
	splay(t);printf("%d %d\n",u,v);cut(u,v);
}
int main()
{
	n=rd();rep(i,1,n-1)add(rd(),rd());
	dfs(1,0);rep(i,1,n)f[i]=i;
	rep(i,1,n-1)link(rd(),rd());
	printf("%d\n",n-1);
	rep(i,1,n-1)
	{
		printf("%d %d ",a[i],b[i]);
		qry(a[i],b[i]);link(a[i],b[i]);uni(a[i],b[i]);
	}
	return 0;
}