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

	vector<pair<int, int>> economy;
	for (int i = 0; i < n; ++i)
		economy.push_back({a[i] - n + 1 + i, i});

	int ans = 0;
	for (int i : a) ans += i;

	sort(economy.rbegin(), economy.rend());
	for (int i = 0; i < k; ++i) {
		ans -= economy[i].first + i;
	}

	cout << ans << '\n';
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

// 8 2 5 15 11 2 8

// 2 -3 1 12 9 1 8

// 12 9 8 2 1

// 51 - 32 - 10 = 19 - 10 = 9