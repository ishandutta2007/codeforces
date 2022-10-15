#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
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

const int MAX = 1004;
int dp[MAX][MAX][9];
int dp2[9][1 << 8];

inline void upd(int &a, int b) {
	if (a) {
		a = min(a, b);
	} else {
		a = b;
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

	int n;
	cin >> n;

	int ar[n + 1];
	for(int i = 1; i <= n; i++)
	cin >> ar[i];

	for(int i = n; i; i--) {
		for(int j = 1; j <= 8; j++) {
			for(int z = 1; z <= n; z++) {
				dp[i][z][j] = dp[i + 1][z][j];
			}
		}
		for(int j = n; j; j--) {
			if(dp[i][j][ar[i]]) {
				dp[i][j + 1][ar[i]] = dp[i][j][ar[i]];
			}
		}
		dp[i][1][ar[i]] = i + 1;
	}
	int max_len = n / 8 + 1;
	int ans = 0;
	for(int l = 0; l <= max_len; l++) {
		ms(dp2);
		dp2[0][0] = 1;
		for(int j = 0; j < 8; j++) {
			for(int mask = 0; mask < (1 << 8); mask++) {
				if(dp2[j][mask]) {
					for(int i = 0; i < 8; i++) {
						if(!(mask & (1 << i))) {
							if(l) {
								if(dp[dp2[j][mask]][l][i + 1]) {
									upd(dp2[j][mask | (1 << i)], dp[dp2[j][mask]][l][i + 1]);
								}
							} else {
								upd(dp2[j][mask | (1 << i)], dp2[j][mask]);
							}
							if(dp[dp2[j][mask]][l + 1][i + 1]) {
								upd(dp2[j + 1][mask | (1 << i)], dp[dp2[j][mask]][l + 1][i + 1]);
							}
						}
					}
				}
			}
		}
		for(int j = 0; j <= 8; j++) {
			int m = 255;
			if(dp2[j][m]){
				ans = max(ans, l * 8 + j);
			}
		}
	}
	cout << ans << endl;
}