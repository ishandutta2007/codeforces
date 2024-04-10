#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb insert

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = (int)5e5 + 1;
const int A = (int)2e5 + 1;

int n;
set<pii> g[N];
vi od1, od2;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y; --x; --y; g[x].pb({ y + A, i }); g[y + A].pb({ x, i });
	}
	for (int i = 0; i < A; i++) if (sz(g[i]) & 1) od1.push_back(i);
	for (int i = 0; i < A; i++) if (sz(g[i + A]) & 1) od2.push_back(i + A);
	while (min(sz(od1), sz(od2)) > 0) {
		int u = od1.back(), v = od2.back();
		od1.pop_back(); od2.pop_back();
		g[u].pb({ v, -1 }); g[v].pb({ u, -1 });
	}
	if (sz(od1)) for (int u : od1) g[u].pb({ A - 1 + A, -1 }), g[A - 1 + A].pb({ u, -1 });
	if (sz(od2)) for (int u : od2) g[u].pb({ A - 1, -1 }), g[A - 1].pb({ u, -1 });
	vector<char> ans(n);
	for (int u = 0; u < A; u++) if (sz(g[u])) {
		vector<pii> st = { { u, -1 } };
		vi path;
		while (!st.empty()) {
			int v = st.back().first;
			int ei = st.back().second;
			if (g[v].empty()) {
				st.pop_back();
				path.push_back(ei);
			}
			else {
				pii e = *g[v].begin();
				g[v].erase(g[v].begin());
				g[e.first].erase({ v, e.second });
				st.push_back(e);
			}
		}
		for (int i = 0; i < sz(path); i++) {
			if (i & 1) {
				if (path[i] != -1) {
					ans[path[i]] = 'b';
				}
			}
			else {
				if (path[i] != -1) {
					ans[path[i]] = 'r';
				}
			}
		}
	}
	for (auto c : ans) cout << c;
}