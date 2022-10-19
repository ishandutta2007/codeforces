#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,ans[1000039],d[1000039],cnt,root[1000039];
struct yyy{int to,z;};
struct ljb{
	int head,h[1000039];
	yyy f[2000039];
	inline void add(int x,int y){f[++head]=(yyy){y,h[x]};h[x]=head;}
}s;
static char buf[10000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=x*10+s-48,s=getchar();
}
inline void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
struct tree{int l,r,f,maxn;}f[21000039];
inline void up(int now){
	f[now].f=max(f[f[now].l].f,f[f[now].r].f);
	f[now].maxn=f[f[now].l].f<f[f[now].r].f?f[f[now].r].maxn:f[f[now].l].maxn;
}
inline void get(int x,int l,int r,int &now){
	if(!now) now=++cnt;
	if(l==r){f[now].f++;f[now].maxn=l;return;}
	int m=l+r>>1;
	if(x<=m) get(x,l,m,f[now].l);
	else get(x,m+1,r,f[now].r);
	up(now);
}
inline int merge(int l,int r,int x,int y){
	if(!x||!y) return x+y;
	if(l==r){f[x].f+=f[y].f;return x;}
	int m=l+r>>1;
	f[x].l=merge(l,m,f[x].l,f[y].l);
	f[x].r=merge(m+1,r,f[x].r,f[y].r);
	up(x);return x;
}
inline void dfs(int x,int last){
	d[x]=d[last]+1;yyy tmp;get(d[x],1,n,root[x]);
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last){
			dfs(tmp.to,x);
			root[x]=merge(1,n,root[x],root[tmp.to]);
		}
	}
	ans[x]=f[root[x]].maxn-d[x];
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	register int i;
	read(n);
	for(i=1;i<n;i++) read(x),read(y),s.add(x,y),s.add(y,x);
	dfs(1,0);
	for(i=1;i<=n;i++) print(ans[i]),putchar('\n');
}