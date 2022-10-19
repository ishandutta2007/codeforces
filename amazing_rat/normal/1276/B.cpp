#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e5)+10;
int T,n,m,idx,tot,nxt[maxn*2],head[maxn];
int to[maxn*2],fa[maxn],sz[maxn],t1,t2;
int dfn[maxn],low[maxn],a,b;
map<ll,bool> M;
ll haxi(int x,int y) { return (ll)(x-1)*n+y; }
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
bool tarjan(int u) {
	//printf("%d %d\n",u,fa[u]);
    dfn[u]=low[u]=++idx; sz[u]=1;
    bool flag,res=(u==b);
    for (int i=head[u],v;i;i=nxt[i]) {
        v=to[i];
        if (dfn[v]==-1) {
            fa[v]=u;
            flag=tarjan(v);
            sz[u]+=sz[v];
            low[u]=min(low[u],low[v]);
            if (flag) res=1;
            if (u==b&&low[v]>=dfn[u]) t1+=sz[v];
            if (u==a&&!flag) t2+=sz[v];
        }
        else if (v!=fa[u])
            low[u]=min(low[u],dfn[v]);
    }
    return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	int x,y;
	while (T--) {
		read(n); read(m); read(a); read(b);
		M.clear();
		tot=idx=0;
		for (int i=1;i<=n;i++) head[i]=0,dfn[i]=-1;
		while (m--) {
			read(x); read(y);
			if (M[haxi(x,y)]) continue;
			M[haxi(x,y)]=M[haxi(y,x)]=1;
			add(x,y); add(y,x);
		}
		t1=t2=0; fa[a]=0;
		tarjan(a);
		printf("%lld\n",(ll)t1*t2);
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