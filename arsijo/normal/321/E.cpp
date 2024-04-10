#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-5;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef M_PI
#define M_PI 3.141592653589793238462643383
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
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAXN = 4010;
const int MAXK = 810;
const ll INF = 1E18;
ll dp[MAXN][MAXK];
int ar[MAXN][MAXN];
ll dp1[MAXN][MAXN];
ll dp2[MAXN][MAXN];
int o[MAXN][MAXK];

inline bool upd(ll &a, ll b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

inline ll get(int l, int r) {
	return dp2[r][r] - dp2[l - 1][l - 1] - dp1[r][l - 1] + dp1[l - 1][l - 1];
}

int n;

void solve(int l, int r, int tl, int tr, int m) {
	if (l > r)
		return;
	int x = (l + r) >> 1;
	for (int i = tl; i <= tr && i < x; i++) {
		if (upd(dp[x][m], dp[i][m - 1] + get(i + 1, x)))
			o[x][m] = i;
	}
	//cout << m << " " << x << " " << o[x][m] << " " << dp[x][m] << endl;
	solve(l, x - 1, tl, o[x][m], m);
	solve(x + 1, r, o[x][m], tr, m);
}

void solve(int m) {
	solve(0, n, 0, n, m);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int m;
	read(n);
	read(m);

	for(int i = 0; i < MAXN; i++) {
		for(int j = 0; j < MAXK; j++) {
			dp[i][j] = INF;
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			read(ar[i][j]);
			dp1[i][j] = ar[i][j] + dp1[i - 1][j] + dp1[i][j - 1] - dp1[i - 1][j - 1];
			dp2[i][j] = ar[i][j] + dp2[i - 1][j - 1] + dp1[i][j] - dp1[i - 1][j];
		}
	}

	dp[0][0] = 0;

	for(int j = 1; j <= m; j++){
		solve(j);
	}

	cout << dp[n][m] << endl;

}