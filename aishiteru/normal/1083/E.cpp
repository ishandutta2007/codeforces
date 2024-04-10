#include<stdio.h>
#include<string.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
int n,q[N],top1,top2;
struct ky{
	int x,y;ll w,val;
	bool operator < (const ky&p)const{return x<p.x;}
}a[N];
ll f[N],ans;
il double slope(ct x,ct y){return a[x].x==a[y].x?1e18:(double) (1.0*(f[x]-f[y]))/(a[x].x-a[y].x);}
il ll cal(ct x,ct y){return f[y]-(0ll+a[y].x)*a[x].y+a[x].val;}
template<class I>
il void ckMax(I&p,I q){p=(p>q?p:q);}
int main(){ 
	scanf("%d",&n);it i;
	for(i=1;i<=n;++i) scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].w),a[i].val=(0ll+a[i].x)*a[i].y-a[i].w;
	std::sort(a+1,a+1+n),f[1]=a[1].val,q[top1=top2=1]=0;
	for(i=1;i<=n;++i){
		while(top1<top2&&slope(q[top1],q[top1+1])>=a[i].y) ++top1;
		f[i]=cal(i,q[top1]),ckMax(ans,f[i]);
		while(top1<top2&&slope(q[top2-1],q[top2])<slope(q[top2],i)) --top2;
		q[++top2]=i;
	}
	printf("%lld",ans);
	return 0;
}