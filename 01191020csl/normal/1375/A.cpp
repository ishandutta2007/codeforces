#include<bits/stdc++.h>
using namespace std;
int f[101][51][51][2];
int a[100];
void solve(int n, int i, int j, int op, int n0) {
	if (!n) {
		for (int i = 1; i <= n0; i++) cout << a[i] << ' ';
		cout << endl;
		return;
	}
	if (op) a[n] *= -1;
	int tmp = f[n][i][j][op];
	if (a[n] > a[n-1] * tmp) --i;
	if (a[n] < a[n-1] * tmp) --j;
	op = tmp == 1 ? 0 : 1;
	solve(n - 1, i, j, op, n0);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		memset(f, 0, sizeof(f));
		f[1][0][0][0] = f[1][0][0][1] = 1;
		for (int i = 2; i <= n; i++)
			for (int j = 0; j <= n/2 && j <= i; j++)
				for (int k = 0; k <= n/2 & k <= i; k++)
					for (int x = 0; x < 2; x++)
						for (int y = 0; y < 2; y++) {
							int a1 = x?-a[i]:a[i], a2 = y?-a[i-1]:a[i-1];
							if (a1 > a2 && j && f[i-1][j-1][k][y]) f[i][j][k][x] = y?-1:1;
							if (a1 == a2 && f[i-1][j][k][y]) f[i][j][k][x] = y?-1:1;
							if (a1 < a2 && f[i-1][j][k-1][y]) f[i][j][k][x] = y?-1:1;
						}
		bool flag = 0;
		for (int i = 0; i <= n/2; i++) {
			for (int j = 0; j <= n/2; j++) {
				if (f[n][i][j][0]) {
					solve(n, i, j, 0, n);
					flag = 1;
					break;
				}
				if (f[n][i][j][1]) {
					solve(n, i, j, 1, n);
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
	}
}