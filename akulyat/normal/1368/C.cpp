#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
vector<pll> ans;
set<pll> d;
bool viv = false;

void draw(ll x, ll y) {
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			if (i != 1 || j != 1) {
				d.insert({x + i, y + j});
			}
}

void solve() {
	cin >> n;
	// cout << 8 + 7 * n << '\n';
	draw(-2, 0);
	for (int i = 0; i < n; i++) {
		int x = 2 * i;
		int y = -2;
		if (i & 1)
			y = 0;
		draw(x, y);
	}
	for (auto p : d)
		ans.push_back(p);
	cout << ans.size() << '\n';
	for (auto p : ans)
		cout << p.F << ' ' << p.S << '\n';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}