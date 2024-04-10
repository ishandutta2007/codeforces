#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int T,n,tot,head[maxn],nxt[maxn*2],to[maxn*2];
ll dis[maxn],ans,w[maxn*2];
int fa[maxn],sz[maxn],SZ[maxn];
struct node { int x; ll y; } d[maxn];
bool cmp(node a,node b) { return a.y>b.y; }
void add(int x,int y,int z) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y; w[tot]=z;
}
void dfs(int u,int p) {
	fa[u]=p; SZ[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==p) continue;
		dis[v]=dis[u]+w[i];
		dfs(v,u);
		SZ[u]+=SZ[v];
	}
}
struct cmp2 {
	bool operator() (int a,int b) {
		return a<b;
	}
};
priority_queue<int,vector<int>,cmp2> q[maxn];
int dfs(int u) {
	q[u]=priority_queue<int,vector<int>,cmp2>();
	int tmp=1,xx;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v==fa[u]) continue;
		xx=dfs(v);
		q[u].push(xx);
		tmp+=xx;
	}
	q[u].push(1);
	if (tmp>n-SZ[u]) {
		xx=tmp-(n-SZ[u]);
		while (q[u].size()>1&&xx>0) {
			int x=q[u].top(); q[u].pop();
			int y=q[u].top(); q[u].pop();
			x--; y--; xx-=2; tmp-=2;
			if (x) q[u].push(x);
			if (y) q[u].push(y);
			ans-=dis[u]*2;
		}
	}
	return tmp;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); int x,y,z,u;
	while (T--) {
		read(n); n*=2;
		for (int i=1;i<=n;i++) head[i]=0;
		tot=0;
		for (int i=1;i<n;i++) {
			read(x); read(y); read(z);
			add(x,y,z); add(y,x,z);
		}
		dfs(1,0);
		ans=0;
		for (int i=1;i<=n;i++) d[i]=(node){i,dis[i]},ans+=dis[i];
		sort(d+1,d+n+1,cmp);
	//	for (int i=1;i<=n;i++) printf("%d %lld\n",i,dis[i]);
		for (int I=1;I<=n;I++) {
			u=d[I].x; sz[u]=1;
			for (int i=head[u],v;i;i=nxt[i]) {
				v=to[i];
				if (v==fa[u]) continue;
				sz[u]+=sz[v];
			}
			ans-=(sz[u]/2)*2*dis[u];
			sz[u]%=2;
		}
		printf("%lld ",ans);
		ans=0;
		for (int i=1;i<=n;i++) ans+=dis[i];
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/