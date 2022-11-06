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

ll n, k;
ll a[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	ll ans = a[n - 1] - a[0];

	int cL = 1, cR = 1;

	while (cL + cR <= n)
	{
		if (cL <= cR)
		{
			ll d = a[cL] - a[cL - 1];
			if (k <= d * cL)
			{
				ll cnt = k / cL;
				ans -= cnt;
				break;
			}

			ll cnt = d;

			k -= cnt * cL;
			cL++;
			ans -= cnt;
		}
		else
		{
			ll d = a[n - cR] - a[n - cR - 1];
			if (k <= d * cR)
			{
				ll cnt = k / cR;
				ans -= cnt;
				break;
			}

			ll cnt = d;
			k -= cnt * cR;
			cR++;
			ans -= cnt;
		}
	}

	cout << ans;
}