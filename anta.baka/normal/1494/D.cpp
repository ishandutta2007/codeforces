#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

struct Edge {
	int u, v, c;
	bool operator < (Edge ot) {
		return c < ot.c;
	}
};

int get(vector<int>& p, int u) {
	while (p[u] != -1) {
		u = p[u];
	}
	return u;
}

void solve() {
	int n;
	cin >> n;
	vector<Edge> tmp;
	vector<int> zp(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int c;
			cin >> c;
			if (i < j) {
				tmp.push_back({ i, j, c });
			}
			if (i == j) {
				zp[i] = c;
			}
		}
	}
	sort(tmp.begin(), tmp.end());
	vector<int> p(n, -1);
	for (auto kek : tmp) {
		int u = get(p, kek.u);
		int v = get(p, kek.v);
		if (u == v) {
			continue;
		}
		p.push_back(-1);
		zp.push_back(kek.c);
		p[u] = p.size() - 1;
		p[v] = p.size() - 1;
	}
	unordered_set<int> alive;
	vector<int> pp(p.size(), -1);
	for (int st = 0; st < n; st++) {
		alive.insert(st);
		int u = st;
		int last = u;
		while (p[u] != -1) {
			u = p[u];
			while (p[u] != -1 && zp[u] == zp[p[u]]) {
				u = p[u];
			}
			alive.insert(u);
			pp[last] = u;
			last = u;
		}
	}
	cout << alive.size() << '\n';
	int pog = 0;
	vector<int> re(p.size(), -1);
	int root = -1;
	for (int i = 0; i < p.size(); i++) {
		if (alive.count(i)) {
			re[i] = pog++;
			cout << zp[i] << ' ';
			if (pp[i] == -1) {
				root = i;
			}
		}
	}
	cout << '\n';
	cout << 1 + re[root] << '\n';
	for (int i = 0; i < p.size(); i++) {
		if (i != root && alive.count(i)) {
			cout << re[i] + 1 << ' ' << re[pp[i]] + 1 << '\n';
		}
	}

}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}