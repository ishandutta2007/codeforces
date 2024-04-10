#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
const int MAXN=200005;

int n,q;

int c[MAXN<<1];
void add(int x,int d){for(;x<=n+q;x+=(x&-x))c[x]+=d;}
int query(int x){int s=0;for(;x;x-=(x&-x))s+=c[x];return s;}

int size[MAXN],whi[MAXN];
int ch[MAXN][2],fa[MAXN];
bool rev[MAXN];
bool nroot(int u){return ch[fa[u]][0]==u || ch[fa[u]][1]==u;}
bool sontype(int u){return ch[fa[u]][1]==u;}
void reverse(int u){rev[u]^=1,swap(ch[u][0],ch[u][1]);}
void pushdown(int u)
{
	if(rev[u])reverse(ch[u][0]),reverse(ch[u][1]),rev[u]=0;
	if(whi[u])whi[ch[u][0]]=whi[ch[u][1]]=whi[u];
}
void pushall(int u){if(nroot(u))pushall(fa[u]);pushdown(u);}
void update(int u){size[u]=size[ch[u][0]]+size[ch[u][1]]+1;}
void rotate(int u)
{
	int t=sontype(u),x=fa[u],y=fa[x],z=ch[u][t^1];
	if(nroot(x))ch[y][sontype(x)]=u;fa[u]=y;
	ch[x][t]=z;if(z)fa[z]=x;
	ch[u][t^1]=x;fa[x]=u;
	update(x);update(u);
}
void splay(int u)
{
	pushall(u);
	while(nroot(u))
		if(!nroot(fa[u]))rotate(u);
		else if(sontype(u)==sontype(fa[u]))rotate(fa[u]),rotate(u);
		else rotate(u),rotate(u);
}
void access(int u,int ks)
{
	int v;
	for(v=0;u;u=fa[v=u])
	{
		splay(u);
		add(whi[u],size[ch[u][1]]-size[u]);
		ch[u][1]=v;
		update(u);
	}
	splay(v);
	whi[v]=n+ks;
	add(whi[v],size[v]);
}

vector<int> G[MAXN];
int deg[MAXN];
priority_queue<int,vector<int>,greater<int> > pq;
void dfs(int u,int pa)
{
	for(auto v:G[u])
	{
		if(v==pa)continue;
		fa[v]=u;
		dfs(v,u);
	}
}
inline int ask(int u){splay(u);return query(whi[u])-size[ch[u][0]];}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	char op[10];int u,v;
	readint(n),readint(q);
	for(int i=1;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u),++deg[u],++deg[v];
	int cnt=0;
	for(int i=1;i<=n;++i)if(deg[i]==1)pq.push(i);
	while(!pq.empty())
	{
		u=pq.top();pq.pop();
		whi[u]=++cnt;
		for(auto v:G[u])
		{
			if(deg[v]==1)continue;
			--deg[v];
			if(deg[v]==1)pq.push(v);
		}
	}
	dfs(n,-1);
	for(int i=1;i<=n;++i)size[i]=1,add(i,1);
	for(int ks=1;ks<=q;++ks)
	{
		scanf("%s",op);readint(u);
		if(op[0]=='u')
		{
			access(u,ks);
			splay(u);
			reverse(u);
		}
		else if(op[0]=='w')printf("%d\n",ask(u));
		else readint(v),printf("%d\n",ask(u)<ask(v)?u:v);
	}
	return 0;
}