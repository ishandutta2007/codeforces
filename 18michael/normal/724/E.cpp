#include<bits/stdc++.h>
#define LL long long
LL n,c,sum=0,ans,a[10002];
int main()
{
	scanf("%lld%lld",&n,&c);for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(LL i=1,x;i<=n;++i)scanf("%lld",&x),sum+=x,a[i]=a[i]-x+(i-1)*c;
	ans=sum,std::sort(a+1,a+n+1);
	for(LL i=1;i<=n;++i)ans=std::min(ans,(sum+=a[i])-i*(i-1)/2*c);
	return 0&printf("%lld",ans);
}