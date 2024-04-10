#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

struct Edge {
	int a, b;

	Edge(int _a, int _b) : a(_a), b(_b) {}

	friend ostream& operator<<(ostream &s, const Edge &e) {
		s << e.a << " " << e.b << endl;
		return s;
	}
};
int n, k;
vector<Edge> ans;
int cur;

void dfs(int u, int cnt_n, int depth) {
	if (depth == 0) {
		return;
	}
	int p = cur;
	for (int i = 0; i < cnt_n; i++) {
		if (ans.size() == n - 1) {
			return;
		}
		ans.push_back(Edge(u, cur));
		dfs(cur++, k - 1, depth - 1);
	}
}

signed main() {
	int d;
	cin >> n >> d >> k;
	if (d >= n || (k == 1 && n > 2)) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 1; i <= d; i++) {
		ans.push_back(Edge(i, i + 1));
	}
	cur = d + 2;
	for (int i = 2; i <= d; i++) {
		dfs(i, k - 2, min(i - 1, d + 1 - i));
	}
	if (ans.size() != n - 1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (auto e : ans) {
		cout << e;
	}
	return 0;
}