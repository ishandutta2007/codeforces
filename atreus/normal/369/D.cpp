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
const int inf = 1e9 + 7, maxn = 3000 + 100;
int p[maxn], dp[maxn][maxn];
bool have100[maxn], mark[maxn];

int main(){
    ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	memset (dp, 63, sizeof dp);
	dp[1][2] = 0;
	for (int i = n; i >= 1; i--){
		have100[i] = have100[i + 1];
		mark[i] = mark[i + 1];
		if (p[i] == 100)
			have100[i] = 1;
		if (p[i] != 0)
			mark[i] = 1;
	}
	for (int i = 1; i <= n + 1; i++){
		if (p[i - 1] != 100 and mark[i])
			dp[i][i + 1] = min (dp[i][i + 1], dp[i - 1][i] + 1);
		for (int j = i - 2; j >= 1; j--){
			if (p[j] != 100 and mark[i])
				dp[i][i + 1] = min(dp[i][i + 1], dp[j][i] + 1);
			if (p[j] != 0 and mark[i - 1])
				dp[i][i + 1] = min(dp[i][i + 1], dp[j][i - 1] + 1);
		}
		for (int j = i + 2; j <= n + 2; j++){
			if (!have100[j - 1] and p[i] != 0)
				dp[i][j] = dp[i][j - 1] + 1;
		}
	}
	int cnt = (dp[n + 1][n + 2] <= k);
	for (int i = 1; i <= n + 1; i++){
		for (int j = i + 1; j <= n + 1; j++){
//			cout << i << " " << j << " " << dp[i][j] << endl;
			if (dp[i][j] <= k)
				cnt ++;
		}
	}
	cout << cnt << endl;
}