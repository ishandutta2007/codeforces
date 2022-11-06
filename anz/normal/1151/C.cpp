#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MOD = 1000000007;

ll mPow(ll a, ll b)
{
	if (b == 0) return 1;
	if (b & 1)
		return a * mPow(a, b - 1);
	else
	{
		ll tmp = mPow(a, b / 2);
		return tmp * tmp;
	}
}

ll mInv(ll n)
{
	return mPow(n, MOD - 2);
}

ll l, r;

ll s(ll n)
{
	ll result = 0;
	ll cnt = 1;
	ll mul = 2;
	while (n >= mul)
	{
		mul *= 2;
		cnt++;
	}

	ll lenOdd = 0, lenEven = 0;
	lenOdd = lenEven = cnt / 2;
	if ((cnt & 1) == 0) lenEven--;

	lenOdd = (mPow(4, lenOdd) - 1) / 3;
	lenEven = (mPow(4, lenEven) - 1) * 2 / 3;

	if (cnt & 1)
		lenOdd += n - (mul / 2) + 1;
	else
		lenEven += n - (mul / 2) + 1;

	result += (lenOdd % MOD) * (lenOdd % MOD) % MOD;
	result += (lenEven % MOD) * ((lenEven + 1) % MOD) % MOD;
	result %= MOD;

	return result;
}

int main()
{
	scanf("%lld%lld", &l, &r);
	ll result = s(r) - s(l - 1);
	if (result < 0) result += MOD;
	result %= MOD;
	printf("%lld", result);
}