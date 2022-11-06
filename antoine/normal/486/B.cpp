#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, n;
	cin >> m >> n;
	vector<vector<int>> A(m, vector<int>(n, 1));
	auto B = A;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> B[i][j];
			if (!B[i][j]) {
				for (int k = 0; k < n; ++k)
					A[i][k] = 0;
				for (int k = 0; k < m; ++k)
					A[k][j] = 0;
			}
		}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (B[i][j]) {
				bool ok = false;
				for (int k = 0; k < n; ++k)
					ok |= A[i][k];
				for (int k = 0; k < m; ++k)
					ok |= A[k][j];
				if (!ok) {
					cout << "NO";
					return 0;
				}
			}
	cout << "YES";
	for (int i = 0; i < m; ++i) {
		cout << '\n';
		for (int j = 0; j < n; ++j) {
			if (j)
				cout << ' ';
			cout << A[i][j];
		}
	}
	return 0;
}