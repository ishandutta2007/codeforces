#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
using namespace std;
const int Y = 200100;
long long arr[Y];
int lss[Y];
int dd[Y];
int dp[Y];
bool NI[Y];
int ans[Y];
long long aaa = 0;
vector<int>Ed[Y];
void dfs(int i, int p, int d) {
	dp[i] = 1;
	dd[i] = d - 1;
	for (auto x : Ed[i]) {
		if (x == p)continue;
		dfs(x, i, d + 1);
		dp[i] += dp[x];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		Ed[a].push_back(b);
		Ed[b].push_back(a);
		++lss[a];
		++lss[b];
	}
	dfs(1, -1, 1);
	for (int i = 1; i <= n; ++i)dd[i] = dd[i] - (dp[i] - 1);
	sort(dd + 1,dd + 1 + n);
	for (int j = 0, i = n; j < k; ++j, --i) {
		aaa += (long long)dd[i];
	}
	cout << aaa;
	return 0;
}