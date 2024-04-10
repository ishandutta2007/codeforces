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

ll n, l;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> l;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ll nl = 0, nr = n - 1;
	ld lc = 0, rc = l;
	ll ls = 1, rs = 1;
	ld ans = 0;
	while (nl <= nr) {
		ld needl = v[nl] - lc;
		ld needr = rc - v[nr];
		ld timel = needl / ls;
		ld timer = needr / rs;
		if (timel <= timer) {
			lc += timel * ls;
			rc -= timel * rs;
			ls++;
			nl++;
			ans += timel;
		} else {
			lc += timer * ls;
			rc -= timer * rs;
			rs++;
			nr--;
			ans += timer;
		}
	}
	ld timec = (rc - lc) / (ls + rs);
	ans += timec;
	lc += timec * ls;
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);	
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}