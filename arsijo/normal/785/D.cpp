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

ll dp[100][100];

int solve1(int n, int m) {
	ll ans = 0;
	for (int i = 1; i <= min(n, m); i++) {
		ans += (dp[n][i] * dp[m][i]) % MOD;
	}
	return (ans % MOD);
}

const int MAX = 2e5 + 10;

ll _pow(ll a, ll b) {
	return (b == 0 ? 1 : b & 1 ? a * _pow(a, b - 1) : sqr(_pow(a, b >> 1)))
			% MOD;
}

ll fac[MAX], afac[MAX];

ll c(int n, int m) {
	ll ans = fac[n];
	ans = (ans * afac[m]) % MOD;
	ans = (ans * afac[n - m]) % MOD;
	return ans;
}

ll solve2(int n, int m) {
	if(n == 0 || m == 0)
		return 0;
	return (c(n + m, n) - 1 + MOD) % MOD;
}

int suff[MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	fac[0] = 1;
	for(int i = 1; i < MAX; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}

	for(int i = 0; i < MAX; i++) {
		afac[i] = _pow(fac[i], MOD - 2);
	}

	dp[0][0] = 1;
	for(int i = 1; i < 100; i++) {
		dp[i][0] = dp[i][i] = 1;
		for(int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] %= MOD;
		}
	}

	string s;
	cin >> s;
	for(int i = (int) s.size() - 1; i >= 0; i--){
		suff[i] = suff[i + 1] + (s[i] == ')');
	}

	int pref = 0;
	ll ans = 0;
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] == '('){
			pref++;
			ans += solve2(pref, suff[i + 1]);
			ans -= solve2(pref - 1, suff[i + 1]);
			ans += MOD;
			ans %= MOD;
		}
	}

	cout << ans << endl;

}