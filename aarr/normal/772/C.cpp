#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int N = 200 * 1000 + 5;
int n, m;

bool mark[N];
int dp[N], par[N], cnt[N];
vector <int> vec[N];
long long fi[N];

int bmm(int x, int y) {
	if (y == 0) {
		return x;
	}
	return bmm(y, x % y);
}

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= m;
	if (y % 2) {
		ans *= x;
		ans %= m;
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mark[x] = true;
	}
	for (int i = 0; i < m; i++) {
		if (!mark[i]) {
			int x = bmm(m, i);
			cnt[x]++;
			vec[x].push_back(i);
		}
	}
	for (int i = m; i; i--) {
		for (int j = i * 2; j <= m; j += i) {
			if (dp[j] >= dp[i]) {
				dp[i] = dp[j];
				par[i] = j;
			}
		}
		dp[i] += cnt[i];
	//	cout << "73 " << i << " " << dp[i] << " " << cnt[i] << endl;
	}
	iota(fi + 1, fi + N, 1);
	for (int i = 2; i < N; i++) {
		if (fi[i] == i) {
			for (int j = i; j < N; j += i) {
				fi[j] = fi[j] * (i - 1) / i;
			}
		}
	}
//	cout << fi[m] << endl;
	cout << dp[1] << '\n';
	int x = 1, lt = 1, lgcd = 1;
	while (x) {
		for (auto y : vec[x]) {
			long long ans = 1ll * y / lgcd * po(lt / lgcd, fi[m] - 1);
			ans %= m;
		//	cout << "75 " << y << " " << lt << endl;
			cout << ans << " ";
			lt = y;
			lgcd = x;
			
		}
		x = par[x];
		
	}
	return 0;
}