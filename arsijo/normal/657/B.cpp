#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-8;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const ll INF = 1e18;

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n;
	ll k;
	cin >> n >> k;

	ll ar[n + 1];
	ll suff[n + 1], pref[n + 1];
	for(int i = 0; i <= n; i++) {
		cin >> ar[i];
	}
	for(int i = 0; i <= n; i++)
	suff[i] = pref[i] = LONG_LONG_MAX;

	for(int i = n; i >= 0; i--) {
		suff[i] = (i == n ? 0 : suff[i + 1]) * 2 + ar[i];
		if(abs(suff[i]) > INF){
			suff[i] = LONG_LONG_MAX;
			break;
		}
	}

	ll sum = 0;
	dbg {
		for(int i = 0; i <= n; i++) {
			cout << suff[i] << " ";
		}
		cout << endl;
	}
	int ans = 0;

	for(int i = 0; i <= n; i++) {
		if(abs(sum) % 2 == 1)
		break;
		sum /= 2;
		if(!(i != n && suff[i + 1] == LONG_LONG_MAX)) {
			ll val = (i == n ? 0 : -suff[i + 1] * 2) + (i == 0 ? 0 : -sum);
			if(abs(val) <= k && (i != n || val != 0))
			ans++;
			dbg cout << val << endl;
		}
		sum += ar[i];
	}

	cout << ans << endl;

}