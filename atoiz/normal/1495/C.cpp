/*input
1
3 4
....
.X.X
....
...X
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		string a, b, c;
		for (int i = 0; i < n; i += 3) {
			if (i + 0 < n) cin >> a;
			if (i + 1 < n) cin >> b;
			if (i + 2 < n) cin >> c;
			fill(a.begin(), a.end(), 'X');

			if (i + 2 < n) {
				bool connectAll = i + 3 == n;
				bool hasConnect = false;
				for (int j = 0; j < m; ++j) {
					if (b[j] == 'X' || c[j] == 'X') {
						if (connectAll || !hasConnect) {
							b[j] = c[j] = 'X';
							hasConnect = true;
						}
					}
				}

				if (!hasConnect) {
					b[0] = c[0] = 'X';
				}
			}

			if (i + 0 < n) cout << a << '\n';
			if (i + 1 < n) cout << b << '\n';
			if (i + 2 < n) cout << c << '\n';
		}
	}
}