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


char grid[2000][2000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j];
	}

	int ans = 0;
	for (;;) {
		for (int i = 0; i < n; ++i) {
			int cnt = 0;
			for (int j = 0; j < m; ++j)
				if (grid[i][j] == '.')
					ans += ++cnt >= k;
				else if (grid[i][j] == '*')
					cnt = 0;
				else
					assert(false);
		}

		static int round = 0;
		if (k == 1 || round++) break;
		swap(n, m);
		for (int i = 0; i < 2000; ++i)
			for (int j = 0; j < i; ++j)
				swap(grid[i][j], grid[j][i]);
	}
	cout << ans;

	return 0;
}