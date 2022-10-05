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

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	int a = -1, b = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		int val = v[i];
		if (i + 1 < n && (v[i + 1] == a || v[i + 1] == b)) {
			if (v[i + 1] == a) {
				if (a != val)
					a = val, ans++;
			} else {
				if (b != val)
					b = val, ans++;				
			}
		} else {
			if (a != val)
				a = val, ans++;
			else 
				if (b != val)
					b = val, ans++;				
		}
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
// 	cin >> t;
	while (t--)
		solve();

	return 0;
}