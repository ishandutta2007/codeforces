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
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> inv_a(n);
	vector<int> b(n);
	vector<int> inv_b(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
		inv_a[a[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		b[i]--;
		inv_b[b[i]] = i;
	}

	vector<bool> was(n);
	vector<int> loops;

	for (int i = 0; i < n; ++i) {
		int v = i;
		int len = 0;
		while (!was[v]) {
			was[v] = 1;
			v = inv_a[b[v]];
			len++;
		}
		loops.push_back(len);
	}

	int low = 1;
	int high = n;
	sort(loops.begin(), loops.end());

	int ans = 0;

	for (int i : loops) {
		if (i < 2)
			continue;
		int first = -1;
		int prev = -1;
		int val;
		if (i % 2 == 1)
			i--;
		for (int j = 0; j < i; ++j) {
			val = (j % 2 == 0 ? low++ : high--);
			if (first == -1)
				first = val;
			if (prev != -1)
				ans += abs(val - prev);
			prev = val;
		}
		ans += abs(val - first);
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