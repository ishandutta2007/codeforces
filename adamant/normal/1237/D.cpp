#include <bits/stdc++.h>

using namespace std;

#define fpos alfla

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a.push_back(a[i]);
	}
	for(int i = 0; i < n; i++) {
		a.push_back(a[i]);
	}
	vector<pair<int, int>> st = {{(int)2e9 + 42, -1}};
	vector<int> pr(3 * n, -1);
	int idx = 0;
	for(int i = 0; i < 3 * n; i++) {
		while(st.size() && st.back().first <= a[i]) {
			st.pop_back();
		}
		st.push_back({a[i], i});
		idx = min<int>(idx, st.size() - 1);
		while(st[idx].first <= 2 * a[i]) {
			idx--;
		}
		while(st[idx + 1].first > 2 * a[i]) {
			idx++;
		}
		pr[i] = st[idx].second;
	}
	vector<int> ans(n, -1);
	vector<int> mn(3 * n, 1e9);
	for(int i = 3 * n - 1; i >= 0; i--) {
		if(i + 1 < 3 * n) {
			mn[i] = min(mn[i], mn[i + 1]);
		}
		if(mn[i] < 1e9) {
			ans[i % n] = ans[i % n] == -1 ? mn[i] - i : min(ans[i % n], mn[i] - i);
		}
		if(pr[i] != -1) {
			mn[pr[i]] = min(mn[pr[i]], i);
		}
	}
	for(auto it: ans) {
		cout << it << ' ';
	}
	return 0;
}