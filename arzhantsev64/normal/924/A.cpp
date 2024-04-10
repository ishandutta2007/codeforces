#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> v(n, vector<char> (m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	vector<set<int>> q(n);
	for (int i = 0; i < n; ++i)	
		for (int j = 0; j < m; ++j)
			if (v[i][j] == '#')
				q[i].insert(j);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (q[i] == q[j]) continue;
			for (auto k : q[i]) if (q[j].count(k)) { cout << "No" << endl; return 0; }
			for (auto k : q[j]) if (q[i].count(k)) { cout << "No" << endl; return 0; }
		}
	cout << "Yes" << endl;
}