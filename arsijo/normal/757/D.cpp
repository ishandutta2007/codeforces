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

const int MAX = 20;
const int MAX_N = 75;

int dp[MAX_N + 1][1 << MAX];

inline void add(int &a, int b) {
	if(b < 0){
		b += MOD;
	}
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int n;
string s;

int solve_long() {
	for (int i = 1; i <= n; i++) {
		int ind = 0;
		int now = 0;
		for (int j = 1; j <= i; j++, ind++) {
			if (s[i - j + 1] == '1') {
				if(ind > 10)
					break;
				now += (1 << ind);
			}
			if (now && now <= MAX) {
				for (int z = 0; z < (1 << MAX); z++) {
					add(dp[i][z | (1 << (now - 1))], dp[i - j][z]);
				}
				add(dp[i][1 << (now - 1)], 1);
			}
			if (now > MAX) {
				break;
			}
		}
		if (0)
			for (int z = 0; z < (1 << MAX); z++) {
				if (dp[i][z]) {
					cout << i << " " << z << " " << dp[i][z] << endl;
				}
			}
	}
	int res = 0;
	for (int i = 1; i <= MAX; i++) {
		int mask = (1 << i) - 1;
		for (int j = 1; j <= n; j++) {
			add(res, dp[j][mask]);
		}
	}
	return res;
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

	cin >> n >> s;
	s = "!" + s;

	int a = solve_long();
	cout << a << endl;

}