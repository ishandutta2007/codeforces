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

const int MAX = 151;

int dp[2][2][MAX][MAX];

inline void inc(int &a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
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

	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j++){
			dp[1][1][i][j] = 1;
		}
	}
	int ans = 0;
	for(int t = 1; t <= n; t++) {
		ll sum = 0;
		for(int a = 0; a <= 1; a++) {
			for(int b = 0; b <= 1; b++) {
				for(int i = 1; i <= m; i++) {
					for(int j = i; j <= m; j++) {
						sum += dp[a][b][i][j];
					}
				}
			}
		}
		inc(ans, (sum * (n - t + 1)) mod);
		for(int b = 0; b <= 1; b++) {
			for(int i = 1; i <= m; i++){
				for(int j = i + 1; j <= m; j++){
					for(int a = 0; a <= 1; a++){
						inc(dp[0][b][i + 1][j], dp[a][b][i][j]);
					}
				}
			}
		}
		for(int a = 0; a <= 1; a++) {
			for(int i = 1; i <= m; i++){
				for(int j = m; j > a; j--){
					for(int b = 0; b <= 1; b++){
						inc(dp[a][0][i][j - 1], dp[a][b][i][j]);
					}
				}
			}
		}
		for(int i = m; i > 1; i--){
			for(int j = i; j <= m; j++){
				for(int b = 0; b <= 1; b++){
					inc(dp[1][b][i - 1][j], dp[1][b][i][j]);
				}
			}
		}
		for(int i = m; i >= 1; i--){
			for(int j = i; j < m; j++){
				for(int a = 0; a <= 1; a++){
					inc(dp[a][1][i][j + 1], dp[a][1][i][j]);
				}
			}
		}
	}
	cout << ans << endl;

}