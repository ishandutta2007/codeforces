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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		ll r, b, k; cin >> r >> b >> k;
		if (r > b) swap(r, b);
		ll g = gcd(r, b);
		r /= g, b /= g;

		ll res;
		if (r == 1) res = b - 1;
		else res = (b - 2) / r + 1;
		if (res >= k) cout << "REBEL\n";
		else cout << "OBEY\n";
	}
}