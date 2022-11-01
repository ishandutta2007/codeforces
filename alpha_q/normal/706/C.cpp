#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const long long INF = 1e17 + 10;

string s[N], r[N];
int n; long long c[N], dp[N][2];

long long call (int pos, int flag) {
	if (pos == 1) return flag ? c[1] : 0;
	if (dp[pos][flag] != -1) return dp[pos][flag];

	long long &ret = dp[pos][flag];
	ret = INF;

	if (flag == 0) {
		if (s[pos] >= s[pos - 1]) ret = min(ret, call(pos - 1, 0));
		if (s[pos] >= r[pos - 1]) ret = min(ret, call(pos - 1, 1));
	} else {
		if (r[pos] >= s[pos - 1]) ret = min(ret, c[pos] + call(pos - 1, 0));
		if (r[pos] >= r[pos - 1]) ret = min(ret, c[pos] + call(pos - 1, 1));
	}

	return ret;
}

int main (int argc, char const *argv[]) {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		r[i] = s[i];
		reverse(r[i].begin(), r[i].end());
	}
	memset(dp, -1, sizeof dp);
	long long ans = min(call(n, 0), call(n, 1));
	if (ans == INF) ans = -1;

	printf("%lld\n", ans);

	cout.flush();
	return 0;
}