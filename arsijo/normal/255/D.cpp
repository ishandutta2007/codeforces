#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-17;
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
char ccc;
inline void read(int &n) {
	n = 0;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		n = n * 10 + ccc - '0';
	}
}
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

ll n, x, y, c;

inline ll sum(ll n){
	return n * (n + 1) / 2;
}

inline ll solve_2(ll d, ll len){
	if(len <= d)
		return 0;
	len -= d;
	ll ans = sum(len - 1) * 2 + len;
	//cout << "! " << ans << endl;
	return ans;
}

inline ll solve_3(ll a, ll b, ll len){
	//cout << a << " " << b << endl;
	if(a + b < len){
		ll ans = sum(len - (a + b));
		//cout << "? " << ans << endl;
		return ans;
	}
	return 0;
}

ll check(ll t){
	ll ans = 1 + (t != 0 ? (4 + 4 * t) * t / 2 : 0);
	t++;
	ans -= solve_2(n + 1 - x, t) + solve_2(n + 1 - y, t);
	ans -= solve_2(x, t) + solve_2(y, t);
	ans += solve_3(n + 1 - x, n + 1 - y, t) + solve_3(n + 1 - y, x, t);
	ans += solve_3(x, y, t) + solve_3(y, n + 1 - x, t);
	t--;
	return ans;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> n >> x >> y >> c;

	ll l = 0, r = n + n;
	while(l < r){
		ll x = (l + r) >> 1;
		if(check(x) >= c)
			r = x;
		else
			l = x + 1;
	}

	cout << l << endl;

}