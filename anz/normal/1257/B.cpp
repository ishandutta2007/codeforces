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
		ll x, y; cin >> x >> y;
		if (x == 1)
		{
			if (y == 1) cout << "YES\n";
			else cout << "NO\n";
		}
		else if (x == 2 || x == 3)
		{
			if (y <= 3) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "YES\n";
	}
}