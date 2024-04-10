#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int dp[50][50][51][51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for(int dx = 1; dx < n+1; dx++)
		for (int dy = 1; dy < n+1; dy++) 
			for (int x = 0; x < n; x++)
				for (int y = 0; y < n; y++){
					if (dx + x > n || dy + y > n)
						break;
					dp[x][y][dx][dy] = n;
					if (dx == 1 && dy == 1)
						if (a[x][y] == '.')
							dp[x][y][dx][dy] = 0;
						else
							dp[x][y][dx][dy] = 1;
					else {
						for (int i = x; i < min(x + dx, n); i++) {
							int b;
							b = 0;
							for (int j = y; j < min(y + dy, n); j++) {
								if (a[i][j] != '.') {
									b = 1;
									break;
								}
							}
							if (b == 0) {
								int a1, a2;
								a1 = 0;
								a2 = 0;
								if (i - x > 0)
									a1 = dp[x][y][i-x][dy];
								if (dx - (i - x) - 1 > 0)
									a2 = dp[i+1][y][dx-(i-x)-1][dy];
								dp[x][y][dx][dy] = min(dp[x][y][dx][dy], min(a1 + a2, max(dx, dy)));
							}
						}
						for (int j = y; j < min(y + dy, n); j++) {
							int b;
							b = 0;
							for (int i = x; i < min(x + dx, n); i++) {
								if (a[i][j] != '.') {
									b = 1;
									break;
								}
							}
							if (b == 0) {
								int a1, a2;
								a1 = 0;
								a2 = 0;
								if (j - y > 0)
									a1 = dp[x][y][dx][j - y];
								if (dy - (j - y) - 1 > 0)
									a2 = dp[x][j+1][dx][dy - (j - y)-1];
								dp[x][y][dx][dy] = min(dp[x][y][dx][dy], min(a1 + a2, max(dx, dy)));
							}
						}
						dp[x][y][dx][dy] = min(dp[x][y][dx][dy], max(dx, dy));
					}
			}
	cout << dp[0][0][n][n];
	return 0;
}