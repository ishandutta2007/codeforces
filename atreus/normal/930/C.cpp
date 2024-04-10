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
const int INF = 1e9 + 7, maxn = 1e5 + 50;
int tmp[maxn], a[maxn], dp[maxn], lef[maxn], rig[maxn];

int main(){
    ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		int l, r;
		cin >> l >> r;
		tmp[l] ++;
		tmp[r + 1] --;
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++){
		cnt += tmp[i];
		a[i] = cnt;
	}

	memset (dp, 63, sizeof dp);
	dp[0] = - (1ll << 30);
	for (int i = 1; i <= m; i++){
		int idx = upper_bound (dp, dp + m, a[i]) - dp;
		dp[idx] = a[i];
		lef[i] = idx - 1;
	}

	memset (dp, 63, sizeof dp);
	dp[0] = - (1ll << 30);
	for (int i = m; i >= 1; i--){
		int idx = upper_bound (dp, dp + m, a[i]) - dp;
		dp[idx] = a[i];
		rig[i] = idx - 1;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = max (ans, lef[i] + rig[i] + 1);
	cout << ans << endl;
}