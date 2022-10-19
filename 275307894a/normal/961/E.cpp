#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,root[200039],maxn=1e9,minn=0,tot,a[200039];
long long ans;
struct tree{int l,r,f;}f[20000039];
inline void xj(int &now){f[++tot]=f[now];now=tot;}
inline void get(int x,int l,int r,int &now){
	xj(now);f[now].f++;
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m) get(x,l,m,f[now].l);
	else get(x,m+1,r,f[now].r);
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now].f;
	int m=l+r>>1,fs=0;
	if(x<=m&&f[now].l) fs+=find(x,y,l,m,f[now].l);
	if(y>m&&f[now].r) fs+=find(x,y,m+1,r,f[now].r);
	return fs;
}
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		root[i]=root[i-1];
		ans+=find(i,maxn,minn,maxn,root[min(i-1,a[i])]);
		get(a[i],minn,maxn,root[i]);
	}
	printf("%lld\n",ans);
}