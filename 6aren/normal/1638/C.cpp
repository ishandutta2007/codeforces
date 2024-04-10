#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> p(n + 1), pos(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}
	int cur = n + 1;
	int mn = 1e9;
	int res = 0;
	for (int i = n; i >= 1; i--) {
		if (pos[i] < cur && i < mn) 
			res++;
		for (int j = cur - 1; j >= pos[i]; j--) 
			mn = min(mn, p[j]);
		cur = min(cur, pos[i]);
	}
	cout << res << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
}