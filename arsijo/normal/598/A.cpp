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
typedef pair<ll, ll> ii;
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

ll sum(ll n){
	return (n + 1) * n / 2;
}

ll div2(ll n){
	ll ans = 0;
	for(ll i = 1; i <= n; i <<= 1)
		ans += i;
	return ans;
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << sum(n) - 2 * div2(n) << endl;
	}

}