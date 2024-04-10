#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
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

const int MAX = 500;
const int MAX_LOG = 61;
bitset<MAX> dp[MAX][MAX_LOG][2];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		dp[a][0][c][b] = 1;
	}

	for(int l = 1; l < MAX_LOG; l++) {
		for(int pos = 0; pos < n; pos++) {
			for(int a = 0; a < n; a++) {
				if(dp[pos][l - 1][0][a]) {
					dp[pos][l][0] |= dp[a][l - 1][1];
				}
			}
			for(int a = 0; a < n; a++) {
				if(dp[pos][l - 1][1][a]) {
					dp[pos][l][1] |= dp[a][l - 1][0];
				}
			}
		}
	}

	int q = 0;

	ll ans = 0;
	bitset<MAX> now;
	now[0] = 1;
	for(int i = MAX_LOG - 1; i >= 0; i--) {
		bitset<MAX> t;
		for(int a = 0; a < n; a++) {
			if(now[a]) {
				t |= dp[a][i][q];
			}
		}
		if(t.count()) {
			ans += (1LL << i);
			now = t;
			q ^= 1;
		}
	}
	if(ans > 1e18) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}

}