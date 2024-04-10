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

ll n, r;
set <ll> s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
	{
		s.clear();
		cin >> n >> r;
		for (int i = 0; i < n; i++)
		{
			ll x; cin >> x;
			s.insert(x);
		}

		int ans = 0;

		ll d = 0;
		auto it = s.end(); it--;
		while (true)
		{
			ll cm = (*it) - d;
			if (cm <= 0) break;

			ans++;
			if (it == s.begin()) break;
			it--;
			d += r;
		}

		cout << ans << "\n";
	}
}