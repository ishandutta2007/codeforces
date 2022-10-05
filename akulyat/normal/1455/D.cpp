#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef int      ll;
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

ll n, x;
vector<ll> v;
bool viv = false;

bool good(vector<ll> &v) {
	ll n = v.size();
	for (int i = 1; i < n; i++)
		if (v[i - 1] > v[i])
			return false;
	return true;
}

void solve() {
	cin >> n >> x;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	if (good(v))
		return void(cout << 0 << '\n');
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (x < v[i]) {
			swap(x, v[i]), ans++;
			if (good(v))
				return void(cout << ans << '\n');
		}
	if (!good(v))
		return void(cout << -1 << '\n');
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