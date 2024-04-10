#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-11;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
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

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int ar[n + 2];
	ms(ar);
	for(int i = 1; i <= n; i++)
		cin >> ar[i];

	string s;
	cin >> s;

	ll pref1[n + 2];
	ms(pref1);
	ll pref2[n + 2];
	ms(pref2);
	for(int i = 1; i <= n; i++){
		pref1[i] = pref1[i - 1];
		pref2[i] = pref2[i - 1];
		if(s[i - 1] == 'A')
			pref1[i] += ar[i];
		else
			pref2[i] += ar[i];
	}

	ll suff1[n + 2];
	ms(suff1);
	ll suff2[n + 2];
	ms(suff2);

	for(int i = n; i >= 1; i--){
		suff1[i] = suff1[i + 1];
		suff2[i] = suff2[i + 1];
		if(s[i - 1] == 'A')
			suff1[i] += ar[i];
		else
			suff2[i] += ar[i];
	}

	ll ans = 0;

	for(int i = 1; i <= n + 1; i++){
		ll a = max(pref2[i - 1] + suff2[i], max(pref1[i - 1] + suff2[i], pref2[i - 1] + suff1[i]));
		ans = max(ans, a);
	}
	cout << ans;

}