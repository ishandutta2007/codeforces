#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef vector<int>::iterator vit;
const ld E = 1e-7;
const int MOD = 1e9 + 7;

#ifdef LOCAL
const ll MAX = 100;
#else
const ll MAX = 1e5 + 1;
#endif

vector<int> vec[MAX];

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	int n, m, s, e;
	cin >> n >> m >> s >> e;

	int a[n], b[m];
	for(int i = 0; i < n; i++)
	cin >> a[i];
	for(int i = 0; i < m; i++)
	cin >> b[i];

	for(int i = 0; i < m; i++)
	vec[b[i]].push_back(i);

	int k = s / e;
	int dp[n + 1][k + 1];
	for(int i = 0; i <= n; i++)
	for(int j = 0; j <= k; j++)
	dp[i][j] = INT_MAX;

	dp[0][0] = -1;
	int ans = 0;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(dp[i][j] == INT_MAX)
				continue;
			int res = j * e + dp[i][j] + 1 + i;
			if(res <= s)
				ans = max(ans, j);
			if(i == n)
				continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			if(j == k)
				continue;
			vit it = upper_bound(vec[a[i]].begin(), vec[a[i]].end(), dp[i][j]);
			if(it != vec[a[i]].end()){
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], *it);
			}
		}
	}

	cout << ans;

}