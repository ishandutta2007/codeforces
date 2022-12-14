#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int maxn = 5e3 + 100;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

int dp[maxn][maxn][3], a[maxn];

int dis (int idx, int idx1) {
	if (a[idx1] < a[idx])
		return 0;
	return a[idx1] - a[idx] + 1;
}

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	memset (dp, 63, sizeof dp);
	for (int i = 0; i <= n; i++) {
		dp[i][0][0] = 0;
		dp[i][0][1] = 0;
	}
	
	dp[1][1][1] = 0;
	a[0] = -inf;
	a[n + 1] = -inf;
	for (int i = 2; i <= n + 1; i++) {
		for (int j = 1; j <= (n + 1) / 2; j++) {
			int tmp = a[i - 1] - a[i - 2] - 1;
			tmp = max (tmp, a[i - 1] - a[i] - 1);
			tmp = max (tmp, 0);
			dp[i][j][1] = min (dp[i - 2][j - 1][1] + max (dis (i - 2, i - 1), dis(i, i - 1)), dp[i - 2][j - 1][0] + dis (i, i - 1));
			dp[i][j][0] = min (dp[i - 1][j][1] + dis (i - 1, i), dp[i - 1][j][0]);
//			cout << i << " " << j << " " << 1 << " " << dp[i][j][1] << endl;
//			cout << i << " " << j << " " << 0 << " " << dp[i][j][0] << endl;
		}
	}
	for (int i = 1; i <= (n + 1) / 2; i++)
		cout << dp[n + 1][i][0] << " ";
	cout << endl;
	return 0;
}