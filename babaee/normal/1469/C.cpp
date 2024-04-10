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

ll n, k, H[MAXN];

inline int solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> H[i];
	}

	ll mn = H[1], mx = H[1];
	for (int i = 2; i <= n; i++) {
		ll h = H[i];
		ll tmn = h, tmx = h + k - 1;
		if (tmn > mx + k - 1 || tmx + k - 1 < mn) return cout << "NO" << endl, 0;
		mx = min(tmx, mx + k - 1);
		mn = max(tmn, mn - k + 1);
	}

	if (H[n] >= mn && H[n] <= mx) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve(); 
	return 0;
}