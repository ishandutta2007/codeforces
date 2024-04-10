#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, x, y, cnt;
vector<ll> c;
bool viv = false;

void make_less() {
	bool cont = false;
	for (int i = 0; i < 6; i++) {
		int j = (i - 1 + 6) % 6;
		int u = (i + 1 + 6) % 6;
		if (c[j] + c[u] < c[i])
			c[i] = min(c[i], c[j] + c[u]), cont = true;
	}
	if (!cont)
		return;
	cnt++;
	make_less();
}

void solve() {
	cin >> x >> y;
	c.resize(6);
	cnt = 0;
	for (auto &i : c)
		cin >> i;
	for (int i = 0; i < 100; i++)
		make_less();
	if (viv) 
		cout << cnt << " made " << endl;

	ll ans = 0;
	if (x >= 0) {
		if (y >= 0) {
			if (x <= y) {
				ans = x * c[0] + (y - x) * c[1];
			} else {
				ans = y * c[0] + (x - y) * c[5];
			}
		} else {
			ans = (-y) * c[4] + x * c[5];
		}
	} else {
		if (y >= 0) {
			ans = y * c[1] + (-x) * c[2];
		} else {
			if (x <= y) {
				ans = (-y) * c[3] + (y - x) * c[2];
			} else {
				ans = (-x) * c[3] + (x - y) * c[4];
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}