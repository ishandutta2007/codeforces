#include <bits/stdc++.h>
using namespace std;
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
#ifndef LLONG_MAX
#define LLONG_MAX LONG_LONG_MAX
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

inline void upd(ll &a, ll b){
	a = min(a, b);
}

int main() {
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n, m, k;
	cin >> n >> m >> k;

	ll dp[n + 2][m + 2][k + 2];
	ll INF = 1e16;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int z = 0; z <= k; z++) {
				dp[i][j][z] = INF;
			}
		}
	}

	int ar[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}

	int d[n + 1][m + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> d[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		if (ar[1] == 0) {
			dp[1][i][1] = d[1][i];
		} else if (ar[1] == i) {
			dp[1][i][1] = 0;
		}
	}
	ll t[m+ 2], u[m + 2];
	for (int i = 2; i <= n; i++) {
		if (ar[i]) {
			for (int z = 1; z <= k; z++) {
				for (int a = 1; a <= m; a++) {
					if (a == ar[i]) {
						
							upd(dp[i][ar[i]][z], dp[i - 1][ar[i]][z]);
					} else {
					    if (z > 1)
						upd(dp[i][ar[i]][z], dp[i - 1][a][z - 1]);
					}
				}
			}
		} else {
			for(int z = 1; z <= k; z++){
				for(int a = 1; a <= m; a++){
					upd(dp[i][a][z], dp[i - 1][a][z] + d[i][a]);
				}
				if(z == 1)
					continue;
				t[0] = INF;
				for(int a = 1; a <= m; a++)
					t[a] = min(t[a - 1], dp[i - 1][a][z - 1]);
				u[m + 1] = INF;
				for(int a = m; a >= 1; a--)
					u[a] = min(u[a + 1], dp[i - 1][a][z - 1]);
				for(int a = 1; a <= m; a++){
					upd(dp[i][a][z], min(t[a - 1], u[a + 1]) + d[i][a]);
				}
			}
		}
	}

	ll ans = INF;
	for(int i = 1; i <= m; i++)
		upd(ans, dp[n][i][k]);
	if(ans == INF)
		ans = -1;
	cout << ans << endl;

}