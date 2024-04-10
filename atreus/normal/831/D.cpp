#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

const long long inf = 1e9;
const int maxn = 3e3 + 100;
long long a[maxn], b[maxn], dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k, l;
	cin >> n >> k >> l;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= k; i++)
		cin >> b[i];
	sort (a + 1, a + n + 1);
	sort (b + 1, b + k + 1);
	memset (dp, 63, sizeof dp);
	for (int i = 0; i <= k; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++){
			dp[i][j] = min (dp[i][j - 1], max (dp[i - 1][j - 1], abs (a[i] - b[j]) + abs (b[j] - l)));
//			cout << i << " " << j << " -> " << dp[i][j] << endl;
		}
	}
	cout << dp[n][k] << endl;
}