#include<cstdio>
using namespace std;
#define N 1234567
int s[N],n,as[N];
long long k;
int main()
{
	scanf("%d%lld",&n,&k);
	if(k<1ll*n*(n+1)/2)printf("-1\n");
	else
	{
		long long mx=1ll*(n*2-(n-1)/2)*((n+1)/2)-(n%2==1?n/2+1:0);
		if(k>mx)printf("%lld\n",mx);
		else printf("%lld\n",k);
		for(int i=1;i<=n;i++)printf("%d ",i);
		printf("\n");
		long long las=k-1ll*n*(n+1)/2;
		for(int i=1;i<=n;i++)
		{
			int tp=n-i*2+1;
			if(las>tp)las-=tp,as[i]=n-i+1;
			else
			{
				as[i]=i+las;
				for(int j=i+1;j<i*2+las;j++)as[j]=j-i;
				for(int j=i*2+las;j<=n;j++)as[j]=j-i+1;
				for(int i=1;i<=n;i++)printf("%d ",as[i]);
				return 0;
			}
		}
		for(int i=1;i<=n;i++)printf("%d ",as[i]);
	}
}