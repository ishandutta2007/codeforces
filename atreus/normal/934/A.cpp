#include <iostream>
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
const int inf = 1e9 + 7, maxn = 1000 + 100;
ll a[maxn], dp[maxn], b[maxn];

int main(){ 
	ios_base::sync_with_stdio(false);
	memset (dp, -63, sizeof dp);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i] = max(dp[i], a[i] * b[j]);
		}
	}
	sort (dp + 1, dp + n + 1);
	cout << dp[n - 1] << endl;
}