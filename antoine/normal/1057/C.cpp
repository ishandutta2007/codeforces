#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int cnt[55];
char col[55];
int dp[55][2005];
const int Inf = (int)1e9;

int f(const int i, const int k) {
	if(k - cnt[i] <= 0) return 0;
	int &res = dp[i][k];
	if(res != -1) return res;
	res = Inf;

	for(int j = 1; j <= n; ++j)
		if(cnt[j] > cnt[i] && col[j] != col[i])
			res = min(res, abs(j - i) + f(j, k - cnt[i]));

	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dp, -1, sizeof dp);

	int start, k;
	cin >> n >> start >> k;

	for(int i = 1; i <= n; ++i)
		cin >> cnt[i];
	for(int i = 1; i <= n; ++i)
		cin >> col[i];

	int res = Inf;
	for(int i = 1; i <= n; ++i)
		res = min(res, abs(i - start) + f(i, k));

	cout << (res >= Inf ? -1 : res);
	return 0;
}