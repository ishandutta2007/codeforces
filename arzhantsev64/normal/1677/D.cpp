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

	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int ans = 1;

	for (int i = 0; i < n - k; ++i) {
		if (v[i] != -1 && v[i] > i) {
			cout << 0 << '\n';
			return;
		}

		if (v[i] == -1)
			ans = (ans * (i + k + 1)) % mod;
		else if (v[i] == 0)
			ans = (ans * (k + 1)) % mod;
	}

	for (int i = n - k; i < n; ++i) {
		if (v[i] != -1 && v[i] != 0) {
			cout << 0 << '\n';
			return;
		}
		ans = (ans * (i - n + k + 1)) % mod;
	}
	cout << ans << endl;

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