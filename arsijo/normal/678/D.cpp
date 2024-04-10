#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
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
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ll a, b, x, n;

inline ll next(ll x){
	return (x * a + b) mod;
}

ll solve_long(){
	ll x = ::x;
	for(int i = 0; i < n; i++)
		x = next(x);
	return x;
}

ll multy(ll n, ll m){
	ll ans = (m == 0 ? 0 : m & 1 ? n + multy(n, m - 1) : 2 * multy(n, m >> 1)) % MOD;
	return ans;
}

template<typename T> inline T sqr(T t) {
	return multy(t, t);
}

ll _pow(ll n, ll m){
	ll ans = (m == 0 ? 1 : m & 1 ? multy(n, _pow(n, m - 1)) : sqr(_pow(n, m >> 1))) % MOD;
	//cout << n << " " << m << " " << ans << endl;
	return ans;
}



ll solve_quick(){
	if(n == 0)
		return x;
	if(n == 1){
		return (multy(x, a) + b) % MOD;
	}
	if(a == 1){
		return (x + multy(n, b)) % MOD;
	}
	ll ans = multy(x, _pow(a, n)) % MOD;
	ll w = _pow(a, n) - 1;
	if(w < 0)
		w += MOD;
	w = multy(w, b) % MOD;
	w = multy(w, _pow(a - 1, MOD - 2)) % MOD;
	return (ans + w) % MOD;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> a >> b >> n >> x;

	cout << solve_quick() << endl;

}