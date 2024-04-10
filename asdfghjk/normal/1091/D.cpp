#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1000005,md=998244353;
int n,i,j,jc[N],rjc[N],inv[N],ans;
int main()
{
	scanf("%d",&n);
	inv[1]=1;
	for(i=2;i<=n;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=1;
	for(i=1;i<=n;++i)
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md;
	ans=jc[n];
	for(i=1;i<=n;++i)
		ans=(ans+1ll*jc[n]*rjc[n-i]%md*(jc[n-i]-1+md)%md)%md;
	printf("%d",ans);
	return 0;
}