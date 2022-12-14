#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
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
typedef long double ld;
typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 5e4 + 100;
const int inf = (int)1e9;
const int block = 400;

int n, k;

ll ans;

vector <int> v[maxn];

int dp[maxn][510];

void dfs (int u, int par = -1) {
	dp[u][0] = 1;
	for (auto w : v[u]) {
		if (w != par) {
			dfs (w, u);
			for (int i = 1; i <= k and dp[w][i - 1] > 0; i++) {
				dp[u][i] += dp[w][i - 1];
			}
		}
	}
	ll tmp = 0;
	for (auto w : v[u]) {
		if (w != par) {
			for (int i = 1; i < k; i++) {
				tmp += dp[w][i - 1] * (dp[u][k - i] - dp[w][k - i - 1]);
			}
		}
	}
	ans += tmp / 2 + dp[u][k];
}

int main () { 
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	dfs (1);
	cout << ans << endl;
}