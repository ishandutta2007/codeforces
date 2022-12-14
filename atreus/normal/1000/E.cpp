#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
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
const int maxn = 3e5 + 500;;
const int mod = 998244353;
const ll inf = (1ll << 62);
int ans, subh[maxn], hei[maxn], dp[maxn];
vector <int> v[maxn];
bool visited[maxn];

void dfs (int u, int h, int par) {
	visited[u] = 1;
	subh[u] = h;
	hei[u] = h;
	int mx1 = 0, mx2 = 0;
	for (auto w : v[u]) {
		if (!visited[w]) {
			dfs (w, h + 1, u);
			subh[u] = min (subh[u], subh[w]);
			dp[w] += (subh[w] > h);
			dp[u] = max (dp[u], dp[w]);
			if (dp[w] >= mx1) {
				mx2 = mx1;
				mx1 = dp[w];
			}
			else if (dp[w] > mx2)
				mx2 = dp[w];
		}
		else if (w != par)
			subh[u] = min (subh[u], hei[w]);
	}
	ans = max (ans, dp[u]);
	ans = max (ans, mx2 + mx1);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	dfs (1, 0, 0);
	cout << ans << endl;
}