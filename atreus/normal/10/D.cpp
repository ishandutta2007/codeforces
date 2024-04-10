#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 550 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int dp[maxn][maxn], a[maxn], b[maxn], par[maxn];
vector <int> v;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = 1;
				for (int k = i - 1; k >= 1; k--) {
					if (a[k] < a[i]) {
						if (dp[i][j] < dp[k][j - 1] + 1) {
							dp[i][j] = max (dp[i][j], dp[k][j - 1] + 1);
							par[i] = k;
						}
					}
				}
			}
			else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	int x = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i][m] > dp[x][m])
			x = i;
	}
	cout << dp[x][m] << endl;
	while (x != 0) {
		v.PB (a[x]);
		x = par[x];
	}
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
	cout << endl;
}