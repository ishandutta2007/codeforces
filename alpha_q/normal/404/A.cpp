#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	char g[305][305];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];
	char a = g[1][1], b = g[1][2];
	if (a == b) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if ((i == j && g[i][j] != a) || (i + j == n + 1 && g[i][j] != a)) {
				cout << "NO\n";
				return 0;
			} else if (i != j && i + j != n + 1 && g[i][j] != b) {
				cout << "NO\n";
				return 0;
			}
		}
	cout << "YES\n";
	return 0;
}