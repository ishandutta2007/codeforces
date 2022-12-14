#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 1e5 + 10;
const int SQRT = 800;

int dp[2][SQRT];
int r[maxn], c[maxn];
vector<int> v[maxn];

int get(int i, int j){
	return upper_bound(v[i].begin(), v[i].end(), j) - v[i].begin();
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
		cin >> r[i] >> c[i];
		v[c[i]].push_back(r[i]);
	}
	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());
	memset(dp, 63, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++){
		int p = i & 1;
		dp[p][0] = dp[1-p][0] + get(n-i+1, n) * 3;
		for (int k = 1; k <= min(i, SQRT-1); k++)
			dp[p][0] = min(dp[p][0], dp[1-p][k-1] + k*(k+1)/2 + 2 + get(n-i+1, n-k) * 3);
		for (int j = 1; j < SQRT; j++)
			dp[p][j] = min(dp[p][j-1], dp[1-p][j-1] + get(n-i+1, n-j) * 3);
	}
	cout << dp[n&1][0] << '\n';
}