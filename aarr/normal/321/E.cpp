#include <iostream>
using namespace std;


const int N = 4005, K = 805, inf = 1000 * 1000 * 1000 + 7;

int a[N][N];
int ps[N][N];
int dp[N][K];

int get(int x, int y, int k) {
	return ps[y][y] - ps[y][x] - ps[x][y] + ps[x][x] + dp[x][k];
}

void dq(int k, int l, int r, int L, int R) {
	int md = (l + r) / 2;
	int x = L;
	for (int i = L; i <= R && i < md; i++) {
		if (get(i, md, k - 1) < dp[md][k]) {
			x = i;
			dp[md][k] = get(i, md, k - 1);
		}
	}
	if (r - l == 1) {
		return;
	}
	dq(k, l, md, L, x);
	dq(k, md, r, x, R);
}
int main() {
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s;
	getline(cin, s);
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		for (int j = 1; j <= n; j++) {
			ps[i][j] = (int) ((char) s[(j - 1) * 2] - '0') + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
		//	cout << i << " " << j << " " << ps[i][j] << endl;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = inf;
		}
	}
	for (int i = 1; i <= k; i++) {
		dq(i, 1, n + 1, 0, n);
	}
	cout << dp[n][k] / 2;
	return 0;
}