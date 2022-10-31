#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int n,Q,a[N],ans[N],tr[N];
struct ky{
	int l,r,id;
	bool operator < (const ky&p)const{return r<p.r;}
}q[N];
il void add(it x){while(x) ++tr[x],x-=(x&-x);}
il int que(it x){it ans=0;while(x<=n) ans+=tr[x],x+=(x&-x);return ans;}
int main(){
	scanf("%d%d",&n,&Q);it i,j=1;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	for(i=1;i<=Q;++i) scanf("%d%d",&q[i].l,&q[i].r),++q[i].l,q[i].r=n-q[i].r,q[i].id=i;
	std::sort(q+1,q+1+Q);
	for(i=1;i<=n;++i){
		if(a[i]==i) add(i);
		if(a[i]<i){
			it l=1,r=i,mid,ans=0;
			while(l<=r) mid=l+r>>1,que(mid)>=i-a[i]?ans=mid,l=mid+1:r=mid-1;
			add(ans);
		}
		while(j<=Q&&q[j].r<i) ++j;
		while(j<=Q&&q[j].r==i) ans[q[j].id]=que(q[j].l),++j;
	}
	for(i=1;i<=Q;++i) printf("%d\n",ans[i]);
	return 0;
}