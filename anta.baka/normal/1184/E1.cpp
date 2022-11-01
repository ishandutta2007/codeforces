#include <iostream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

struct DSU {
	vi p, s;
	DSU(int n) : p(n), s(n, 1) { iota(all(p), 0); }
	int get(int v) { return p[v] == v ? v : p[v] = get(p[v]); }
	void unite(int u, int v) {
		if ((u = get(u)) != (v = get(v))) {
			if (s[u] < s[v]) swap(u, v);
			s[u] += s[v]; p[v] = u;
		}
	}
};

struct edge {
	int u, v, w;
	bool operator < (const edge& him) const { return w < him.w; }
};

const int N = 1000001;

int n, m;
edge a[N];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m;
	edge kek; cin >> kek.u >> kek.v >> kek.w; --kek.u; --kek.v;
	for (int i = 0; i < m - 1; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w; --a[i].u; --a[i].v;
	}
	a[m - 1] = {0, 0, 1000000000};
	sort(a, a + m);
	int lf = 0, rg = 1000000000;
	while (lf < rg) {
		int md = (lf + rg + 1) >> 1;
		DSU dsu(n);
		for (int i = 0; i < m; i++) {
			if (md <= a[i].w) {
				if (dsu.get(kek.u) != dsu.get(kek.v)) lf = md;
				else rg = md - 1;
				break;
			}
			else {
				if (dsu.get(a[i].u) != dsu.get(a[i].v)) dsu.unite(a[i].u, a[i].v);
			}
		}
	}
	cout << lf;
}