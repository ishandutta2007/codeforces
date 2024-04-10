#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
//#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-9;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef LOCAL
const int MAX = 2e4;
#else
const int MAX = 2e4;
#endif
#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	ll ans = 0;
	int n, m;
	cin >> n >> m;
	vector<int> vec[n];
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int dp[n];
	ms(dp, 0);
	for(int i = 0; i < n; i++){
		int q = 0;
		for(int j = 0; j < (int) vec[i].size(); j++){
			if(vec[i][j] < i)
				q = max(q, dp[vec[i][j]]);
		}
		dp[i] = q + 1;
		ans = max(ans, 1LL * dp[i] * (ll) vec[i].size());
	}
	cout << ans;

}