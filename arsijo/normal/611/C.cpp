#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-10;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef LOCAL
const int MAX = 1e4 + 10;
#else
const int MAX = 2e4 + 10;
#endif
#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int ar[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	char s[n + 1][m + 1];
	ms(s, 0);
	int dp1[n + 1][m + 1];
	ms(dp1, 0);
	int dp2[n + 1][m + 1];
	ms(dp2, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s[i][j];
			dp1[i][j] = dp1[i - 1][j] + dp1[i][j - 1] - dp1[i - 1][j - 1];
			dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1];
			if (s[i][j] == '.') {
				if (s[i - 1][j] == '.')
					dp1[i][j]++;
				if (s[i][j - 1] == '.')
					dp2[i][j]++;
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = dp1[x2][y2] - dp1[x1][y2] - dp1[x2][y1 - 1] + dp1[x1][y1 - 1]
				+ dp2[x2][y2] - dp2[x1 - 1][y2] - dp2[x2][y1] + dp2[x1 - 1][y1];
		cout << ans << endl;
	}

}