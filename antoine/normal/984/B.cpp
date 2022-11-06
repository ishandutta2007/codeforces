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

bool f() {

	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; ++i)
		cin >> grid[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] != '*') {
				int count = 0;
				for (int a = i - 1; a <= i + 1; ++a)
					for (int b = j - 1; b <= j + 1; ++b)
						count += a >= 0 && a < n && b >= 0 && b < m && !(a == i && b == j) && grid[a][b] == '*';
				if (grid[i][j] == '.') {
					if (count != 0)
						return false;
				}
				else {
					if (count != grid[i][j] - '0')
						return false;
				}
			}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << (f() ? "YES" : "NO");

	return 0;
}