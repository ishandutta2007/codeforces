#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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

const int MAX = 1e5 + 10;

ll dp[MAX][3][11];

vector<int> vec[MAX];

int n, m, k, x;

void mul(ll &a, ll b) {
	a *= b;
	a %= MOD;
}

void add(ll &a, ll b) {
	a += b;
	a %= MOD;
}

ll d[3][11];

void dfs(int pos, int prev = 0) {
	dp[pos][0][0] = (k - 1);
	dp[pos][1][1] = 1;
	dp[pos][2][0] = (m - k);
	for (int a : vec[pos]) {
		if (a != prev) {
			dfs(a, pos);
			ms(d);
			for (int i = 0; i <= x; i++) {
				for (int j = 0; i + j <= x; j++) {
					add(d[0][i + j], dp[a][0][j] * dp[pos][0][i]);
					add(d[0][i + j], dp[a][1][j] * dp[pos][0][i]);
					add(d[0][i + j], dp[a][2][j] * dp[pos][0][i]);
					add(d[1][i + j], dp[a][0][j] * dp[pos][1][i]);
					add(d[2][i + j], dp[a][2][j] * dp[pos][2][i]);
					add(d[2][i + j], dp[a][0][j] * dp[pos][2][i]);
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j <= x; j++) {
					dp[pos][i][j] = d[i][j];
				}
			}
		}
	}
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(4);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> m;

	for(int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	cin >> k >> x;

	ll ans = 0;

	dfs(1);

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j <= x; j++) {
			ans += dp[1][i][j];
		}
	}

	ans %= MOD;

	cout << ans << endl;

}