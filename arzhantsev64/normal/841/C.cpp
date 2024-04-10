#include <bits/stdc++.h>

using namespace std;

int main() {
	int m;
	cin >> m;
	vector<pair<int, int>> a(m);
	vector<pair<int, int>> b(m);
	int t;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		a[i] = {t, i};
	}
	for (int i = 0; i < m; ++i) {
		cin >> t;
		b[i] = {t, i};
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	vector<int> ans(m);
	for (int i = 0; i < m; ++i)
		ans[b[i].second] = a[i].first;
	for (int i : ans)
		cout << i << ' ';
}