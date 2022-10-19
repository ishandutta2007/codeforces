#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k*2; ++i) {
		int a, b;
		cin >> a >> b;
	}
	cout << (n - 1) + (m - 1) + (n * m - 1) << endl;
	for (int i = 0; i < n - 1; ++i)
		cout << "U";
	for (int i = 0; i < m - 1; ++i)
		cout << "R";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m-1; ++j) {
			if (i % 2 == 0)
				cout << "L";
			else
				cout << "R";
		}
		if (i == n - 1)
			break;
		cout << "D";
	}
}