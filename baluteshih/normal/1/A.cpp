#include <stdio.h> 

int main()
{
	long long n,m,a;
	scanf("%lld%lld%lld",&n,&m,&a),n = n/a + (n%a!=0),m = m/a + (m%a!=0);
	printf("%lld\n",n*m);
}