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

	int t; cin >> t;
	while(t--)
	{
		int c[3]; cin >> c[0] >> c[1] >> c[2];
		sort(c, c + 3);

		int ans = c[0];
		int d = c[2] - c[1];

		int tmp = min(c[0], d);
		c[2] -= tmp;

		int remain = c[0] - tmp;
		c[1] -= remain / 2;
		c[2] -= remain - remain / 2;

		ans += min(c[1], c[2]);
		cout << ans << '\n';
	}
}