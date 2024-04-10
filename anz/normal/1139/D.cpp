#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <unordered_map>

using namespace std;

long long m;
const long long MOD = 1000000007;
const long long ARR_SIZE = 100001;
long long exLen[ARR_SIZE];

long long primeTable[ARR_SIZE];
unordered_map<long long, long long> prime[ARR_SIZE];
vector<long long> fact[ARR_SIZE];

long long gcd(long long a, long long b)
{
	while (b)
	{
		long long tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

long long mPow(long long a, long long b)
{
	if (b == 0) return 1;
	if (b & 1)
	{
		return mPow(a, b - 1)*a % MOD;
	}
	else
	{
		long long res = mPow(a, b / 2);
		return res * res % MOD;
	}
}

long long mInv(long long n)
{
	return mPow(n, MOD - 2);
}

long long f(long long x, long long y)
{ //gcd(x,a)=y  a 
	long long result = m / y;

	vector<long long> tmp;
	unordered_map<long long, long long>::iterator i;
	for (i = prime[x].begin(); i != prime[x].end(); i++)
	{
		if (prime[y].count((*i).first) == 0)
		{
			tmp.push_back((*i).first);
		}
		else if ((*i).second != prime[y][(*i).first])
		{
			tmp.push_back((*i).first);
		}
	}

	for (long long i = 1; i < (1 << tmp.size()); i++)
	{
		long long sign = 1;
		long long prod = 1;
		for (long long j = 0; j < tmp.size(); j++)
		{
			if (i & (1ll << j)) {
				prod *= tmp[j];
				sign *= -1;
			}
		}
		result += sign * m / y / prod;
	}

	return result;
}

long long expectedLength(long long x)
{ // gcd x    
	if (x == 1) return 0;
	long long& ret = exLen[x];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = 0; i < fact[x].size(); i++)
	{
		ret += expectedLength(fact[x][i])*f(x, fact[x][i]) % MOD*mInv(m) % MOD;
		ret %= MOD;
	}
	return ret = ret * m % MOD * mInv(m - m / x) % MOD;
	//return ret = ret * x % MOD * mInv(x-1) % MOD;
}

int main()
{
	memset(exLen, -1, sizeof(exLen));
	scanf("%lld", &m);

	for (int i = 2; i <= m; i++)
	{
		if (!primeTable[i])
		{
			for (int j = i; j <= m; j += i)
			{
				primeTable[j] = i;
				int tmp = j;
				int cnt = 0;
				while (tmp%i == 0)
				{
					tmp /= i;
					cnt++;
				}
				prime[j][i] = cnt;
			}
		}
	}

	for (int i = 1; i <= m; i++)
		for (int j = i + i; j <= m; j += i)
		{
			fact[j].push_back(i);
		}

	long long result = 0;

	for (int i = 1; i <= m; i++)
	{
		result += expectedLength(i) * mInv(m) % MOD;
		result %= MOD;
	}

	result = (result + 1) % MOD;

	printf("%lld", result);
}