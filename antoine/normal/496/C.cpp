#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
string grid[100];
bool diff[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> grid[i];

	int ans = 0;
	for (int j = 0; j < m; ++j) {
		bool isSorted = [&]() {
			for(int i = 0; i + 1 < n; ++i) {
				if(!diff[i] && grid[i][j] > grid[i+1][j])
				return false;
			}
			return true;
		}();
		if (!isSorted) {
			ans++;
			continue;
		}
		for (int i = 0; i + 1 < n; ++i)
			diff[i] |= grid[i][j] != grid[i + 1][j];
	}

	cout << ans << '\n';
	return 0;
}