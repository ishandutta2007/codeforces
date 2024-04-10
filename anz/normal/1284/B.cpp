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

ll n;
ll minv[1000001], maxv[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	ll ans = 0;
	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int cmin = 987564321, cmax = -1;
		int l; cin >> l;

		bool flag = false;
		for (int i = 0; i < l; i++)
		{
			int s; cin >> s;
			if (cmin < s) flag = true;
			cmin = min(cmin, s);
			cmax = max(cmax, s);
		}

		if (flag)
		{
			cnt++;
		}
		else
		{
			minv[cmin]++;
			maxv[cmax]++;
		}
	}
	for (int i = 1000000; i >= 0; i--) maxv[i] += maxv[i + 1];

	for (int i = 0; i <= 1000000; i++)
	{
		ans += minv[i] * maxv[i + 1];
	}

	ans += cnt * cnt;
	ans += cnt * (n - cnt) * 2;
	cout << ans;
}