/**
 *    author:  Atreus
 *    created: 09.01.2019 10:28:00       
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxm = 1e5 + 5;
const int maxn = 1e5 + 5;
const int maxp = 100 + 5;

ll par[maxm], a[maxm], d[maxn];
ll dp[maxn][maxp];

ll sum(int fi, int se){
	return par[se] - par[fi - 1];
}

void cal_dp(int fi, int se, int lo, int hi, int row){
	if (fi >= se)
		return;
	int mid = (fi + se) >> 1;
	int idx = -1;
	for (int i = lo; i <= min(mid, hi); i++){
		ll update = dp[i - 1][row - 1] - sum(i, mid) + 1ll * (mid - i + 1) * a[mid];
		if (update < dp[mid][row]){
			dp[mid][row] = update;
			idx = i;
		}
	}
	cal_dp(fi, mid, lo, idx, row);
	cal_dp(mid + 1, se, idx, hi, row);
}

int main (){
	ios_base::sync_with_stdio (false);
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 2; i <= n; i++){
		int x;
		cin >> x;
		d[i] = d[i - 1] + x;
	}
	for (int i = 1; i <= m; i++){
		int h, t;
		cin >> h >> t;
		a[i] = t - d[h]; // lower of time we can get this cat
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++)
		par[i] = par[i - 1] + a[i];
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0; // dp[i][j] is minimum sum of waitings of cats in interval [1, i] with j employs
	for (int i = 1; i <= p; i++){
		cal_dp(1, m + 1, 1, m, i);
		dp[0][i] = 0;
	}
	cout << dp[m][p] << endl;
}