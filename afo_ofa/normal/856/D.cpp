#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>inline void Read(T &x) {
	x=0;T f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	x*=f;
}
const int maxn=200005;
vector<int>G[maxn],rf[maxn];
int n,m,clk,fa[19][maxn],dep[maxn],f[maxn],id[maxn],od[maxn],son[maxn];
struct Path {
	int u,v,c;
	Path(int u=0,int v=0,int c=0):u(u),v(v),c(c){}
}p[maxn];
struct FenwickTree {
	int c[maxn];
	inline void Add(int x,int d) {
		for(;x<=n;x+=x&-x)
			c[x]+=d;
	}
	inline int Que(int x) {
		int res=0;
		for(;x;x-=x&-x)
			res+=c[x];
		return res;
	}
	inline void Update(int x,int d) {
		if(x)
			Add(id[x],d),Add(od[x]+1,-d);
	}
	inline int Query(int x,int y,int l) {
		return Que(id[x])-Que(id[l])+Que(id[y])-Que(id[fa[0][l]]);
	}
}bit[2];
inline void PreDfs(int u=1) {
	id[u]=++clk;
	for(int i=1;i<19;++i)
		fa[i][u]=fa[i-1][fa[i-1][u]];
	for(vector<int>::iterator t=G[u].begin();t!=G[u].end();++t) {
		int v=*t;
		if(v==fa[0][u])
			continue;
		dep[v]=dep[u]+1,fa[0][v]=u;PreDfs(v);
	}
	od[u]=clk;
}
inline int Jmp(int x,int d) {
	for(int i=18;~i;--i)
		if(d>>i&1)
			x=fa[i][x];
	return x;
}
inline int Lca(int x,int y) {
	if(dep[x]<dep[y])
		swap(x,y);
	x=Jmp(x,dep[x]-dep[y]);
	for(int i=18;~i;--i)
		if(fa[i][x]!=fa[i][y])
			x=fa[i][x],y=fa[i][y];
	return x==y?x:fa[0][x];
}
inline void Solve(int u=1) {
	for(vector<int>::iterator t=G[u].begin();t!=G[u].end();++t) {
		int v=*t;
		if(v==fa[0][u])
			continue;
		Solve(v),son[u]+=f[v];
	}
	f[u]=son[u];
	for(vector<int>::iterator t=rf[u].begin();t!=rf[u].end();++t) {
		int v=*t,x=p[v].u,y=p[v].v,w=p[v].c;
		if(dep[x]>dep[y])
			swap(x,y);
		f[u]=max(f[u],w+bit[1].Query(x,y,u)-bit[0].Query(x,y,u));
	}
	bit[0].Update(u,f[u]),bit[1].Update(fa[0][u],f[u]);
}
int main() {
	Read(n),Read(m);
	for(int i=2,x;i<=n;++i)
		Read(x),G[x].push_back(i),G[i].push_back(x);
	PreDfs();
	for(int i=1,x,y,w;i<=m;++i)
		Read(x),Read(y),Read(w),p[i]=Path(x,y,w),rf[Lca(x,y)].push_back(i);
	Solve(),printf("%d\n",f[1]);
}