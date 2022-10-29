#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1000005,md=1000000007;
int n,m,a,b,i,j,k,inv[N],jc[N],rjc[N],ans,pwm[N],pwn[N];
int C(int n,int m)
{
	return 1ll*jc[n]*rjc[m]%md*rjc[n-m]%md;
}
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	inv[1]=1;
	for(i=2;i<=max(n,m);++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	jc[0]=rjc[0]=pwm[0]=pwn[0]=1;
	for(i=1;i<=max(n,m);++i)
		jc[i]=1ll*jc[i-1]*i%md,rjc[i]=1ll*rjc[i-1]*inv[i]%md,pwm[i]=1ll*pwm[i-1]*m%md,pwn[i]=1ll*pwn[i-1]*n%md;
	for(i=0;i<=n-2&&i<=m-1;++i)
	{
		ans=(ans+1ll*C(n-2,i)*C(m-1,i)%md*jc[i]%md*(i+2==n?1:1ll*(i+2)*(i+2==n?1:pwn[n-(i+2)-1])%md)%md*pwm[n-i-2]%md)%md;
	}
	printf("%d",ans);
	return 0;
}