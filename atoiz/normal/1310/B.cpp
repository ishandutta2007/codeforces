/*input
3 4
1 3 5 7

*/

#include <iostream>

using namespace std;

const int MAXN = 17, INF = 1e8;
int dp[1 << MAXN][2][2];
bool fav[1 << MAXN];

void maximize(int &x, int y)
{ x = (x < y ? y : x); }

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N, K;
	cin >> N >> K;
	while (K--) {
		int i;
		cin >> i;
		fav[i - 1] = true;
	}

	--N;
	for (int i = 0; i < (1 << N); ++i) {
		int k = (int) fav[i << 1] + fav[i << 1 | 1];
		for (int x = 0; x < 2; ++x) {
			for (int y = 0; y < 2; ++y) {
				dp[(1 << N) + i][x][y] = (x + y == k ? (k >= 1) : -INF);
			}
		}
	}

	for (int i = (1 << N) - 1; i >= 1; --i) { 
		for (int x = 0; x < 2; ++x) { 
			for (int y = 0; y < 2; ++y) { 
				dp[i][x][y] = -INF; 
			} 
		}

		int i0 = i << 1, i1 = i << 1 | 1;
		for (int x0 = 0; x0 < 2; ++x0) {
			for (int x1 = 0; x1 < 2; ++x1) {
				for (int y0 = 0; y0 < 2; ++y0) {
					for (int y1 = 0; y1 < 2; ++y1) {
						int k = dp[i0][x0][y0] + dp[i1][x1][y1] + (x0 or x1) + (y0 or y1);

						maximize(dp[i][x0][x1 or y0 or y1], k + (x1 or y0 or y1));
						maximize(dp[i][x1][x0 or y0 or y1], k + (x0 or y0 or y1));
					}
				}
			}
		}
	}

	int ans = 0;
	for (int x = 0; x < 2; ++x) {
		for (int y = 0; y < 2; ++y) {
			maximize(ans, dp[1][x][y] + (x or y));
		}
	}
	cout << ans << endl;
}