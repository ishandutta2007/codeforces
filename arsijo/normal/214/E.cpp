#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
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

	int n;
	cin >> n;

	int ar[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> ar[i][j];
		}
	}

	int dp[2][n + n][n + n];
	ms(dp);
	dp[0][0][0] = ar[0][0];
	vector<int> vec[n + n];
	vector<ii> v[n + n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			vec[i + j].push_back(ar[i][j]);
			v[i + j].push_back(make_pair(i, j));
		}
	}
	for(int i = 1; i <= (n - 1) * 2; i++) {
		int w = i & 1;
		int q = 1 - w;
		for(int a = 0; a < n + n; a++){
			for(int b = 0; b < n + n; b++){
				dp[w][a][b] = -1e9;
			}
		}
		if(vec[i].size() > vec[i - 1].size()) {
			int prev_size = (int) vec[i - 1].size();
			for(int a = 0; a < (int) vec[i].size(); a++) {
				for(int b = 0; b < (int) vec[i].size(); b++) {
					for(int c = max(0, a - 1); c <= min(prev_size - 1, a); c++) {
						for(int d = max(0, b - 1); d <= min(prev_size - 1, b); d++) {
							ii f = v[i][a], g = v[i][b];
							dp[w][a][b] = max(dp[w][a][b], dp[q][c][d] + ar[f.first][f.second] + (a != b ? ar[g.first][g.second] : 0));
						}
					}
				}
			}
		} else {
			int prev_size = (int) vec[i - 1].size();
			for(int a = 0; a < (int) vec[i].size(); a++) {
				for(int b = 0; b < (int) vec[i].size(); b++) {
					for(int c = a; c < min(a + 2, prev_size); c++) {
						for(int d = b; d < min(b + 2, prev_size); d++) {
							ii f = v[i][a], g = v[i][b];
							dp[w][a][b] = max(dp[w][a][b], dp[q][c][d] + ar[f.first][f.second] + (a != b ? ar[g.first][g.second] : 0));
						}
					}
				}
			}
		}
		if(0)
		for(int i = 0; i < n + n; i++){
			for(int j = 0; j < n + n; j++){
				cout << dp[w][i][j] << "\t";
			}
			cout << endl;
		}
	}
	cout << dp[0][0][0] << endl;

}