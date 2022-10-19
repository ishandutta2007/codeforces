/*input
1 1
1 1 1

*/

// https://ideone.com/oxuDlE



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

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

const int MAXN = 300007;
const long long INF = 1e15;
int N, M;
vector<int> G[MAXN], add[MAXN], rem[MAXN];
int st[MAXN], en[MAXN], vis[MAXN], curTime = 0;
long long cost[MAXN];
long long cur_min[MAXN << 2], lazy[MAXN << 2], dp[MAXN];

void inc(long long &x, long long y) 
{
	x = ((x += y) > INF ? INF : x);
}
	
void push(int root, int lo, int hi)
{
	if (lo < hi && lazy[root]) {
		inc(cur_min[root << 1], lazy[root]);
		inc(lazy[root << 1], lazy[root]);
		inc(cur_min[root << 1 | 1], lazy[root]);
		inc(lazy[root << 1 | 1], lazy[root]);
	}
	lazy[root] = 0;
}

void upd(int l, int r, long long x, int root = 1, int lo = 0, int hi = M - 1)
{
	if (hi < l || r < lo) return;
	if (l <= lo && hi <= r) {
		inc(cur_min[root], x);
		inc(lazy[root], x);
		return;
	}

	int mid = (lo + hi) >> 1;
	push(root, lo, hi);
	upd(l, r, x, root << 1, lo, mid);
	upd(l, r, x, root << 1 | 1, mid + 1, hi);
	cur_min[root] = min(cur_min[root << 1], cur_min[root << 1 | 1]);
}

long long get(int l, int r, int root = 1, int lo = 0, int hi = M - 1)
{
	if (hi < l || r < lo) return INF;
	if (l <= lo && hi <= r) return cur_min[root];

	int mid = (lo + hi) >> 1;
	push(root, lo, hi);
	return min(get(l, r, root << 1, lo, mid), get(l, r, root << 1 | 1, mid + 1, hi));
}

void dfs(int u, int p)
{
	st[u] = curTime;
	FORA(w, add[u]) vis[w] = curTime++;

	long long total = 0;
	FORA(v, G[u]) if (v != p) {
		dfs(v, u);
		total += dp[v];
	}

	en[u] = curTime - 1;

	FORA(v, G[u]) if (v != p) {
		upd(st[v], en[v], total - dp[v]);
	}
	FORA(w, add[u]) upd(vis[w], vis[w], cost[w] + total);
	if (u != 1) FORA(w, rem[u]) upd(vis[w], vis[w], INF);

	dp[u] = get(st[u], en[u]);
	if (dp[u] == INF) {
		cout << -1 << endl;
		exit(0);
	}
}

signed main()
{
	scanf("%d %d", &N, &M);
	if (N == 1) return cout << 0 << endl, 0;
	// cout << N << ' ' << M << endl;
	FOR(i, 0, N - 2) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	FOR(i, 0, M - 1) {
		int u, v;
		scanf("%d %d %I64d", &u, &v, &cost[i]);
		add[u].push_back(i);
		rem[v].push_back(i);
	}

	dfs(1, 0);
	cout << dp[1] << endl;

	return 0;
}