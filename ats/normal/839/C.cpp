#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <vector<int> >g;
double res = 0;
double num = 0;
void dfs(int a, int from, int depth ,double prob) {
	int c = g[a].size();
	if (from != -1) {
		c--;
	}
	if (c == 0) {
		res += depth*prob;
		return;
	}
	for (int i = 0; i < g[a].size(); i++) {
		if (from != g[a][i]) {
			dfs(g[a][i], a, depth + 1, prob*(1 / (double)c));
		}
	}
}

signed main() {
	int n;
	cin >> n;
	g.resize(n);
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1, 0, 1);

	cout << setprecision(15) << res << endl;
	return 0;
}