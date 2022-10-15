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
#define input _read("input.txt")
#define mod % MOD
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

ll dp[31][31][51];

ll solve(int x, int y, int k){
	if(dp[x][y][k] != 0 || k == 0 || x * y == k)
		return dp[x][y][k];
	ll ans = INT_MAX;
	for(int i = 1; i <= x - i; i++)
		for(int j = 0; j <= k; j++)
			ans = min(ans, solve(i, y, j) + solve(x - i, y, k - j) + sqr(y));
	for(int i = 1; i <= y - i; i++)
		for(int j = 0; j <= k; j++)
			ans = min(ans, solve(x, i, j) + solve(x, y - i, k - j) + sqr(x));
	return dp[x][y][k] = ans;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
#else

#endif

	ms(dp);

	int t;
	cin >> t;
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		cout << solve(a, b, c) << endl;
	}

}