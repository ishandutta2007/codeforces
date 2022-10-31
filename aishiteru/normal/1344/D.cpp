#include<stdio.h>
#include<algorithm>
#include<assert.h>
#define it register int
#define ct const int
#define il inline
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005;
const ll inf=4e18;
int n,a[N],b[N],id[N];
ll k,val[N];
il ll f(ct x,ct w){return a[x]==w?-inf:a[x]-3ll*w*w-3ll*w-1;}
il int cal(ct x,cll lim){
	if(f(x,0)<=lim) return 0;
	it l=0,r=a[x],mid,ans=0;
	while(l<=r) mid=l+r>>1,f(x,mid)<lim?r=mid-1:l=mid+1;
	return l;
}
il bool ck(cll mid){
	rll sum=0;
	for(it i=1;i<=n;++i)
		b[i]=cal(i,mid),sum+=b[i];
	return sum<=k;
}
il void ms(){
	rll l=-inf,r=inf,mid,ans=0;
	while(l<=r) mid=l+r>>1,ck(mid)?ans=mid,r=mid-1:l=mid+1;
	ck(ans);
}
int main(){
	scanf("%d%lld",&n,&k);it i;
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	ms();//rll check=0;
	for(i=1;i<=n;++i) val[i]=f(i,b[i]),id[i]=i,k-=b[i];
	auto cmp = [&](ct p,ct q){return val[p]>val[q];};
	std::sort(id+1,id+1+n,cmp);
	assert(k<=n);
	for(i=1;i<=k;++i) ++b[id[i]];
	for(i=1;i<=n;++i) printf("%d ",b[i]);//check+=b[i]*(a[i]-b[i]*b[i]);printf("\n%lld",check);
	return 0;
}