#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int n,i,a[N],c[N];
long long ans;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		c[a[i]]++;
	}
	for(i=1;i<=n;++i)
		ans+=1ll*c[i]*i*(n-i+1);
	for(i=1;i<n;++i)
		ans-=1ll*min(a[i],a[i+1])*(n-max(a[i],a[i+1])+1);
	printf("%lld",ans);
	return 0;
}