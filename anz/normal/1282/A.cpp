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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		ll a, b, c, r; cin >> a >> b >> c >> r;
		if (a > b) swap(a, b);
		ll cl = c - r, cr = c + r;
		cr = min(cr, b);
		cl = max(cl, a);

		ll m = max(cr - cl, 0ll);
		cout << b - a - m << '\n';
	}
}