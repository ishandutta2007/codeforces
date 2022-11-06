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

	int t; cin >> t;
	while (t--)
	{
		ll a, b, c, n; cin >> a >> b >> c >> n;
		if ((a + b + c + n) % 3)
		{
			cout << "NO\n";
			continue;
		}

		ll div = (a + b + c + n) / 3;
		if (a > div || b > div || c > div) cout << "NO\n";
		else cout << "YES\n";
	}
}