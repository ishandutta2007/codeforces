#include <iostream>
using namespace std;

const int N = 21;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N][N];
int sum[1 << N];
int dp[1 << N];
int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i < n; i++) {
		a[s[i] - 'a'][s[i - 1] - 'a']++;
		a[s[i - 1] - 'a'][s[i] - 'a']++;
	}
	for (int i = 1; i < (1 << m); i++) {
		int x = __builtin_ctz(i);
		sum[i] = sum[i - (1 << x)];
		for (int j = 0; j < m; j++) {
			if (j != x) {
				if (get(i, j)) {
					sum[i] -= a[x][j];
				}
				else {
					sum[i] += a[x][j];	
				}
			}
		}
	}
	for (int i = 1; i < (1 << m); i++) {
		dp[i] = inf;
	//	int x = __builtin_ctz(i);
		for (int j = 0; j < m; j++) {
			if (get(i, j)) {
				dp[i] = min(dp[i], dp[i - (1 << j)]);
			}
		}
		dp[i] += sum[i];
//		cout << i << " " << sum[i] << " " << dp[i] << endl;
	}
	cout << dp[(1 << m) - 1] << endl;
	return 0;
}