#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <cmath>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		ll n, k;
		scanf("%lld%lld", &n, &k);
		ll cnt = 0;
		while (n)
		{
			if (n < k)
			{
				cnt += n;
				n = 0;
			}
			else
			{
				if (n % k == 0)
				{
					n /= k;
					cnt++;
				}
				else
				{
					ll tmp = n / k * k;
					cnt += n - tmp;
					n -= (n - tmp);
				}
			}
		}
		printf("%lld\n", cnt);
	}
}