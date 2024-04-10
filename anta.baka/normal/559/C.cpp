#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int mod = (int)1e9 + 7;
const int N = (int)2e5 + 100;

int pw(int a, int b) {
	if (!b) {
		return 1;
	}
	if (b & 1) {
		return 1LL * a * pw(a, b - 1) % mod;
	}
	a = pw(a, b >> 1);
	return 1LL * a * a % mod;
}

int fac[N];
int ifac[N];

int cnk(int n, int k) {
	if (n < k) {
		return 0;
	}
	return 1LL * fac[n] * (1LL * ifac[k] * ifac[n - k] % mod) % mod;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	fac[0] = 1;
	ifac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = 1LL * fac[i - 1] * i % mod;
		ifac[i] = pw(fac[i], mod - 2);
	}
	int h, w, n;
	cin >> h >> w >> n;
	vector<pii> a(n);
	for (auto& p : a) {
		cin >> p.first >> p.second;
	}
	sort(all(a));
	vector<vi> dp(n, vi(2, 0));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		dp[i][1] = cnk(a[i].first + a[i].second - 2, a[i].first - 1);
		for (int j = 0; j < i; j++) {
			if (a[j].second <= a[i].second) {
				int n = a[i].first - a[j].first + 1;
				int m = a[i].second - a[j].second + 1;
				int k = cnk(n + m - 2, n - 1);
				dp[i][0] = (dp[i][0] + 1LL * dp[j][1] * k) % mod;
				dp[i][1] = (dp[i][1] + 1LL * dp[j][0] * k) % mod;
			}
		}
		//cout << dp[i][0] << ' ' << dp[i][1] << endl;
		int n = h - a[i].first + 1;
		int m = w - a[i].second + 1;
		int k = cnk(n + m - 2, n - 1);
		ans = (ans + 1LL * (dp[i][0] - dp[i][1]) * k % mod + mod) % mod;
	}
	cout << (ans + cnk(h + w - 2, h - 1)) % mod;
}