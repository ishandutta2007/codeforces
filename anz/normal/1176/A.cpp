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
	int q;
	scanf("%d", &q);
	while (q--)
	{
		ll n;
		scanf("%lld", &n);
		int ans = 0;
		while (n != 1)
		{
			if (n % 5 == 0)
				n /= 5, n *= 4;
			else if (n % 3 == 0)
				n /= 3, n *= 2;
			else if (n % 2 == 0)
				n /= 2;
			else
			{
				ans = -1;
				break;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
}