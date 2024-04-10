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

int main()
{
	int t; cin >> t;
	while (t--)
	{
		ll s; cin >> s;
		ll ans = 0;
		while (s >= 10)
		{
			ll tmp = s / 10 * 10;
			ans += tmp;
			s = s - tmp + tmp / 10;
		}
		ans += s;
		cout << ans << '\n';
	}
}