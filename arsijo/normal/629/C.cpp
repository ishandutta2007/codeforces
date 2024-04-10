#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#define endl "\n"
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int solve_min(string s) {
	int ans = 0;
	int w = 0;
	for (int i = 0; i < (int) s.size(); i++) {
		if (s[i] == '(') {
			w++;
		} else {
			w--;
		}
		ans = min(ans, w);
	}
	return -ans;
}

int get(string s) {
	int w = 0;
	for (int i = 0; i < (int) s.size(); i++)
		if (s[i] == '(')
			w++;
		else
			w--;
	return w;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(std::time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;
	int q = n - m + 2;

	int dp[q + 2][q + 2];
	ms(dp);

	dp[0][0] = 1;
	for(int i = 1; i <= q; i++) {
		dp[i][0] = dp[i - 1][1];
		for(int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			if(dp[i][j] >= MOD)
			dp[i][j] -= MOD;
		}
	}

	ll ans = 0;
	string s;
	cin >> s;

	int mm = solve_min(s);
	int status = get(s);
	ll a, b;
	for(int i = 0; i + m <= n; i++) {
		for(int j = mm; j <= i; j++) {
			a = dp[i][j];
			if(!a)
				continue;
			int e = j + status;
			dbg cout << a << " " << i << " " << j << " " << a << " " << e << endl;
			if(0 <= e && e <= q) {
				b = dp[n - i - m][e];
				dbg cout << b << endl;
				ans += (a * b) mod;
			}
		}
	}

	cout << ans mod;

}