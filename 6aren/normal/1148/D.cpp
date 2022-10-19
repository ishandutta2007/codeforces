#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> a[2];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		if (u < v) {
			a[0].push_back(make_pair(v, i));
		} else {
			a[1].push_back(make_pair(v, i));
		}
	}
	if (a[0].size() > a[1].size()) {
		cout << a[0].size() << endl;
		sort(a[0].begin(), a[0].end());
		for (int i = a[0].size() - 1; i >= 0; i--) {
			cout << a[0][i].second << ' ';
		}
	} else {
		cout << a[1].size() << endl;
		sort(a[1].begin(), a[1].end());
		for (int i = 0; i < a[1].size(); i++) {
			cout << a[1][i].second << ' ';
		}
	}
	return 0;
}