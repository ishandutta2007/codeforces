#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-10;
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

ll gcd(ll a, ll b){
	while(a != 0 && b != 0)
		a >= b ? a %= b : b %= a;
	return a + b;
}

ll solve_long(ll n, ll a, ll b){
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		if(i / a * a == i / b * b)
			ans++;
	}
	return ans;
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	ll n, a, b;
	cin >> n >> a >> b;

#ifdef LOCAL
	cout << solve_long(n, a, b) << endl;
#endif
	ll ans = 0;
	ll A = a;
	ans += min(n, min(a, b) - 1);
	a /= gcd(a, b);

	ll t = n / a;
	t /= b;

	if(t > 1){
		ans += (t - 1) * min(A, b);
	}
	if(t >= 1){
		ans += min(n - t * a * b + 1, min(A, b));
#ifdef LOCAL
		cout << t * a * b << " " << min(n - t * a * b + 1, min(A, b)) << endl;
#endif
	}

	ll r = gcd(n, ans);
	cout << ans / r << "/" << n / r << endl;

}