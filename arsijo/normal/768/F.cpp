#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-7;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#define M_PI acos(-1)
#define remove tipa_remove
#define next tipa_next
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
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
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
	kkkk = 0;
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
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
}

#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 2e5 + 10;

ll _pow(ll a, ll b) {
	return (b == 0 ? 1 : b & 1 ? a * _pow(a, b - 1) : sqr(_pow(a, b >> 1)))
			% MOD;
}

ll fac[MAX], afac[MAX];

ll c(int n, int m) {
	ll ans = fac[n];
	ans = (ans * afac[m]) % MOD;
	ans = (ans * afac[n - m]) % MOD;
	return ans;
}

ll f(int a, int b, int c) {
	ll ans = fac[a + b + c];
	ans = (ans * afac[a]) % MOD;
	ans = (ans * afac[b]) % MOD;
	ans = (ans * afac[c]) % MOD;
	return ans;
}

ll a(ll n, ll m){
	if(n < 0 || m < 0)
		return 0;
	return c(n + m, n);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	fac[0] = fac[1] = 1;
	for(int i = 2; i < MAX; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}

	for(int i = 0; i < MAX; i++) {
		afac[i] = _pow(fac[i], MOD - 2);
	}

	int n, m, h;
	cin >> n >> m >> h;

	if(m == 0 || h == 0){
		cout << 1 << endl;
		return 0;
	}

	ll q = c(n + m, n);

	ll p = 0;

	for(int i = 1; i * (h + 1) <= m; i++) {
		ll w = a(i, n - i + 1);
		//cout << i << " " << w << endl;
		ll add = m - i * (h + 1);
		w *= a(i - 1, add);
		w %= MOD;
		p += w;
		p %= MOD;
	}

	if(p < 0){
		p += MOD;
	}
	p %= MOD;

	p *= _pow(q, MOD - 2);
	p %= MOD;
	cout << p << endl;

}