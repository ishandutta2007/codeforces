/*input
3
1 2 1
1 2
2 3

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 200007;
const ll INF = 1e17;
int N, R;
ll H[MAXN], maxH[MAXN], dp[MAXN];
vector<int> G[MAXN];

void dfs(int u, int p) {
	dp[u] = 0;
	for (int v : G[u]) if (v != p) {
		dfs(v, u);
		maxH[u] = max(maxH[u], maxH[v]);
		dp[u] += dp[v];
	}

	if (dp[u] == 0) { // leaf
		dp[u] = maxH[u] = H[u];
		return;
	}

	if (maxH[u] < H[u]) dp[u] += H[u] - maxH[u], maxH[u] = H[u];
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	FOR(i, 1, N) cin >> H[i];	
	FOR(i, 1, N - 1) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	R = int(max_element(H, H + N + 1) - H);
	for (int v : G[R]) dfs(v, R);
	if (SZ(G[R]) == 1) { // R is leaf
		cout << dp[G[R][0]] + 2 * H[R] - maxH[G[R][0]] << endl;
		return 0;
	}

	vector<ll> vec;
	ll ans = 0;
	for (int v : G[R]) {
		ans += dp[v];
		vec.push_back(-maxH[v]);
	}
	nth_element(vec.begin(), vec.begin() + 2, vec.end());
	cout << ans + 2 * H[R] + vec[0] + vec[1] << endl;
	return 0;
}