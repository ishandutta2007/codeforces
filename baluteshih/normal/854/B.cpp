#include <stdio.h>

int main()
{
	long long n,k,ans,lans;
	while(scanf("%lld%lld",&n,&k)!=EOF)
	{
		lans=(n!=k && k!=0);
		if(k*3<=n) ans=k*2;
		else if(k*3==n+1) ans=k*2-1;
		else
		{
			ans=(n/3)*2,k-=n/3;
			if(n%3==2) k--,ans++;
			else if(n%3==1) k--;
			ans-=k;
		}
		printf("%lld %lld\n",lans,ans);
	}
}