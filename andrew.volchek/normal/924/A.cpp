#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

#define ll long long


int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	set<int> glcols, glrows;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '#') {
				vector<int> rows, cols;
				for (int ii = 0; ii < n; ++ii) {
					if (a[ii][j] == '#') {
						rows.push_back(ii);
						if (glrows.count(ii)) {
							cout << "No\n";
							return 0;
						}
						glrows.insert(ii);
					}
				}
				for (int jj = 0; jj < m; ++jj) {
					if (a[i][jj] == '#') {
						cols.push_back(jj);
						if (glcols.count(jj)) {
							cout << "No\n";
							return 0;
						}
						glcols.insert(jj);
					}
				}
				for (auto x : rows) {
					for (auto y : cols) {
						if (a[x][y] != '#') {
							cout << "No\n";
							return 0;
						}
						a[x][y] = '.';
					}
				}
			}
		}
	}
	cout << "Yes\n";
	
	return 0;
}