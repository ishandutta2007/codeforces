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
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#define M_PI acos(-1)
#define remove tipa_remove
#define left tipa_left
#define right tipa_right
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

int n, v, k;

const int MAX = 78;
int dp[MAX][MAX][MAX][3];

inline void upd(int &a, int b) {
	a = min(a, b);
}

int ar[MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	string s;
	cin >> s;
	int N = n;
	n = v = k = 0;
	for(int i = 0; i < N; i++) {
		if(s[i] == 'V') {
			ar[i] = 2;
			v++;
		} else if(s[i] == 'K') {
			k++;
			ar[i] = 1;
		} else {
			n++;
			ar[i] = 0;
		}
	}

	const int INF = 1e9;

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k; j++) {
			for(int z = 0; z <= v; z++) {
				for(int q = 0; q < 3; q++) {
					dp[i][j][z][q] = INF;
				}
			}
		}
	}

	dp[0][0][0][0] = 0;

	for(int a = 0; a <= n; a++) {
		for(int b = 0; b <= k; b++) {
			for(int c = 0; c <= v; c++) {
				for(int z = 0; z < 3; z++) {
					if(dp[a][b][c][z] < INF) {
						//cout << a << " " << b << " " << c << " " << z << " " << dp[a][b][c][z] << endl;
						for(int t = 0; t < 3; t++) {
							if(z == 2 && t == 1)
							continue;
							if(t == 0 && a == n)
							continue;
							if(t == 1 && b == k)
							continue;
							if(t == 2 && c == v)
							continue;
							int has_1 = a, has_2 = b, has_3 = c;
							int res = dp[a][b][c][z];
							bool find = false;
							for(int i = 0; i < N && ((!find)); i++) {
								if(ar[i] == 0) {
									if(has_1) {
										has_1--;
									} else {
										if(t == 0) {
											find = true;
										} else {
											res++;
										}
									}
								} else if(ar[i] == 1) {
									if(has_2) {
										has_2--;
									} else {
										if(t == 1) {
											find = true;
										} else {
											res++;
										}
									}
								} else if(ar[i] == 2) {
									if(has_3) {
										has_3--;
									} else {
										if(t == 2) {
											find = true;
										} else {
											res++;
										}
									}
								}
							}
							upd(dp[a + (t == 0)][b + (t == 1)][c + (t == 2)][t], res);
						}
					}
				}
			}
		}
	}

	cout << min(dp[n][k][v][0], min(dp[n][k][v][1], dp[n][k][v][2])) << endl;

}