#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
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

const int MAX = 1e5 + 10;

ll f(ll n) {
	ll ans = n;
	int s = sqrt(n);
	for (int i = 2; i <= s; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			ans -= ans / i;
		}
	if (n > 1)
		ans -= ans / n;
	return ans;
}

ll f(ll n, vector<ll> v) {
	ll ans = n;
	for (ll i : v)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			ans -= ans / i;
		}
	if (n > 1)
		ans -= ans / n;
	return ans;
}

ll g(ll n) {
	return n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			ans += f(i);
		}
	}
	return ans;
}

ll g2(ll n) {
	ll m = n;
	vector<ll> v;
	int s = sqrt(n);
	for (int i = 2; i <= s; i++) {
		if(n % i == 0){
			v.push_back(i);
			while(n % i == 0){
				n /= i;
			}
		}
	}
	if(n != 1){
		v.push_back(n);
	}
	n = m;
	ll ans = 0;
	for(int i = 1; i <= s; i++){
		if(n % i == 0){
			ans += f(i, v);
			if(i * 1LL * i != n){
				ans += f(n / i, v);
			}
		}
	}
	return ans;
}

int F(int n, int k) {
	if (k == 1) {
		return f(g(n));
	}
	if (k & 1) {
		return f(F(n, k - 1));
	} else {
		return g(F(n, k - 1));
	}
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

	ll n, k;
	cin >> n >> k;

	for(ll i = 1; i <= k && n > 0; i++){
		if(i & 1){
			ll m = n;
			n = f(n);
			if(m == n)
				break;
		}
	}

	cout << n % MOD << endl;

}