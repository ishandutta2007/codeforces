#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
template<typename T> T sqr(T a) {
	return a * a;
}
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-10;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define db 1
#else
#define db 0
#endif
#define dbg if(db) cout

ll get(ll n, ll a, ll b, ll c, ll q) {
	ll left = n - q * (b - c);
	return q + max(0LL, left) / a;
}

ll solve_long(ll n, ll a, ll b, ll c) {
	ll ans = 0;
	for (ll i = 0; true; i++) {
		ans = max(ans, n / a + i);
		if (n < b)
			break;
		n -= b - c;
	}
	return ans;
}

ll solve(ll n, ll a, ll b, ll c) {
	if (n < b) {
		return n / a;
	}
	ll l = 0, r = (n - b) / (b - c) + 1;
	return max(get(n, a, b, c, l), get(n, a, b, c, r));
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
	srand(time(NULL));
#ifdef LOCAL
	input;
#endif

	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	cout << solve(n, a, b, c);

}