#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<int> mx(10, -1);
	for (int i = 0; i < n; ++i) {
		int b = nxt(), d = nxt() - 1;
		mx[d] = max(mx[d], b);
	}
	if (*min_element(all(mx)) == -1) {
		cout << "MOREPROBLEMS\n";
	} else {
		cout << accumulate(all(mx), 0) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}