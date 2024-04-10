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
#define int			    ll

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 1e18 + 10;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, T[MAXN], X[MAXN];

inline bool in_mid(int l, int r, int x) {
	if (l > r) swap(l, r);
	return (l <= x) && (x <= r);
}

int solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> T[i] >> X[i];
	T[n] = INF;

	int tar = 0, bs = 0, pos = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		int ht = T[i + 1] - T[i];
		if (T[i] < bs) {
			if (in_mid(pos, tar, X[i]) && abs(pos - X[i]) <= ht) ans++;
			if (pos <= tar) pos = min(tar, pos + ht);
			else pos = max(tar, pos - ht);
		} else {
			if (abs(pos - X[i]) <= ht) ans++;
			bs = T[i] + abs(pos - X[i]);
			tar = X[i];
			if (pos <= tar) pos = min(tar, pos + ht);
			else pos = max(tar, pos - ht);
		}

	}

	cout << ans << endl;
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}