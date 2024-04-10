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
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;

	ll ans = 0;
	if (e > f)
	{
		ll first = min(a, d);
		ans += first * e;
		d -= first;
		ll second = min(min(b, c), d);
		ans += second * f;
		cout << ans;
	}
	else
	{
		ll second = min(min(b, c), d);
		ans += second * f;
		d -= second;
		ll first = min(a, d);
		ans += first * e;
		cout << ans;
	}
}