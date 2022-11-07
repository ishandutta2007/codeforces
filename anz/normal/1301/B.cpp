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
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		int cnt = 0;

		bool flag = true;
		ll minv = numeric_limits<ll>::max();
		ll maxv = -1;
		ll dif = 0;

		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			if (a[i] == -1)
			{
				if (i && a[i-1] != -1)
				{
					minv = min(minv, a[i - 1]);
					maxv = max(maxv, a[i - 1]);
				}
				if (i + 1 < n && a[i + 1] != -1)
				{
					minv = min(minv, a[i + 1]);
					maxv = max(maxv, a[i + 1]);
				}
			}
			else
			{
				flag = false;
				if (i + 1 < n && a[i + 1] != -1)
				{
					ll d = a[i] - a[i + 1]; if (d < 0) d = -d;
					dif = max(dif, d);
				}
			}
		}

		if (flag)
		{
			cout << "0 0\n";
			continue;
		}

		ll ans = (minv + maxv) / 2;
		dif = max(dif, max(maxv - ans, ans - minv));

		cout << dif << ' ' << ans << '\n';
	}
}