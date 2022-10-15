#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e6 + 1;
#endif

ll check(ll a, ll bc, ll l) {
	if (a < bc)
		return 0;
	ll g = min(a - bc, l);
	return (g + 1) * (g + 2) / 2;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	ll a, b, c, l;
	cin >> a >> b >> c >> l;
	ll ans = (l + 1) * (l + 2) * (l + 3) / 6;
	for(ll i = 0; i <= l; i++) {
		ans -= check(a + i, b + c, l - i) + check(b + i, a + c, l - i) + check(c + i, a + b, l - i);
	}
	cout << ans;

}