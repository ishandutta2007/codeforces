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
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define next tipa_next
#define left tipa_left
#define right tipa_right
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
inline bool read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n') {
			if (ccc == '\n')
				return true;
			break;
		}
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
	return false;
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

int n;

const int MAX = 51;

int ar[MAX];

ll dp[2][MAX][MAX][MAX][MAX];

inline void upd(ll &a, ll b) {
	a += b % MOD;
	if (a >= MOD)
		a -= MOD;
}

ll C[MAX][MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	C[0][0] = 1;
	for(int i = 1; i < MAX; i++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
		}
	}

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}

	dp[0][ar[1] == 2][ar[1] == 3][ar[2] == 2][ar[2] == 3] = 1;

	for (int i = 3; i <= n; i++) {
		for (int a = 0; a <= n; a++) {
			for (int b = 0; b + a <= n; b++) {
				for (int c = 0; c + a + b <= n; c++) {
					for (int d = 0; d + a + b + c <= n; d++) {
						if (dp[0][a][b][c][d]) {
							//cout << i << " " << a << " " << b << " " << c << " " << d << " " << dp[0][a][b][c][d] << endl;
							ll now = dp[0][a][b][c][d];
							for(int a0 = 0; a0 <= a && a0 <= ar[i]; a0++) {
								for(int b0 = (a0 == 0 ? 1 : 0); b0 <= b && a0 + b0 <= ar[i] && a0 + b0 <= 1; b0++) {
									for(int c0 = 0; c0 <= c && a0 + b0 + c0 <= ar[i]; c0++) {
										for(int d0 = 0; d0 <= d && a0 + b0 + c0 + d0 <= ar[i]; d0++) {
											if(a - a0 + b0 != 0 || b - b0 != 0)
											if(a0 || b0 || c0 || d0)
											upd(dp[1][a - a0 + b0][b - b0][c - c0 + d0 + ((ar[i] - a0 - b0 - c0 - d0) == 1)][d - d0 + ((ar[i] - a0 - b0 - c0 - d0) == 2)], now * C[a][a0] * C[b][b0] * C[c][c0] * C[d][d0]);
										}
									}
								}
							}
							//cout << dp[1][0][0][0][0] << endl;
							for(int a0 = 0; a0 <= a && a0 <= ar[i]; a0++) {
								for(int b0 = 0; b0 <= b && a0 + b0 <= ar[i] && a0 + b0 <= 1; b0++) {
									if(a - a0 + b0 == 0 && b - b0 == 0) {
										for(int c0 = 0; c0 + a0 + b0 <= ar[i] && c0 <= c; c0++) {
											for(int d0 = (c0 == 0 && a0 == 0 && b0 == 0 ? 1 : 0); c0 + d0 + a0 + b0 <= ar[i] && d0 <= d; d0++) {
												int a1 = c - c0 + d0;
												int b1 = d - d0;
												int c1 = 0;
												int d1 = 0;
												if(ar[i] == 1 + a0 + b0 + c0 + d0){
													if((a0 || b0) == 1){
														a1++;
													}else{
														c1++;
													}
												}else if(ar[i] == 2 + a0 + b0 + c0 + d0){
													if((a0 || b0) == 1){
														b1++;
													}else{
														d1++;
													}
												}
												//cout << "---- " << a0 << " " << b0 << " " << c0 << " " << d0 << " " << a1 << " " << b1 << " " << c1 << " " << d1 << " " << now * C[a][a0] * C[b][b0] * C[c][c0] * C[d][d0] << endl;
												upd(dp[1][a1][b1][c1][d1], now * C[a][a0] * C[b][b0] * C[c][c0] * C[d][d0]);
											}
										}
									}
								}
							}
							//cout << dp[1][0][0][0][0] << endl;
						}
					}
				}
			}
		}
		for (int a = 0; a <= n; a++) {
			for (int b = 0; b + a <= n; b++) {
				for (int c = 0; c + a + b <= n; c++) {
					for (int d = 0; d + a + b + c <= n; d++) {
						dp[0][a][b][c][d] = dp[1][a][b][c][d];
						dp[1][a][b][c][d] = 0;
					}
				}
			}
		}
	}

	cout << dp[0][0][0][0][0] << endl;

}