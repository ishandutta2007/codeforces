#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2000005;
const int MOD = 1000000007;

LL f[N];

void pre(int n)
{
	for (int i = 3; i <= n; i++)
		if (i % 3 == 0) f[i] = (f[i - 1] + f[i - 2] * 2 + 1) % MOD;
		else f[i] = (f[i - 1] + f[i - 2] * 2) % MOD;
}

int main()
{
	pre(2000000);
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		printf("%lld\n", f[n] * 4 % MOD);
	}
	return 0;
}