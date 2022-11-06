#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
ll w[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m;
		int c1 = -1, c2 = -1;
		ll v1 = 10001, v2 = 10001;

		ll sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			sum += w[i];

			if (w[i] < v2)
			{
				v2 = w[i];
				c2 = i;

				if (v1 > v2)
				{
					swap(c1, c2);
					swap(v1, v2);
				}
			}
		}

		if (n == 2 || m < n)
		{
			cout << "-1\n";
			continue;
		}

		ll ans = sum * 2;
		ll remain = m - n;
		ans += remain * (v1 + v2);

		cout << ans << '\n';
		for (int i = 1; i < n; i++) cout << i << ' ' << i + 1 << '\n';
		cout << n << ' ' << "1\n";

		for (int i = 0; i < remain; i++)
			cout << c1 << ' ' << c2 << '\n';
	}
}