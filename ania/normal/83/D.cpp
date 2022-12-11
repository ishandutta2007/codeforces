#include <cstdio>
#include <algorithm>
using namespace std;

int go(int,int);

bool isprime(int x)
{
	if(x<2) return 0;
	for(int d = 2; d*d <= x; d++)
		if(x % d == 0) return 0;
	return 1;
}

int f(int a, int k)
{
	int res = a;
	for(int d = 2; d < k; d++)
		res -= go(a, d);
	//printf("f %d %d = %d\n", a, k, res);
	return res;
}

int go(int a, int k)
{
	if(!isprime(k)) return 0;
	if(a < k) return 0;
	if(a < 1LL*k*k) return 1;
	int R = f(a/k, k);
	return R;
}

int main()
{
	int a,b,k;
	scanf("%d%d%d", &a, &b, &k);
	printf("%d\n", go(b,k) - go(a-1,k));
}