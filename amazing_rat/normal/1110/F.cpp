#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1e17;
const int maxn=500010;
int n,q,tot,fa[maxn][20],cnt;
ll dep[maxn],c[maxn],DELTA;
ll tr[4*maxn],lazy[4*maxn],ans[maxn];
int a[maxn],b[maxn];
struct node {
	int l,r,id;
}; vector<node> Q[maxn];
struct edge {
	int to; ll w;
}; vector<edge> g[maxn];
void dfs(int u,int p) {
	fa[u][0]=p; int d=0;
	a[u]=++cnt;
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i].to;
		dep[v]=dep[u]+g[u][i].w;
		d++; dfs(v,u);
	}
	if (!d) c[u]=dep[u];
	else c[u]=INF; b[u]=cnt;
}
void build(int l,int r,int root) {
	if (l==r) { tr[root]=c[l]; return; }
	int mid=(l+r)/2;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);
	tr[root]=min(tr[root*2],tr[root*2+1]);
}
void pushdown(int root) {
	if (lazy[root]==0) return;
	tr[root*2]=min(tr[root*2]+lazy[root],INF);
	tr[root*2+1]=min(tr[root*2+1]+lazy[root],INF);
	lazy[root*2]+=lazy[root];
	lazy[root*2+1]+=lazy[root];
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,ll delta) {
	if (L<=l&&r<=R) {
		tr[root]=min(tr[root]+delta,INF);
		lazy[root]+=delta; return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2,delta);
	if (mid<R) add(L,R,mid+1,r,root*2+1,delta);
	tr[root]=min(tr[root*2],tr[root*2+1]);
}
ll query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	pushdown(root);
	int mid=(l+r)/2; ll res=INF;
	if (L<=mid) res=min(res,query(L,R,l,mid,root*2));
	if (mid<R) res=min(res,query(L,R,mid+1,r,root*2+1));
	return res;
}
void DFS(int u,int p) {
	for (int i=0;i<Q[u].size();i++)
		ans[Q[u][i].id]=DELTA+query(Q[u][i].l,Q[u][i].r,1,n,1);
	ll w;
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i].to; w=g[u][i].w;
		DELTA+=w;
		add(a[v],b[v],1,n,1,-w*2);
		DFS(v,u);
		DELTA-=w;
		add(a[v],b[v],1,n,1,w*2);
	}
}
bool cmp(edge x,edge y) {
	return x.to<y.to;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q);
	int x,y,z,l,r,L,R,res,mid;
	for (int i=2;i<=n;i++) {
		read(x); read(z);
		g[x].push_back((edge){i,z});
	}
	for (int i=1;i<=n;i++)
		sort(g[i].begin(),g[i].end(),cmp);
	dfs(1,0);
	build(1,n,1);
	for (int i=1;i<=q;i++) {
		read(x); read(l); read(r);
		Q[x].push_back((node){l,r,i});
	}
	DFS(1,0);
	for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}