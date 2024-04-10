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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int c, m, x; cin >> c >> m >> x;

		int ans = min(min(c, m), x);
		c -= ans, m -= ans, x -= ans;

		int cm = min(c, m);
		c -= cm, m -= cm;
		
		int tmp;
		if (c) tmp = min(c, cm), c -= tmp;
		else tmp = min(m, cm), m -= tmp;

		ans += tmp;
		cm -= tmp;
		ans += (cm*2) / 3;
		cout << ans << "\n";
	}
}