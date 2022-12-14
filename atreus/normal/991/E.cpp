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
const int maxn = 2e5 + 50;
const int Maxn = 5e3 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll dp[20][40], c[500][500];
int a[30];

int main() {
	ios_base::sync_with_stdio(false);
	ll n, cnt = 0;
	cin >> n;
	while (n > 0) {
		int k = n % 10;
		if (k == 0)
			k = 10;
		a[k] ++;
		n /= 10;
		cnt ++;
	}
	c[0][0] = 1;
	for (int i = 1; i <= 50; i++) {
		c[0][i] = 1;
		for (int j = 1; j <= i; j++)
			c[j][i] = c[j][i - 1] + c[j - 1][i - 1];
	}
	dp[0][0] = 1;
	int tmp = 1;
	for (int i = 1; i <= 10; i++) {
		if (a[i] == 0) {
			for (int j = 0; j <= cnt; j++)
				dp[i][j] = dp[i - 1][j];
			continue;
		}
		for (int j = tmp; j <= cnt; j++) {
			for (int k = j - 1; k >= max (j - a[i], tmp - 1); k --) {
				int ted = j - k;
				if (i == 10)
					dp[i][j] += c[ted][j - 1] * dp[i - 1][k];
				else
					dp[i][j] += c[ted][j] * dp[i - 1][k];
			}
//			cout << i << " " << j << " " << dp[i][j] << endl;
		}
		tmp += (a[i] > 0);
	}
	ll k = 0;
	for (int i = tmp - 1; i <= cnt; i++) {
		k += dp[10][i];
	}
	cout << k << endl;
}