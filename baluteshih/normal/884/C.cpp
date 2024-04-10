#include <stdio.h>

long long unions[100050],counts[100050];

long long f(long long n)
{
	if(unions[n]==n) return n;
	return unions[n]=f(unions[n]); 
}

int main()
{
	long long n,i,tmp,a=0,b=0,ans=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		unions[i]=i;
	for(i=1;i<=n;i++)
		scanf("%lld",&tmp),unions[f(tmp)]=f(i);
	for(i=1;i<=n;i++)
		counts[f(i)]++;
	for(a=counts[1],i=2,ans=counts[1]*counts[1];i<=n;ans+=counts[i]*counts[i],i++)
		if(counts[i]>a) b=a,a=counts[i];
		else if(counts[i]>b) b=counts[i];
	printf("%lld\n",ans+2*a*b);
}