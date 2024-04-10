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
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	const int prime = 100447;

	int n, m;
	cin >> n >> m;

	cout << prime << ' ' << prime << '\n';
	for (int i = 1; i <= n - 2; ++i) {
		cout << i << ' ' << (i + 1) << ' ' << 1 << "\n";
	}
	cout << (n - 1) << ' ' << n << ' ' << (prime - (n - 2)) << "\n";
	
	m -= (n - 1);
	for(int i = 1; i <= n; ++i)
		for (int j = i + 2; j <= n; ++j) {
			if (j == i + 1)
				continue;
			if (!m) return 0;
			cout << i << ' ' << j << ' ' << (int)1e9 << '\n';
			--m;
		}
	return 0;
}