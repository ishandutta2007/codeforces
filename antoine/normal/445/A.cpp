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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
		for (int j = 0; j < m; ++j)
			if (grid[i][j] == '.')
				grid[i][j] = ((i + j) & 1) ? 'W' : 'B';
	}
	for (int i = 0; i < n; ++i)
		cout << grid[i] << '\n';
	return 0;
}