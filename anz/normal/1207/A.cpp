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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int b, p, f; cin >> b >> p >> f;
		int h, c; cin >> h >> c;

		int ans = 0;
		if (h > c)
		{
			int ham = min(p, b / 2);
			ans += h * ham;
			b -= ham * 2;

			int chi = min(f, b / 2);
			ans += c * chi;
		}
		else
		{
			int chi = min(f, b / 2);
			ans += c * chi;
			b -= chi * 2;

			int ham = min(p, b / 2);
			ans += h * ham;
		}
		cout << ans << "\n";
	}
}