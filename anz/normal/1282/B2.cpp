#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, p, k;
ll a[200001];
ll psum[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> p >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			psum[i] = a[i];
			if (i) psum[i] += psum[i - 1];
		}

		int ans = 0;
		for (int i = 0; i < k; i++)
		{
			int res = 0;
			ll cp = p;
			for (int j = i; j + k <= n; j += k)
			{
				if (a[j + k - 1] > cp) break;
				cp -= a[j + k - 1];
				res += k;
			}

			int idx = upper_bound(psum, psum + i, cp) - psum;

			res += idx;

			ans = max(ans, res);
		}
		cout << ans << '\n';
	}
}