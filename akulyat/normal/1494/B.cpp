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

ll n, a, b, c, d;
vector<ll> v;
bool viv = false;

bool work(vector<ll> v, int tp) {
	for (int j = 0; j < 4; j++) {
		if (tp & 1) {
			v[j] -= 1;
			v[(j + 1) % 4] -= 1;
		}
		tp >>= 1;
	}
	for (auto i : v)
		if (i < 0 || i > n - 2)
			return false;
	return true;
}

void solve() {
	cin >> n;
	v.resize(4);
	for (auto &i : v)
		cin >> i;
	for (int j = 0; j < 1 << 4; j++)
		if (work(v, j)) {
			cout << "YES\n";
			return;
		}
	cout << "NO\n";
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