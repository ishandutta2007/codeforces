#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=998244353;
int n,m,K,s2[5005][5005],invm,ans,i,j,k,x,inv[5005];
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
	scanf("%d%d%d",&n,&m,&K);
	invm=pw(m,md-2);
	s2[0][0]=1;
	for(i=1;i<=K;++i)
		for(j=1;j<=i;++j)
			s2[i][j]=(s2[i-1][j-1]+1ll*s2[i-1][j]*j)%md;
	inv[1]=1;
	for(i=2;i<=K;++i)
		inv[i]=1ll*inv[md%i]*(md-md/i)%md;
	for(i=1,j=1,k=1,x=1;i<=K&&i<=n;++i)
	{
		j=1ll*j*invm%md;
		k=1ll*k*i%md;
		x=1ll*x*inv[i]%md*(n-i+1)%md;
		ans=(ans+1ll*s2[K][i]*k%md*j%md*x%md)%md;
	}
	printf("%d",ans);
	return 0;
}