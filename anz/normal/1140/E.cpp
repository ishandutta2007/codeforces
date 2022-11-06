#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

long long n, k;
long long a[200001];
long long cacheDiff[200001];
long long cacheSame[200001];

const long long MOD = 998244353;

long long cntDiff(int l);
long long cntSame(int l)
{
	long long& ret = cacheSame[l];
	if (ret != -1) return ret;
	if (l == 0) return 0;
	if (l & 1)
	{
		long long t1 = cntSame(l / 2) * cntSame(l / 2);
		t1 %= MOD;
		long long t2 = ((k - 1)*cntDiff(l / 2)%MOD)*cntDiff(l / 2);
		t2 %= MOD;
		return ret = (t1 + t2) % MOD;
	}
	else
	{
		return ret = ((k - 1)*cntDiff(l - 1)) % MOD;
	}
}

long long cntDiff(int l)
{
	long long& ret = cacheDiff[l];
	if (ret != -1) return ret;
	if (l == 0) return 1;
	if (l & 1)
	{
		long long t1 = 2 * cntSame(l / 2)*cntDiff(l / 2);
		t1 %= MOD;
		long long t2 = ((k - 2)*cntDiff(l / 2)%MOD)*cntDiff(l / 2);
		t2 %= MOD;
		return ret = (t1 + t2) % MOD;
	}
	else
	{
		long long t1 = cntSame(l - 1);
		long long t2 = (k - 2)*cntDiff(l - 1);
		t2 %= MOD;
		return ret = (t1 + t2) % MOD;
	}
}

int main() {
	memset(cacheDiff, -1, sizeof(cacheDiff));
	memset(cacheSame, -1, sizeof(cacheSame));

	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	bool isEmpty = true;
	long long odd = 1, even = 1;
	long long start = -1;
	long long length = 0;
	for (int i = 0; i < n; i += 2)
	{
		if (a[i] != -1)
		{
			if (i + 2 < n && a[i] == a[i + 2])
			{
				printf("0");
				return 0;
			}

			if (length != 0)
			{
				if (isEmpty)
				{
					long long tmp = 0;
					tmp += ((k - 1)*cntDiff(length - 1)) % MOD;
					tmp %= MOD;
					tmp += cntSame(length - 1);
					tmp %= MOD;

					odd *= tmp;
					odd %= MOD;
				}
				else
				{
					long long tmp = 0;
					if (start == a[i])
						tmp += cntSame(length);
					else
						tmp += cntDiff(length);
					tmp %= MOD;
					odd *= tmp;
					odd %= MOD;
				}
			}
			start = a[i];
			length = 0;
			isEmpty = false;
		}
		else
			length++;
	}
	if (length != 0)
	{
		if (isEmpty)
		{
			if (length == 1)
			{
				odd *= k;
				odd %= MOD;
			}
			else
			{
				long long tmp = 0;
				tmp += (((k*k - k) % MOD)*cntDiff(length - 2)) % MOD;
				tmp %= MOD;
				tmp += (k*cntSame(length - 2))%MOD;
				tmp %= MOD;

				odd *= tmp;
				odd %= MOD;
			}
		}
		else
		{
			long long tmp = 0;
			tmp += ((k - 1)*cntDiff(length - 1)) % MOD;
			tmp %= MOD;
			tmp += cntSame(length - 1);
			tmp %= MOD;

			odd *= tmp;
			odd %= MOD;
		}

	}

	length = 0;
	isEmpty = true;
	for (int i = 1; i < n; i += 2)
	{
		if (a[i] != -1)
		{
			if (i + 2 < n && a[i] == a[i + 2])
			{
				printf("0");
				return 0;
			}
			if (length != 0)
			{
				if (isEmpty)
				{
					long long tmp = 0;
					tmp += ((k - 1)*cntDiff(length - 1)) % MOD;
					tmp %= MOD;
					tmp += cntSame(length - 1);
					tmp %= MOD;

					odd *= tmp;
					odd %= MOD;
				}
				else
				{
					long long tmp = 0;
					if (start == a[i])
						tmp += cntSame(length);
					else
						tmp += cntDiff(length);
					tmp %= MOD;
					odd *= tmp;
					odd %= MOD;
				}
			}
			start = a[i];
			length = 0;
			isEmpty = false;
		}
		else
			length++;
	}
	if (length != 0)
	{
		if (isEmpty)
		{
			if (length == 1)
			{
				odd *= k;
				odd %= MOD;
			}
			else
			{
				long long tmp = 0;
				tmp += (((k*k - k)%MOD)*cntDiff(length - 2)) % MOD;
				tmp %= MOD;
				tmp += (k*cntSame(length - 2)) % MOD;
				tmp %= MOD;

				odd *= tmp;
				odd %= MOD;
			}
		}
		else
		{
			long long tmp = 0;
			tmp += ((k - 1)*cntDiff(length - 1)) % MOD;
			tmp %= MOD;
			tmp += cntSame(length - 1);
			tmp %= MOD;

			odd *= tmp;
			odd %= MOD;
		}

	}

	long long result = odd % MOD;
	printf("%lld", result);
}