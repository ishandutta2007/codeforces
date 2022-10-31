#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int n,m,Q;
struct ky{
	int x,y,col;
	bool operator < (const ky&p)const{return x^p.x?x<p.x:(y^p.y?y<p.y:col>p.col);}
}a[N],b[N];
il int Min(ct p,ct q){return p<q?p:q;}
il bool ck(ct mid){
	it i,minn=2e9,fl=0;
	for(i=1;i<=mid;++i) b[i]=a[i];
	std::sort(b+1,b+1+mid);
	for(i=1;i<=mid;++i){
		b[i].col?minn=Min(minn,b[i].y):fl|=(b[i].y>=minn);
		if(fl) return 0;
	}
	return 1;
}
il void ms(){
	it l=1,r=Q,mid,ans=0;
	while(l<=r) mid=l+r>>1,ck(mid)?ans=mid,l=mid+1:r=mid-1;
	for(it i=1;i<=ans;++i) puts("YES");
	for(it i=ans+1;i<=Q;++i) puts("NO");
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);it i;
	for(i=1;i<=Q;++i) scanf("%d%d",&a[i].x,&a[i].y),a[i].col=a[i].x&1,a[i].x=a[i].x+1>>1,a[i].y=a[i].y+1>>1;
	ms();
	return 0;
}