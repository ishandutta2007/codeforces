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
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> q;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ll cnt[2];
	cnt[0] = cnt[1] = 0;
	for (auto i : v)
		cnt[i]++;

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int pl;
			cin >> pl;
			pl--;
			cnt[v[pl]]--;
			v[pl] = 1 - v[pl];
			cnt[v[pl]]++;
		} else {
			int k;
			cin >> k;
			if (cnt[1] >= k)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
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