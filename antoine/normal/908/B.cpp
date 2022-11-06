#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<string> grid;
string s;

struct Cell {
	int r, c;
};

bool f(const pair<int, int> * mapping) {
	Cell pos = { -1, -1 };
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] == 'S')
				pos = { i, j };

	for (char c : s) {
		pos.r += mapping[c - '0'].first;
		pos.c += mapping[c - '0'].second;
		if (pos.r < 0 || pos.c < 0 || pos.r >= n || pos.c >= m || grid[pos.r][pos.c] == '#')
			return false;
		if (grid[pos.r][pos.c] == 'E')
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	grid.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> grid[i];
	cin >> s;
	pair<int, int> mapping[4] = { {0, 1}, {1, 0},  {-1, 0}, {0, -1} };
	sort(mapping, mapping + 4);
	int ans = 0;
	do
		ans += f(mapping);
	while (next_permutation(mapping, mapping + 4));
	cout << ans;
	return 0;
}