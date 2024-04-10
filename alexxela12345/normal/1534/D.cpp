#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

set<pair<int, int>> edges;

void addEdge(int a, int b) {
	if (b < a)
		swap(a, b);
	edges.insert({a, b});
}

int n;

vector<int> ask(int v) {
	cout << "? ";
	cout << v << endl;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			addEdge(i + 1, v);
		}
	}
	return arr;
}

void solve() {
	cin >> n;
	auto dist = ask(1);
	vector<int> cnt(2);
	for (int i = 1; i < n; i++) {
		cnt[dist[i] % 2]++;
	}
	int ind = min_element(cnt.begin(), cnt.end()) - cnt.begin();
	for (int i = 1; i < n; i++) {
		if (dist[i] % 2 == ind) {
			ask(i + 1);
		}
	}
	assert((int) edges.size() == n - 1);
	cout << "!" << endl;
	for (auto e : edges) {
		cout << e.first << " " << e.second << endl;
	}
}

signed main() {
	int t = 1;
	while (t--) {
		solve();
	}
}