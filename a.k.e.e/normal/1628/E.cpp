#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=600005,MAXK=19,INF=1<<30;

int n,q;
pair<int,pii> e[MAXN];
int fa[MAXN],ch[MAXN][2],val[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
int anc[MAXN][MAXK],dep[MAXN],dfn[MAXN],dfn_cnt,ded[MAXN];
void dfs1(int u)
{
	dfn[u]=++dfn_cnt;
	ded[dfn[u]]=u;
	for(int i=1;i<MAXK;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	if(u<=n)return;
	for(int i=0;i<2;++i)
		anc[ch[u][i]][0]=u,
		dep[ch[u][i]]=dep[u]+1,
		dfs1(ch[u][i]);
}
int lca(int u,int v)
{
	if(!u||!v)return u|v;
	if(dep[u]>dep[v])swap(u,v);
	for(int i=MAXK-1;i>=0;--i)if(dep[v]-dep[u]>=(1<<i))v=anc[v][i];
	if(u==v)return u;
	for(int i=MAXK-1;i>=0;--i)if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}

int Min[MAXN<<2],Max[MAXN<<2],f[MAXN<<2],g[MAXN<<2],cov[MAXN<<2];
void build(int id,int l,int r)
{
	cov[id]=-1;
	Min[id]=INF,Max[id]=-INF;
	if(l==r)
	{
		f[id]=g[id]=dfn[l];
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	f[id]=min(f[id<<1],f[id<<1|1]);
	g[id]=max(g[id<<1],g[id<<1|1]);
}
void work(int id,int c)
{
	if(!c)Min[id]=INF,Max[id]=-INF,cov[id]=0;
	else Min[id]=f[id],Max[id]=g[id],cov[id]=1;
}
void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(l==ql && r==qr)
	{
		work(id,c);
		return;
	}
	if(cov[id]>=0)work(id<<1,cov[id]),work(id<<1|1,cov[id]),cov[id]=-1;
	int mid=(l+r)>>1;
	if(ql<=mid)modify(id<<1,l,mid,ql,min(qr,mid),c);
	if(qr>mid)modify(id<<1|1,mid+1,r,max(mid+1,ql),qr,c);
	Min[id]=min(Min[id<<1],Min[id<<1|1]);
	Max[id]=max(Max[id<<1],Max[id<<1|1]);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q;
	readint(n),readint(Q);
	for(int i=1;i<n;++i)readint(e[i].y.x),readint(e[i].y.y),readint(e[i].x);
	sort(e+1,e+n);
	for(int i=1;i<=2*n-1;++i)fa[i]=i,val[i]=-1;
	for(int i=1;i<n;++i)
	{
		val[i+n]=e[i].x;
		int u=getfa(e[i].y.x),v=getfa(e[i].y.y);
		fa[u]=fa[v]=i+n;
		ch[i+n][0]=u,ch[i+n][1]=v;
	}
	dfs1(2*n-1);
	build(1,1,n);
	while(Q--)
	{
		int op,l,r;readint(op);
		if(op==1)readint(l),readint(r),modify(1,1,n,l,r,1);
		else if(op==2)readint(l),readint(r),modify(1,1,n,l,r,0);
		else
		{
			int u;readint(u);
			int x=Min[1],y=Max[1];
			chkmin(x,dfn[u]),chkmax(y,dfn[u]);
			printf("%d\n",val[lca(ded[x],ded[y])]);
		}
	}
	return 0;
}