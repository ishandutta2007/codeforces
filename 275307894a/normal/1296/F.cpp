#include<cstdio>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define beg int cur=s.h[x]
#define end cur
#define go cur=tmp.z
using namespace std;
int n,m,k,w[10039],xs,ys,anss[10039];
int d[10039],fa[10039];
struct yyy{int to,z,num;};
struct ljb{
	int head,h[10039];
	yyy f[20039];
	inline void add(int x,int y,int z){
		f[++head]=(yyy){y,h[x],z};
		h[x]=head;
	}
}s;
struct ques{int x,y,z;}g[10039];
inline bool cmp(ques x,ques y){return x.z<y.z;}
inline void dfs(int x,int last){
	d[x]=d[last]+1;yyy tmp;fa[x]=last;
	for(beg;end;go){
		tmp=s.f[cur];
		if(tmp.to!=last) dfs(tmp.to,x);
	}
}
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline void lca(int x,int y,int z){
	if(d[x]<d[y]) swap(x,y);
	while(d[x]!=d[y]) w[x]=z,x=fa[x];
	if(x==y)return;
	while(fa[x]!=fa[y]) w[x]=w[y]=z,x=fa[x],y=fa[y];
	w[x]=w[y]=z;
}
inline int check(int x,int y){
	int ans=1e9;
	if(d[x]<d[y]) swap(x,y);
	while(d[x]!=d[y]) ans=min(w[x],ans),x=fa[x];
	if(x==y)return ans;
	while(fa[x]!=fa[y]) ans=min(ans,min(w[x],w[y])),x=fa[x],y=fa[y];
	return min(ans,min(w[x],w[y]));
}
inline void dfss(int x,int last){
	yyy tmp;
	for(beg;end;go){
		tmp=s.f[cur];
		if(tmp.to!=last) anss[tmp.num]=w[tmp.to],dfss(tmp.to,x);
	}
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d%d",&xs,&ys),s.add(xs,ys,i),s.add(ys,xs,i);
	scanf("%d",&m);
	for(i=1;i<=m;i++) scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].z);
	sort(g+1,g+m+1,cmp);
	dfs(1,0);
	for(i=1;i<=m;i++) lca(g[i].x,g[i].y,g[i].z);
	for(i=1;i<=m;i++) if(check(g[i].x,g[i].y)!=g[i].z){printf("-1");return 0;}
	dfss(1,0);
	for(i=1;i<n;i++) printf("%d ",anss[i]?anss[i]:1);
}