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

	ll u, v; cin >> u >> v;
	if (u > v)
	{
		cout << -1;
		return 0;
	}
	if (u == v)
	{
		if (u == 0)
			cout << 0;
		else
			cout << "1\n" << u;
		return 0;
	}
	if ((v - u) % 2)
	{
		cout << -1;
		return 0;
	}

	ll ans1 = u;
	ll ans2 = (v - u) / 2;

	if ((ans1 ^ ans2) == (ans1 + ans2))
	{
		cout << "2\n";
		cout << ans1 + ans2 << ' ' << ans2;
	}
	else
	{
		cout << "3\n";
		cout << ans1 << ' ' << ans2 << ' ' << ans2;
	}
}