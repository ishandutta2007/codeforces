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
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-8;
const ll MOD = 1e9 + 9;
#define mod % MOD

#ifdef LOCAL
#define DEBUG
#endif

const int MAX = 2e5 + 4;

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int dp[500][500], ar[500];

int solve(int l, int r){
	if(l > r)
		return 1;
	if(dp[l][r] != -1)
		return dp[l][r];
	int &ans = dp[l][r];
	ans = 10000;
	if(ar[l] == ar[r]){
		ans = solve(l + 1, r - 1);
	}
	for(int i = l + 1; i <= r; i++){
		ans = min(ans, solve(l, i - 1) + solve(i, r));
	}
	//cout << l << " " << r << " " << ans << endl;
	return ans;
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = -1;
		}
	}

	for(int i = 0; i < n; i++)
		dp[i][i] = 1;

	cout << solve(0, n - 1);

}