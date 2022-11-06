#include <stdio.h>

const long long mod=1000000007;

int main()
{
	long long a,b;
	scanf("%I64d%I64d",&a,&b);
	printf("%I64d",((b-1)*b/2%mod*(b*(a*(a+1)/2%mod)%mod+a))%mod);
	return 0;
}