#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long ll;
const int maxn = 1e6 + 100;
bool mark[maxn];
int dp[maxn];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++){
		int clockt;
		cin >> clockt;
		mark[clockt] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= maxn - 50; i++){
		dp[i] = dp[i - 1];
		if (mark[i])
			dp[i] ++;
		if (i >= m and mark[i - m])
			dp[i] --;
		if (dp[i] == k){
			ans ++;
			dp[i] --;
			mark[i] = 0;
		}
	}
	cout << ans << endl;
}