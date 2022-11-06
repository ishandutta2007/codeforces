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
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		ll a[301];
		for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
		sort(a, a + n);
		ll ans = a[0] * a[n - 1];

		int cnt = 0;
		for (ll i = 2; i*i <= ans; i++)
			if (ans % i == 0)
			{
				if (i*i == ans) cnt++;
				else cnt += 2;
			}

		bool flag = true;

		if (cnt != n) flag = false;
		else
		{
			for (int i = 0; i <= n / 2; i++)
			{
				ll left = a[i];
				ll right = a[n - 1 - i];
				if (left*right != ans)
				{
					flag = false;
					break;
				}
			}
		}

		
		if (flag) printf("%lld\n", ans);
		else printf("-1\n");
	}
}