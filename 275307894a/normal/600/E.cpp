#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,c[100039],root[100039],cnt,now;
long long ans[100039];
struct yyy{int to,z;};
struct ljb{
	int head,h[100039];
	yyy f[200039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
struct tree{int l,r,f;long long maxn;}f[10000039];
inline void up(int now){
	f[now].f=max(f[f[now].l].f,f[f[now].r].f);
	if(f[f[now].l].f==f[f[now].r].f) f[now].maxn=f[f[now].l].maxn+f[f[now].r].maxn;
	else f[now].maxn=f[f[now].l].f>f[f[now].r].f?f[f[now].l].maxn:f[f[now].r].maxn;
}
inline void get(int x,int l,int r,int &now){
	if(!now) now=++cnt;
	if(l==r){f[now].f++;f[now].maxn=l;return;}
	int m=l+r>>1;
	if(x<=m) get(x,l,m,f[now].l);
	else get(x,m+1,r,f[now].r);
	up(now);
}
inline int merge(int x,int y,int l,int r){
	if(!x||!y) return x+y;
	if(l==r){f[x].f+=f[y].f;f[x].maxn=l;return x;}
	int m=l+r>>1;
	f[x].l=merge(f[x].l,f[y].l,l,m);
	f[x].r=merge(f[x].r,f[y].r,m+1,r);
	up(x);return x;
}
inline void dfs(int x,int last){
	yyy tmp;
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last) dfs(tmp.to,x),root[x]=merge(root[x],root[tmp.to],1,n);
	}
	ans[x]=f[root[x]].maxn;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&c[i]),get(c[i],1,n,root[i]);
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
	dfs(1,0);
	for(i=1;i<=n;i++) printf("%lld ",ans[i]);
}