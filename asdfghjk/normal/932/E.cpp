#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
int n,K,i,j,s2[5005][5005],ans;
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
	scanf("%d%d",&n,&K);
	s2[1][1]=1;
	for(i=2;i<=K;++i)
	{
		s2[i][1]=1;
		for(j=2;j<=i;++j)
			s2[i][j]=(s2[i-1][j-1]+1ll*s2[i-1][j]*j)%md;
	}
	for(j=1,i=1;j<=K&&j<=n;++j)
	{
		i=1ll*i*(n-j+1)%md;
		ans=(ans+1ll*s2[K][j]*i%md*pw(2,n-j)%md)%md;
	}
	printf("%d",ans);
	return 0;
}