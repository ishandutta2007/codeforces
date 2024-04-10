#include <bits/stdc++.h>

using namespace std;

int A[15][15], r, c, n, k, i, j, s, t, x, y;

int main() {
	memset(A, 0, sizeof A);
	cin >> r >> c >> n >> k;
	for (i = 1; i <= n; i++)
		cin >> x >> y, A[x][y] = 1;
	
	int Ret = 0;
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			for (s = 1; s <= r; s++) {
				for (t = 1; t <= c; t++) {
					int cnt = 0;
					for (int p = i; p <= s; p++)
						for (int q = j; q <= t; q++)
							cnt += A[p][q];
					if (cnt >= k) ++Ret;
				}
			}
		}
	}
	
	cout << Ret << endl;
	return 0;
}