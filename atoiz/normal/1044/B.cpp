// https://codeforces.com/group/sd4r2IvEfL/contest/289090/problem/A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int nTests;
	cin >> nTests;
	while (nTests--) {
		int n;
		cin >> n;
		vector<vector<int>> g(n + 1);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vector<int> vec[2];
		for (int k = 0; k < 2; ++k) {
			int z;
			cin >> z;
			vec[k].resize(z);
			for (int &i : vec[k]) cin >> i;
		}

		cout << "B " << vec[1][0] << endl;
		int root;
		cin >> root;

		vector<int> st, flag, vis;
		flag.assign(n + 1, 0), vis.assign(n + 1, 0);
		for (int u : vec[0]) flag[u] = true;
		st.push_back(root);
		vis[root] = true;
		while (not flag[st.back()]) {
			int u = st.back();
			st.pop_back();
			for (int v : g[u]) if (not vis[v]) {
				st.push_back(v);
				vis[v] = true;
			}
		}

		cout << "A " << st.back() << endl;
		int other;
		cin >> other;
		if (find(vec[1].begin(), vec[1].end(), other) == vec[1].end()) {
			cout << "C " << -1 << endl;
		} else {
			cout << "C " << st.back() << endl;
		}
	}
}