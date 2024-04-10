#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-17;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
inline void read(int &n) {
	n = 0;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		n = n * 10 + ccc - '0';
	}
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

ll _pow(ll n, ll m) {
	return (m == 0 ? 1 : m & 1 ? _pow(n, m - 1) * n : sqr(_pow(n, m >> 1)))mod;
}

ll fac[1000], antifac[1000];
int n;

inline void mult(ll &a, ll b) {
	a = (a * b)mod;
}

inline ll add(ll ans1, int n, int m) {
	mult(ans1, fac[n + m]);
	mult(ans1, antifac[n]);
	mult(ans1, antifac[m]);
	return ans1;
}

inline void add(ll &a, ll b) {
	a += b;
	while (a >= MOD)
		a -= MOD;
}

int ar[10];
ll dp[101][101];
ll solve() {
	if(n == 0)
		return 1;
	ms(dp);
	for (int i = ar[0]; i <= n; i++)
		dp[0][i] = 1;
	for (int i = 1; i < 10; i++) {
		if (ar[i] == 0)
			for (int j = 0; j <= n; j++) {
				dp[i][j] = dp[i - 1][j];
			}
		for (int j = ar[i]; j <= n; j++) {
			if (j == 0)
				continue;
			for (int w = j; w <= n; w++) {
				add(dp[i][w], add(dp[i - 1][w - j], w - j, j));
			}
		}
	}
	return dp[9][n];
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	fac[0] = fac[1] = 1;
	for(int i = 2; i < 1000; i++) {
		fac[i] = (fac[i - 1] * i) mod;
	}
	for(int i = 0; i < 1000; i++) {
		antifac[i] = _pow(fac[i], MOD - 2);
	}
	cin >> n;

	for(int i = 0; i < 10; i++)
	cin >> ar[i];

	int sum = 0;
	for(int i = 0; i < 10; i++)
	sum += ar[i];

	if(sum > n) {
		cout << 0;
		return 0;
	}

	if(n == 1) {
		cout << 1;
		return 0;
	}

	if(sum && sum == ar[0]) {
		cout << 0;
		return 0;
	}
	ll ans = 0;
	n--;
	for(int q = n; q >= 0; q--) {
		n = q;
		for(int i = 1; i <= 9; i++) {
			if(ar[i]) {
				sum--;
				ar[i]--;
				if(n >= sum)
					add(ans, solve());
				ar[i]++;
				sum++;
			} else {
				if(n >= sum)
					add(ans, solve());
			}
		}
	}

	cout << ans << endl;

}