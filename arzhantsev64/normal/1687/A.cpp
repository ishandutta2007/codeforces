#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define pt pair<int, int>
#define x first
#define y second

const int mod = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> sa(n);
	sa[0] = a[0];
	for (int i = 1; i < n; ++i)
		sa[i] = sa[i - 1] + a[i];

	if (k >= n) {
		int ans = sa[n - 1] + k * n - n * (n + 1) / 2;
		cout << ans << '\n';
	} else {
		int ans = 0;
		for (int i = k - 1; i < n; ++i)
			ans = max(ans, sa[i] - (i - k >= 0 ? sa[i - k] : 0));
		cout << ans + k * (k - 1) / 2 << '\n';
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    	 solve();

    return 0;
}