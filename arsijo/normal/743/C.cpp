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
ll MOD = 1e9 + 7;
const ld E = 1e-9;
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
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ii operator+(ii a, ii b) {
	ll d = a.second * b.second;
	ll c = a.first * b.second + b.first * a.second;
	ll g = __gcd(c, d);
	return make_pair(c / g, d / g);
}

bool operator==(ii a, ii b) {
	return (a.first == b.first && a.second == b.second);
}

int get(int n) {
	ii a = make_pair(2, n);
	if (n % 2 == 0) {
		a = make_pair(1, n / 2);
	}
	ii b = make_pair(1, 7) + make_pair(1, 8);
	b = b + make_pair(1, 56);
	const int M = 1000;
	for (int i = 2; i <= n; i++) {
		for (int j = i + 1; j <= M; j++) {
			if (1) {
				ii b = make_pair(1, i) + make_pair(1, j);
				for (int z = j + 1; z <= M; z++) {
					if (b + make_pair(1, z) == a) {
						return i;
					}
				}
			} else {
				ll c = n * 1LL * i * j;
				ll d = 2 * i * 1LL * j - n * 1LL * i - n * 1LL * j;
				if (c > 0 && d > 0 && c % d == 0) {
					c /= d;
					if (c != i && c != j && c <= 1e9) {
						ii b = make_pair(1, i) + make_pair(1, j);
						assert(b + make_pair(1, c) == a);
						cout << i << " " << j << " " << c << endl;
						return 0;
					}
				}
			}
		}
	}
	return -1;
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

	int n;
	cin >> n;
	if(n == 1) {
		cout << -1 << endl;
		return 0;
	}
	if(n == 2) {
		cout << "2 3 6" << endl;
		return 0;
	}
	ii a = make_pair(2, n);
	if(n % 2 == 0) {
		a = make_pair(1, n / 2);
	}
	ii b = make_pair(1, 7) + make_pair(1, 8);
	b = b + make_pair(1, 56);
	const int M = 100000000;
	for(int i = n / 2 + 1; i <= n / 2 + 1; i++) {
		for(int j = 1; j <= M; j++) {
			if(i == j)
				continue;
			if(0) {
				ii b = make_pair(1, i) + make_pair(1, j);
				for(int z = 1; z <= M; z++) {
					if(z != i && z != j && b + make_pair(1, z) == a) {
						cout << i << " " << j << " " << z << endl;
					}
				}
			} else {
				ll c = n * 1LL * i * j;
				ll d = 2 * i * 1LL * j - n * 1LL * i - n * 1LL * j;
				if(c > 0 && d > 0 && c % d == 0) {
					c /= d;
					if(c != i && c != j && c <= 1e9) {
						ii b = make_pair(1, i) + make_pair(1, j);
						cout << i << " " << j << " " << c << endl;
						return 0;
					}
				}
			}
		}
	}

}