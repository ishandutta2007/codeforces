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
const int mod = 1e9 + 7, maxn = 5e3 + 100;
ll dp[maxn][maxn], par[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	dp[0][a] = 1;
	for (int i = 1; i <= n; i++)
		par[i] = par[i - 1] + dp[0][i];

	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= n; j++){
			if (j == b)
				continue;
			if (j < b) {
				int mid = (j + b - 1) / 2;
				dp[i][j] = par[mid] - dp[i - 1][j];
			}
			if (j > b){
				int mid = (j + b + 0) / 2;
				dp[i][j] = par[n] - par[mid] - dp[i - 1][j];
			}
			dp[i][j] += mod;
			dp[i][j] += mod;
			dp[i][j] %= mod;
//			cout << i << " - " << j << " = " << dp[i][j] << endl;
		}
		for (int j = 1; j <= n; j++){
			par[j] = par[j - 1] + dp[i][j];
			par[j] %= mod;
		}
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum = (sum + dp[k][i]) % mod;
	cout << sum << endl;
}