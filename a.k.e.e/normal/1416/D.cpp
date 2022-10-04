#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
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
inline int inv(int x){return qmi(x,MOD-2);}
const int MAXN=1000005,MAXK=20;

int n,m,q,a[MAXN],u[MAXN],v[MAXN],op[MAXN],x[MAXN];
bool vis[MAXN];
int fa[MAXN],pa[MAXN],stot;
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
int tim[MAXN],ch[MAXN][2],anc[MAXN][MAXK],dfn[MAXN],dfn_cnt,size[MAXN];
pii Max[MAXN<<2];
void modify(int id,int l,int r,int x,int c)
{
	if(l==r){Max[id]=mp(c,l);return;}
	int mid=(l+r)>>1;
	if(x<=mid)modify(id<<1,l,mid,x,c);
	else modify(id<<1|1,mid+1,r,x,c);
	Max[id]=max(Max[id<<1],Max[id<<1|1]);
}
pii query(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return Max[id];
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	return max(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}
void dfs(int u)
{
	vis[u]=1;
	dfn[u]=++dfn_cnt;
	size[u]=1;
	for(int i=1;i<MAXK;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	if(u>n)for(int t=0;t<=1;++t)anc[ch[u][t]][0]=u,dfs(ch[u][t]),size[u]+=size[ch[u][t]];
	else modify(1,1,stot,dfn[u],a[u]);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m),readint(q);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=m;++i)readint(u[i]),readint(v[i]),vis[i]=1;
	for(int i=1;i<=q;++i)
	{
		readint(op[i]),readint(x[i]);
		if(op[i]==2)vis[x[i]]=0;
	}
	for(int i=1;i<=2*n-1;++i)fa[i]=i;
	for(int i=1;i<=n;++i)tim[i]=q+1;
	stot=n;
	for(int i=1;i<=m;++i)
		if(vis[i])
		{
			int tu=getfa(u[i]),tv=getfa(v[i]);
			if(tu==tv)continue;
			fa[tu]=fa[tv]=pa[tu]=pa[tv]=++stot;
			ch[stot][0]=tu,ch[stot][1]=tv;
			tim[stot]=q+1;
		}
	for(int i=q;i;--i)
		if(op[i]==2)
		{
			int tu=getfa(u[x[i]]),tv=getfa(v[x[i]]);
			if(tu==tv)continue;
			fa[tu]=fa[tv]=pa[tu]=pa[tv]=++stot;
			ch[stot][0]=tu,ch[stot][1]=tv;
			tim[stot]=i;
		}
	memset(vis,0,sizeof(vis));
	for(int i=stot;i;--i)
		if(!vis[i])dfs(i);
	for(int i=1;i<=q;++i)
	{
		if(op[i]==2)continue;
		int u=x[i];
		for(int j=MAXK-1;j>=0;--j)
			if(tim[anc[u][j]]>=i)u=anc[u][j];
		pii p=query(1,1,stot,dfn[u],dfn[u]+size[u]-1);
		printf("%d\n",p.x);
		modify(1,1,stot,p.y,0);
	}
	return 0;
}