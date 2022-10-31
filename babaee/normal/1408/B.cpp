#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN] = {0};

ll solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	if (v.front() == v.back()) return cout << 1 << endl, 0;
	if (k == 1) return cout << -1 << endl, 0;
	set<ll> st;
	for (ll u : v) if (u != 0) st.insert(u);
	if (v.front() == 0) cout << ll(ceil(ld(st.size()) / ld(k - 1))) << endl;
	else {
		if (st.size() <= k) cout << 1 << endl;
		else cout << 1 + ll(ceil(ld(st.size() - k) / ld(k - 1))) << endl;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}