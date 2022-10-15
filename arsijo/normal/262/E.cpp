#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
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

int bits(ll n) {
	int ans = 0;
	while (n) {
		ans += n & 1;
		n >>= 1;
	}
	return ans;
}

void print(int n) {
	int ar[n + 2][n + 2];
	ms(ar);
	ar[1][n + 1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			ar[i][j] = (j == 1 ? 0 : ar[i - 1][j - 1])
					^ (j == n + 1 ? 0 : ar[i - 1][j + 1]);
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		int sum = 0;
		for (int j = 1; j <= n + 1; j++) {
			sum += ar[i][j];
		}
	}
}

int _count(ll n, int b) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (bits(i) == b)
			ans++;
	}
	return ans;
}

ll dp[60][60];

ll _count_2(ll n, int b) {
	if(b == 0)
		return 0;
	if(b == 1){
		return log2(n) + 1;
	}
	int q = log2(n);
	ms(dp);
	dp[q][0] = 1;
	ll t = 1;
	for (int i = q - 1; i >= 0; i--) {
		for (int j = 0; j <= q; j++) {
			dp[i][j] += dp[i + 1][j] + (j != 0 ? dp[i + 1][j - 1] : 0);
		}
		t = t << 1 | (n & (1LL << i) ? 1 : 0);
		int w = bits(t - 1);
		if (w && (t & 1))
			dp[i][w]++;
	}
	dp[0][bits(n)]++;
	return dp[0][b];
}

ll solve_long(ll n, int w){
	ll ans = 0;
	for(int i = 2; i <= n; i++)
		if(bits(i) == w)
			ans++;
	return ans;
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

	ll b, a;
	cin >> a >> b;

	if(b & (b - 1)){
		cout << 0;
		return 0;
	}
	a++;
	int w = log2(b);
	w++;

	cout << _count_2(a, w) - (w == 1 ? 1 : 0) << endl;

}