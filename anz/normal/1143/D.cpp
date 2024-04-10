#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long n, k, a, b;
long long ma[4] = { -1,-1,1,1 };
long long mb[4] = { -1,1,-1,1 };

int main() {
	scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
	long long minNum = 987654321987654321, maxNum = -1;
	for (long long i = 0; i <= n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			long long tmp;
			tmp = i*k + a*ma[j] + b*mb[j];
			if (tmp <= 0) tmp += n * k;

			long long g = gcd(n*k, tmp);
			long long r = n * k / g;
			if (minNum > r) minNum = r;
			if (maxNum < r) maxNum = r;
		}
		
	}

	printf("%lld %lld", minNum, maxNum);
}