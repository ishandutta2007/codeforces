/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int ar[n + 2][m + 2];
	memset(ar, 0, sizeof(ar));
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		ar[a][b] = 1;
		if ((ar[a - 1][b] && ar[a - 1][b - 1] && ar[a][b - 1])
				|| (ar[a + 1][b] && ar[a + 1][b + 1] && ar[a][b + 1])
				|| (ar[a - 1][b] && ar[a - 1][b + 1] && ar[a][b + 1])
				|| (ar[a + 1][b] && ar[a + 1][b - 1] && ar[a][b - 1])) {
			cout << (i + 1);
			return 0;
		}
	}
	cout << 0;
}