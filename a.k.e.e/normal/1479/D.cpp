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
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD1=1010101039,MOD2=1000020001;
const int MAXN=300005,MAXK=19,MAXV=MAXN*21;

int n,a[MAXN];
vector<int> G[MAXN];
int anc[MAXN][MAXK],dep[MAXN];
int stot,vs[MAXN];
pii h[MAXV],pw[MAXN];
int lch[MAXV],rch[MAXV];
pii operator *(pii a,pii b){return mp(1ll*a.x*b.x%MOD1,1ll*a.y*b.y%MOD2);}
pii operator +(pii a,pii b){return mp((a.x+b.x)%MOD1,(a.y+b.y)%MOD2);}
int modify(int id,int l,int r,int x)
{
	int rt=++stot;
	if(l==r)
	{
		h[rt]=mp(1-h[id].x,1-h[id].y);
		return rt;
	}
	int mid=(l+r)>>1;
	if(x<=mid)lch[rt]=modify(lch[id],l,mid,x),rch[rt]=rch[id];
	else rch[rt]=modify(rch[id],mid+1,r,x),lch[rt]=lch[id];
	h[rt]=h[lch[rt]]*pw[r-mid]+h[rch[rt]];
	return rt;
}
int query(int u,int v,int l,int r,int ql,int qr)
{
	if(h[u]==h[v])return -1;
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(qr<=mid)return query(lch[u],lch[v],l,mid,ql,qr);
	if(ql>mid)return query(rch[u],rch[v],mid+1,r,ql,qr);
	int s=query(lch[u],lch[v],l,mid,ql,mid);
	if(s>0)return s;
	return query(rch[u],rch[v],mid+1,r,mid+1,qr);
}
void dfs(int u,int pa)
{
	for(int j=1;j<MAXK;++j)anc[u][j]=anc[anc[u][j-1]][j-1];
	for(auto v:G[u])
		if(v!=pa)
		{
			anc[v][0]=u;
			dep[v]=dep[u]+1;
			vs[v]=modify(vs[u],1,n,a[v]);
			dfs(v,u);
		}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	for(int i=MAXK-1;i>=0;--i)if(dep[anc[v][i]]>=dep[u])v=anc[v][i];
	if(u==v)return u;
	for(int i=MAXK-1;i>=0;--i)if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,u,v,l,r;
	readint(n),readint(Q);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	pw[0]=mp(1,1);pw[1]=mp(29,101);
	for(int i=2;i<=n;++i)pw[i]=pw[i-1]*pw[1]; 
	vs[1]=modify(0,1,n,a[1]);
	dep[1]=1;
	dfs(1,-1);
	while(Q--)
	{
		readint(u),readint(v),readint(l),readint(r);
		int d=lca(u,v);
		if(a[d]<l || a[d]>r)
		{
			int t=query(vs[u],vs[v],1,n,l,r);
			printf("%d\n",t);
		}
		else
		{
			int t=(a[d]==l?-1:query(vs[u],vs[v],1,n,l,a[d]-1));
			if(t<0)
			{
				t=(a[d]==r?-1:query(vs[u],vs[v],1,n,a[d]+1,r));
				if(t<0)
				{
					t=query(vs[u],vs[v],1,n,a[d],a[d]);
					if(t==-1)t=a[d];
					else t=-1;
				}
			}
			printf("%d\n",t);
		}
	}
	return 0;
}