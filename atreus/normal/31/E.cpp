#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;
const int mod = 12713;
ll tav[50], dp[50][50], par[50][50];

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	string s;
	cin >> n >> s;
	s = " " + s;

	tav[0] = 1;
	for (int i = 1; i <= 18; i++)
		tav[i] = tav[i - 1] * 10;
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i > 0) {
				dp[i][j] = dp[i - 1][j] + (int)(s[i + j] - '0') * tav[n - i];
				par[i][j] = 1;
			}
			if (j > 0) {
				ll tmp = dp[i][j];
				dp[i][j] = max (dp[i][j], dp[i][j - 1] + (int)(s[i + j] - '0') * tav[n - j]);
				if (tmp != dp[i][j]) 
					par[i][j] = 2;
			}
		}
	}

	int x = n, y = n;
	string k;
	while (x > 0 or y > 0) {
		if (par[x][y] == 1) {
			k = 'H' + k;
			x --;
		}
		else {
			k = 'M' + k;
			y --;
		}
	}
	cout << k << endl;
}