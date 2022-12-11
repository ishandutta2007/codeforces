#include<cstdio>
#include<algorithm>
using namespace std;

#define MOD 1000000007

int qpow(int a, int n)
{
	if(n==0) return 1;
	int b = qpow(a,n/2);
	b = 1LL*b*b%MOD;
	if(n&1) b = 1LL*a*b%MOD;
	return b;
}

inline int inv(int x)
{
	return qpow(x,MOD-2);
}

int main()
{
	int n;
	scanf("%d", &n);
	int res = 2;
	for(int i = 0; i < n-1; i++)
	{
		res = 1LL * res * (2*n-1-i) % MOD;
		res = 1LL * res * inv(n-1-i) % MOD;
	}
	res += MOD-n;
	res %= MOD;
	printf("%d\n", res);
}