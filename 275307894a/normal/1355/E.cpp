#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#include<cmath>
using namespace std;
long long n,m,k,x,y,a[1000039],ans,ans1,ans2,tot,pus,l,r,mid;
inline long long check(int xs){
	ans1=ans2=ans=0;
	for(int i=1;i<=n;i++) ans1+=max(a[i]-xs,0),ans2+=max(xs-a[i],0);
	ans+=min(ans1,ans2)*y;
	if(ans1>ans2)ans+=(ans1-ans2)*x;
	else ans+=(ans2-ans1)*m;
	return ans;
}
int main(){
	register int i;
	scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
	y=min(y,x+m);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),r=max(r,a[i]);
	//for(i=1;i<=r;i++) printf("%lld ",check(i));
	l=0;r++;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid-1)>check(mid+1)) l=mid;
		else r=mid;
	}
	printf("%lld\n",min(check(l),check(r)));
}