#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;

void f() {
	cout << "No";
	exit(0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);

	int R, C;
	cin >> R >> C;
	vector<string> grid(R);
	for (int i = 0; i < R; ++i) {
		cin >> grid[i];
		for (auto &&c : grid[i])
			if (c == '.')
				c = 'D';
	}
	for(int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if (grid[i][j] == 'W' && i + 1 < R && grid[i + 1][j] == 'S')
				f();
			if (grid[i][j] == 'S' && i + 1 < R && grid[i + 1][j] == 'W')
				f();
			if (grid[i][j] == 'W' && j + 1 < C && grid[i][j + 1] == 'S')
				f();
			if (grid[i][j] == 'S' && j + 1 < C && grid[i][j + 1] == 'W')
				f();
		}
	cout << "Yes\n";
	for (auto &&s : grid)
		cout << s << '\n';
	return 0;
}