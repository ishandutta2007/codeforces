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
#define x first
#define y second
typedef unsigned long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef ii point;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-8;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 2000;
#else
const ll MAX = 2000;
#endif

ll get(ll n, ll a) {
	ll ans = 0;
	ll k = a;
	while (k <= n) {
		ans += n / k;
		k *= a;
	}
	return ans;
}

ll solve(ll n) {
	ll a = n * 2;
	ll b = n;
	ll ans = 1;
	bool prime[n * 2];
	ms(prime);
	for (ll i = 2; i <= a; i++) {
		if (!prime[i]) {
			int j = get(a, i) - get(b, i) * 2;
			for (int q = 0; q < j; q++) {
				ans = (ans * i)mod;
			}
			for(ll j = i * i; j <= a; j += i)
				prime[j] = true;
		}
	}
	return ans;
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;
	cout << solve(n + 1) - 1;

}