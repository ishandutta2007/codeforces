#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef short int si;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-9;
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
	while (x) {
		++kkkk;
		wwww[kkkk] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
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

const int MAX = 5e5 + 1;

int ar[MAX], n, k, _min, _max;

inline ll sum_suff(ll val) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (val <= ar[i]) {
			sum += ar[i] - val + 1;
		}
	}
	return sum;
}

inline ll sum_pref(ll val) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (val >= ar[i]) {
			sum += val - ar[i] + 1;
		}
	}
	return sum;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	read(n);
	read(k);
	for(int i = 1; i <= n; i++) {
		read(ar[i]);
	}

	_max = 0, _min = INT_MAX;
	for(int i = 1; i <= n; i++) {
		_max = max(_max, ar[i]);
		_min = min(_min, ar[i]);
	}

	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += ar[i] - _min;
	}

	if(k * 2 >= sum) {
		dbg {
			cout << "!" << endl;
		}
		cout << (sum % n == 0 ? 0 : 1) << endl;
		return 0;
	}

	int l = _min, r = _max;
	while(l < r) {
		int x = (l + r) >> 1;
		ll res = sum_pref(x);
		dbg cout << x << " " << res << endl;
		if(res > k) {
			r = x;
		} else {
			l = x + 1;
		}
	}

	int ans1 = l;

	l = _min, r = _max;
	while(l < r) {
		int x = (l + r + 1) >> 1;
		ll res = sum_suff(x);
		if(res > k) {
			l = x;
		} else {
			r = x - 1;
		}
	}

	int ans2 = l;

	dbg cout << ans1 << " " << ans2 << endl;
	ll ans = ans2 - ans1;
	if(ans < 0) {
		cout << (sum % n == 0 ? 0 : 1);
	} else {
		cout << ans2 - ans1 << endl;
	}
}