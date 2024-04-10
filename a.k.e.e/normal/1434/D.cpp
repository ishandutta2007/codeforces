#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=500005,MAXK=19;
 
int n,_u[MAXN],_v[MAXN];
vector<pii> G[MAXN];
int dfn[MAXN],size[MAXN],d0[MAXN],d1[MAXN],col[MAXN],ded[MAXN],dfn_cnt;
void dfs(int u,int pa,int *dep)
{
	size[u]=1;
	dfn[u]=++dfn_cnt;ded[dfn_cnt]=u;
	for(auto p:G[u])
	{
		int v=p.x,c=p.y;
		if(v==pa)continue;
		dep[v]=dep[u]+1;
		col[v]=col[u]^c;
		dfs(v,u,dep);
		size[u]+=size[v];
	}
}
int co[MAXN<<2],mu[MAXN<<2][2][2],tag[MAXN<<2];
void maintain(int id)
{
	swap(mu[id][0][0],mu[id][1][0]);
	swap(mu[id][0][1],mu[id][1][1]);
	co[id]^=1;tag[id]^=1;
}
void update(int id)
{
	for(int t=0;t<=1;++t)
		mu[id][0][t]=max(mu[id<<1][0][t],mu[id<<1|1][0][t]),
		mu[id][1][t]=max(mu[id<<1][1][t],mu[id<<1|1][1][t]);
}
void pushdown(int id)
{
	if(!tag[id])return;
	maintain(id<<1),maintain(id<<1|1);
	tag[id]=0;
}
void build(int id,int l,int r)
{
	tag[id]=0;
	if(l==r)
	{
		co[id]=col[ded[l]];
		mu[id][co[id]][0]=d0[ded[l]];
		mu[id][co[id]][1]=d1[ded[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}
void modify(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)
	{
		maintain(id);
		return;
	}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr);
	else modify(id<<1,l,mid,ql,mid),modify(id<<1|1,mid+1,r,mid+1,qr);
	update(id);
}
int query(int id,int l,int r,int ql,int qr,int t,int s)
{
	if(l==ql && r==qr)return mu[id][t][s];
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr,t,s);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr,t,s);
	return max(query(id<<1,l,mid,ql,mid,t,s),query(id<<1|1,mid+1,r,mid+1,qr,t,s));
}
int qcol(int id,int l,int r,int x)
{
	if(l==r)return co[id];
	pushdown(id);
	int mid=(l+r)>>1;
	if(x<=mid)return qcol(id<<1,l,mid,x);
	return qcol(id<<1|1,mid+1,r,x);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q;
	readint(n);
	for(int i=1;i<n;++i)
	{
		int c;
		readint(_u[i]),readint(_v[i]),readint(c);
		G[_u[i]].pb(mp(_v[i],c));G[_v[i]].pb(mp(_u[i],c));
	}
	dfs(1,-1,d1);
	int u=1;
	for(int i=2;i<=n;++i)if(d1[i]>d1[u])u=i;
	dfn_cnt=0;dfs(u,-1,d0);
	int v=1;
	for(int i=2;i<=n;++i)if(d0[i]>d0[v])v=i;
	d1[v]=0;dfn_cnt=0;dfs(v,-1,d1);
	d1[0]=d0[0]=-1;
	for(int i=1;i<n;++i)
		if(d1[_u[i]]>d1[_v[i]])swap(_u[i],_v[i]);
	memset(mu,-1,sizeof(mu));
	build(1,1,n);
	readint(Q);
	while(Q--)
	{
		int x;
		readint(x);
		x=_v[x];
		modify(1,1,n,dfn[x],dfn[x]+size[x]-1);
		int cu=qcol(1,1,n,dfn[u]),cv=qcol(1,1,n,dfn[v]);
		if(cu==cv)printf("%d\n",d0[v]);
		else printf("%d\n",max(mu[1][cu][0],mu[1][cv][1]));
	}
	return 0;
}