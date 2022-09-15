#include <stdio.h>

long long gcd(long long a, long long b)
{
	if(a<b) return gcd(b, a);
	if(!b) return a;
	return gcd(b, a%b);
}
long long min(long long a, long long b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	long long t, u, v, m, g, k;
	scanf("%lld%lld%lld",&t,&u,&v);
	m = min(u, v);
	g = gcd(u, v);
	double l = (double) (u / g) * v;
	if(l>(double)t)
		k = min(t, m-1);
	else
		k = (t/((u/g)*v))*m + min(t%((u/g)*v), m-1);
	g = gcd(k, t);
	printf("%lld/%lld\n", k/g, t/g);
	return 0;
}