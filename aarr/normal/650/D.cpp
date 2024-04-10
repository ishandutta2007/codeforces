#include <bits/stdc++.h>
using namespace std;


const int N = 400 * 1000 + 5, inf = 1000 * 1000 * 1000 + 7;

int a[N];
int dp[N];
vector <pair <int, int> > t[N];
vector <int> lt[N];
vector <int> rt[N];
int l[N], r[N], cnt[N];
int ans[N];


int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		t[x].push_back({i, y});
	}
	fill(dp + 1, dp + n + 1, inf);
	for (int i = 1; i <= n; i++) {
		for (auto p : t[i]) {
			int x = lower_bound(dp, dp + n + 1, p.second) - dp;
//			cout << "51 " << x << endl;
			lt[i].push_back(x);
		} 
		int x = lower_bound(dp, dp + n + 1, a[i]) - dp;
		l[i] = x;
		dp[x] = a[i];
	}
	int ls = lower_bound(dp, dp + n + 1, inf) - dp - 1;
	dp[0] = -inf;
	fill(dp + 1, dp + n + 1, inf);
	for (int i = n; i; i--) {
		for (auto p : t[i]) {
			int x = lower_bound(dp, dp + n + 1, -p.second) - dp;
//			cout << "52 " << p.first << " " << i << " " << x << endl;
			rt[i].push_back(x);
		} 
		int x = lower_bound(dp, dp + n + 1, -a[i]) - dp;
		r[i] = x;
		dp[x] = -a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (l[i] + r[i] - 1 == ls) {
			cnt[l[i]]++;
		}
	}
//	cout << "75 " << ls << endl;
	for (int i = 1; i <= n; i++) {
//		cout << "72 " << l[i] << " " << r[i] << endl;
		for (int j = 0; j < t[i].size(); j++) {
			ans[t[i][j].first] = ls - 1;
			if (cnt[l[i]] != 1 || l[i] + r[i] - 1 != ls) {
				ans[t[i][j].first]++;
			}
//			cout << "74 " << " " << t[i][j].first << " " << lt[i][j] << " " << rt[i][j] << endl;
			ans[t[i][j].first] = max(ans[t[i][j].first], lt[i][j] + rt[i][j] - 1);
		}
	}
	for (int i = 0; i < q; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}