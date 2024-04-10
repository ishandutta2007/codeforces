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

ll n, a, b;
vector<ll> va, vb;
bool viv = false;


void solve() {
	cin >> a >> b >> n;
	va.resize(n);
	vb.resize(n);
	for (auto &i : va)
		cin >> i, i--;
	for (auto &i : vb)
		cin >> i, i--;

	vector<ll> cnta(a, 0);
	vector<ll> cntb(b, 0);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += i;
		ans -= cnta[va[i]];
		ans -= cntb[vb[i]];
		cnta[va[i]]++;
		cntb[vb[i]]++;
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