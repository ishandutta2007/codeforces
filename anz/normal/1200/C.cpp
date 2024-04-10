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
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll n, m, q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> q;

	ll g = gcd(n, m); //g  

	ll a_size = n / g;
	ll b_size = m / g;

	for (int i = 0; i < q; i++)
	{
		ll sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;

		ll a_dir=-1, b_dir=-1;
		if (sx == 1)
			a_dir = (sy - 1) / a_size;
		else
			a_dir = (sy - 1) / b_size;

		if (ex == 1)
			b_dir = (ey - 1) / a_size;
		else
			b_dir = (ey - 1) / b_size;

		if (a_dir == b_dir) cout << "YES\n";
		else cout << "NO\n";
	}
}