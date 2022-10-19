#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define x first
#define y second
#define pb push_back
#define all(s) (s).begin(), (s).end()
#define bit(x, y) ((x >> y) & 1)

const int N = 3005;

int n, k;
vector<int> a[N];
int dp[N];
int ans = 0;

void solve(int l, int r) {


	if (l == r) {
		int tmp = dp[k];
		for (int i = 0; i < min(k, (int) a[l].size()); i++) {
			tmp = max(tmp, dp[k - i - 1] + a[l][i]);
		}
		ans = max(ans, tmp);
		return;
	}

	vector<ii> changes;

	int mid = (l + r) / 2;

	for (int i = mid + 1; i <= r; i++) {
		int sz = a[i].size();
		int val = a[i].back();
		for (int j = k; j >= sz; j--) {

			if (dp[j] < dp[j - sz] + val) {
				changes.push_back({j, dp[j]});
				dp[j] = dp[j - sz] + val;
			}

		}
	}


	solve(l, mid);


	for (int i = (int) changes.size() - 1; i >= 0; i--) {
		ii foo = changes[i];
		dp[foo.x] = foo.y;
	}
	changes.clear();

	for (int i = l; i <= mid; i++) {
		int sz = a[i].size();
		int val = a[i].back();
		for (int j = k; j >= sz; j--) {

			if (dp[j] < dp[j - sz] + val) {
				changes.push_back({j, dp[j]});
				dp[j] = dp[j - sz] + val;
			}
		}
	}


	solve(mid + 1, r);

	for (int i = (int) changes.size() - 1; i >= 0; i--) {
		ii foo = changes[i];
		dp[foo.x] = foo.y;
	}
	changes.clear();
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int sz;
		cin >> sz;
		a[i].resize(sz);
		for (int &e : a[i])
			cin >> e;
		for (int j = 1; j < sz; j++)
			a[i][j] += a[i][j - 1];
	}

	solve(1, n);

	cout << ans << endl;

	return 0;
}