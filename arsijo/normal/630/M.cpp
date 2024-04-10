#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
template<typename T> T sqr(T t) {
	return t * t;
}
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define input _read("input.txt")
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ll get(ll n){
	if(n < 0){
		n = 360 + n;
	}
	return min(360 - n, n);
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ll n;
	cin >> n;

	if(n < 0){
		n = (-n) % 360;
		n = (360 - n) % 360;
	}
	n %= 360;

	ll best = get(n);
	ll ans = 0;

	for(ll i = 1; i <= 10; i++){
		n = (n + 360 - 90) % 360;
		ll w = get(n);
		if(best > w){
			best = w;
			ans = i;
		}
	}

	cout << ans;

}