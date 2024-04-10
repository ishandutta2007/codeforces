#include <iostream>
using namespace std;

const int N = 4005, SQ = 65;

int a[N];
int ps[N];
int dp0[N][N][2];
int dp1[N][N][2];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	for (int k = SQ - 1; k; k--) {
		for (int i = k; i <= n + 1; i++) {
			for (int l = max(1, (n - i) / 2 - SQ); l + i <= n + 1 && l <= (n - i) / 2 + SQ; l++) {
				int r = l + i;
				if (i >= k) {
					dp0[l][i][k % 2] = ps[l + k - 1] - ps[l - 1] - dp1[l + k][i - k][k % 2];
					dp1[l][i][k % 2] = ps[r - 1] - ps[r - k - 1] - dp0[l][i - k][k % 2];
				}
				if (i > k) {
					dp0[l][i][k % 2] = max(dp0[l][i][k % 2], ps[l + k] - ps[l - 1] - dp1[l + k + 1][i - k - 1][1 - (k % 2)]);
					dp1[l][i][k % 2] = max(dp1[l][i][k % 2], ps[r - 1] - ps[r - k - 2] - dp0[l][i - k - 1][1 - (k % 2)]);
				}
			//	cout << l << " " << i << " " << k << endl;
			}
		}
	}
	cout << dp0[1][n][1] << endl;
	return 0;
}