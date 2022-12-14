#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int inf = 1e9 + 7, maxn = 50 + 100;
ll dp[maxn][maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);
	memset (dp, 63, sizeof dp);
	for (int i = 1; i <= 30; i++){
		for (int j = 1; j <= 30; j++){
			dp[i][j][0] = 0;
			if (i * j <= 50)
				dp[i][j][i * j] = 0;
			for (int k = 1; k <= min (50, i * j); k++){
				for (int i1 = 1; i1 < i; i1++){
					for (int k1 = 0; k1 <= k; k1++){
						dp[i][j][k] = min (dp[i][j][k], dp[i1][j][k1] + dp[i - i1][j][k - k1] + j * j);
					}
				}
				for (int j1 = 1; j1 < j; j1++){
					for (int k1 = 0; k1 <= k; k1++){
						dp[i][j][k] = min (dp[i][j][k], dp[i][j1][k1] + dp[i][j - j1][k - k1] + i * i);
					}
				}
			}
		}
	}
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int n, m, k;
		cin >> n >> m >> k;
		cout << dp[n][m][k] << endl;
	}
}