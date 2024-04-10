#include <iostream>
#include <algorithm>
using namespace std;

const int N = 205;
const int C = 10 * 1000 + 5;
const long long inf = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 7;

int c[N];
long long dp[N][N];
bool mark[N][N];
pair <int, int> a[N];
int b[N];

int main() {
	int n, m;
	cin >> n >> m;
	long long k;
	cin >> k;
	int q = n + m - 1;
	for (int i = 1; i <= q; i++) {
		c[i] = C;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			c[i + j + 1] = min(c[i + j + 1], x);
		}
	}
	for (int i = 1; i <= q; i++) {
		a[i] = {c[i], i};
	}
//	for (int i = 1; i <= q; i++) {
//		cout << "43 " << i << " " << c[i] << endl;
//	}
	sort(a + 1, a + q + 1);
	for (int i = 1; i <= q; i++) {
		int x = a[i].second;
	//	cout << "49 " << x << endl;
		for (int i = 0; i <= q; i++) {
			for (int j = 0; j <= q; j++) {
				dp[i][j] = 0;
				mark[i][j] = false;
			}
		}
		dp[0][0] = 1;
		b[x] = 1;
		for (int i = 1; i <= q; i++) {
			for (int j = 1; j <= q; j++) {
				if (b[i] != -1) {
					dp[i][j] += dp[i - 1][j - 1];
					mark[i][j] |= mark[i - 1][j - 1];
				//	if (dp[i][j] >= inf) {
				//		mark[i][j] = true;
				//	}
				}
				if (b[i] != 1) {
					dp[i][j] += dp[i - 1][j + 1];
					mark[i][j] |= mark[i - 1][j + 1];
					if (dp[i][j] >= inf) {
						mark[i][j] = true;
					}
				}
			}
			if (b[i] != 1) {
				dp[i][0] = dp[i - 1][1];
				mark[i][0] |= mark[i - 1][1];
			}
		}
	//	for (int i = 1; i <= q; i++) {
	//		cout << b[i] << " ";
	//	}
	//	cout << endl << "73 " << dp[q][0] << endl;
		if (dp[q][0] < k && !mark[q][0]) {
			b[x] = -1;
			k -= dp[q][0];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i + j + 1] == 1) {
				cout << '(';
			}
			else {
				cout << ')';
			}
		}
		cout << endl;
	}
	return 0;
}