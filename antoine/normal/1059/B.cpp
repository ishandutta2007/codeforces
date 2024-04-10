#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	vector<vector<bool>> ok(n, vector<bool>(m, false));
	for(int i = 1; i + 1 < n; ++i)
		for(int j = 1; j + 1 < m; ++j)
			// if(a[i][j] == '.') {
				[&]() {
					for(int x = i - 1; x <= i + 1; ++x)
						for(int y = j - 1; y <= j + 1; ++y)
							if(x != i || y != j)
								if(a[x][y] != '#')
									return;
					for(int x = i - 1; x <= i + 1; ++x)
						for(int y = j - 1; y <= j + 1; ++y)
							if(x != i || y != j)
								ok[x][y] = true;
				}();

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m;++j)
			if(a[i][j] == '#' && !ok[i][j]) {
				cout << "NO\n";
				return 0;
			}
	cout << "YES\n";
	return 0;
}