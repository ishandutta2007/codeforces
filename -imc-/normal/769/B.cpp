#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	int s = accumulate(all(a), 0);
	if (s < n - 1 || a[0] == 0) {
		puts("-1");
		return 0;
	}
	
	vector<pair<int, int>> deg(n);
	for (int i = 0; i < n; ++i) {
		deg[i] = {a[i], i};
	}
	sort(deg.begin() + 1, deg.end());
	reverse(deg.begin() + 1, deg.end());

	cout << n - 1 << "\n";
	int current = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < deg[i].first && current < n; ++j) {
			cout << deg[i].second + 1 << " " << deg[current].second + 1 << "\n";
			++current;
		}
	}

	return 0;
}