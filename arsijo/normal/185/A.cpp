#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define def(f) make(#f);
#define y1 dads
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
const ld E = 1e-9;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

ll _pow(ll n, ll m, ll MOD){
	if(m == 1)
		return n mod;
	ll ans = _pow(n, m >> 1, MOD);
	ans = (ans * ans) mod;
	if(m & 1)
		ans = (ans * n) mod;
	return ans;
}

int main() {

	cout.precision(11);

	cout << fixed;
	sync;
	srand(time(NULL));
#ifdef LOCAL
	input;
#else

#endif

	ll n;
	cin >> n;
	if(n == 0){
		cout << 1;
		return 0;
	}
	ll q = _pow(2, n, MOD);

	ll w = (q * (q + 1)) mod;
	w = (w * _pow(2, MOD - 2, MOD)) mod;
	cout << w << endl;

}