#include<cstdio>
#include<algorithm>
using namespace std;
long long m,t,n,k;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		long long tmp=1;
		for(int i=2;i<=n&&tmp<=m;i++)
		tmp=tmp*4+1;
		if(tmp<m)
		{
			printf("NO\n");
			continue;
		}
		if(n==2&&m==3)
		{
			printf("NO\n");
			continue;
		}
		if(m==0)
		{
			printf("YES %lld\n",n);
			continue;
		}
		long long tmp1=1,ans=n-1;
		for(int i=2;i<=n&&tmp1<=m;i++)
		{
			tmp1=tmp1*2+i;
			if(tmp1<=m)
			ans=n-i;
		}
		printf("YES %lld\n",ans);
	}
}