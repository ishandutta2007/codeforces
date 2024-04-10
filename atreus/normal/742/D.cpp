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
const int maxn = 2e3 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll w[maxn], b[maxn], dp[maxn][maxn], bti, wei, cnt = 1, ans[maxn][maxn];
bool visited[maxn];
vector <int> v[maxn], cmp[maxn];
vector <pair <ll, ll> > nap;

void dfs (int u) {
	visited[u] = 1;
	bti += b[u];
	wei += w[u];
	cmp[cnt].PB (u);
	for (auto w : v[u])
		if (!visited[w])
			dfs (w);
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n, m, W;
	cin >> n >> m >> W;
	nap.PB (MP (-1, -1));
	for (int i = 1; i <= n; i++) 
		cin >> w[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= m; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			bti = 0;
			wei = 0;
			dfs (i);
			nap.PB (MP (wei, bti));
			cnt ++;
		}
	}

	for (int i = 1; i < nap.size(); i++) {
		ll p = nap[i].F, q = nap[i].S;
		for (auto k : cmp[i])
			for (int j = w[k]; j <= W; j++) 
				ans[i][j] = max (ans[i][j], dp[i - 1][j - w[k]] + b[k]);
		for (int j = p; j <= W; j++) 
			dp[i][j] = max (dp[i][j], dp[i - 1][j - p] + q);		
		for (int j = 0; j <= W; j++) {
			dp[i][j] = max (dp[i][j], ans[i][j]);
			dp[i][j] = max (dp[i][j], dp[i - 1][j]);
		}
	}
	ll tmp = 0;
	for (int j = 0; j <= W; j++)
		tmp = max (tmp, dp[nap.size() - 1][j]);
	cout << tmp << endl;
}