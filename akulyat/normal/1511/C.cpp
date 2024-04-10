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

ll n, q;
vector<ll> v, qr;
bool viv = false;


void solve() {
	cin >> n >> q;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	qr.resize(q);
	for (auto &i : qr)
		cin >> i, i--;

	vector<deque<int>> pl(50);
	for (int i = 0; i < n; i++) {
		pl[v[i]].push_back(i);
	}

	int nxt = 0;
	for (auto t : qr) {
		int p = pl[t].front();
		int ans = 0;
		for (int j = 0; j < 50; j++) {
			auto z = lower_bound(pl[j].begin(), pl[j].end(), p) - pl[j].begin();
			ans += z;
		}
		ans++;
		cout << ans << ' ';
		nxt--;
		pl[t].front() = nxt;
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}