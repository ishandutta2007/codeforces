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
	int n, m;
	cin >> n >> m;
	vector<bool> taken(m);
	string s;
	cin >> s;
	vector<int> ans(n * m);
	vector<int> bad(m);
	int combo_zeros = 0;
	int cur = 0;
	for (int i = 0; i < n * m; ++i) {
		if (s[i] == '1' && !taken[i % m]) {
			taken[i % m] = 1;
			cur++;
		}
		ans[i] += cur;
	}
	for (int i = 0; i < n * m; ++i) {
		if (s[i] == '0')
			combo_zeros++;
		else
			combo_zeros = 0;
		if (combo_zeros >= m || combo_zeros == i + 1)
			bad[i % m]++;
		ans[i] += i / m + 1 - bad[i % m];
	}
	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';
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