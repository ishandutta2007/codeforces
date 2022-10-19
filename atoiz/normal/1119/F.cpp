// https://codeforces.com/blog/entry/91030?#comment-794573

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
#include <iomanip>
#include <functional>
#include <array>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)
#define SORT(a) sort(begin(a), end(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

template <typename T>
ostream& operator<< (ostream &os, vector<T> &vec) 
{
	if (vec.empty()) return os;
	for (int i = 0; i < (int) vec.size() - 1; ++i) os << vec[i] << ' ';
	return os << vec.back();
}

void debug() {}
template <typename T, typename... Args>
void debug(T t, Args... a)
{
	#ifdef LOCAL
	cout << flush;
	cerr << t;
	debug(a...);
	cerr << flush;
	#endif
}

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

mt19937 rng((int) chrono::system_clock().now().time_since_epoch().count());

// start of code

const ll INF = 1e10;

struct BIT {
	vector<int> cnt;
	vector<ll> val, tot;
	BIT(vector<ll> _val = {}) {
		val.swap(_val);
		val.insert(val.begin(), -1);
		cnt.assign(((int) val.size()), 0);
		tot.assign(((int) val.size()), 0);
	}

	void toggle(ll x) {
		int i = int(lower_bound(val.begin(), val.end(), x) - val.begin());
		for (; i < ((int) val.size()); i += i & (-i)) {
			++cnt[i];
			tot[i] += x;
		}
	}

	ll get(int k) {
		if (k <= 0) return 0;
		int i = 0;
		ll res = 0;
		for (int j = (int) __lg(val.size()) + 1; j >= 0; --j) {
			if (i + (1 << j) < ((int) val.size()) && cnt[i + (1 << j)] <= k) {
				i += (1 << j);
				k -= cnt[i];
				res += tot[i];
			}
		}
		++i;
		if (i < ((int) val.size())) res += val[i] * k;
		else res += INF * k;
		return res;
	}
};

const int MAXN = 250005;
int N, par[MAXN], S, deg[MAXN];
ll W[MAXN];
int go[MAXN], dead[MAXN], last;
vector<int> G[MAXN];
vector<ll> costAlive[MAXN];
BIT costDead[MAXN];

void dfs(int u, int p) {
	par[u] = p;
	go[u] = last, last = u;
	dead[u] = false;
	for (auto &v : G[u]) if (v != p) dfs(v, u); 
}

// int main() {
// 	vector<ll> val = {0, 1, 2, 3, 4, 5, 6, 7};
// 	BIT bit(val);
// 	cout << bit.get(1) << endl;
// 	bit.toggle(2);
// 	bit.toggle(4);
// 	bit.toggle(5);
// 	cout << bit.get(0) << endl;
// 	cout << bit.get(1) << endl;
// 	cout << bit.get(2) << endl;
// 	cout << bit.get(3) << endl;
// }

std::vector<long long> minimum_closure_costs(int _N, std::vector<int> U,
                                             std::vector<int> V,
                                             std::vector<int> _W) {

	N = _N;
	FOR(i, 0, N - 2) {
		++U[i], ++V[i];
		G[U[i]].push_back(V[i]);
		G[V[i]].push_back(U[i]);
		++deg[U[i]], ++deg[V[i]];
	}
	last = 0;
	dfs(1, 0);
	FOR(i, 0, N - 2) {
		if (par[U[i]] == V[i]) swap(U[i], V[i]);
		W[V[i]] = _W[i];
	}
	W[1] = INF;
	FOR(u, 1, N) {
		vector<ll> val = {W[u]};
		for (auto &v : G[u]) val.push_back(W[v]);
		sort(ALL(val)), val.erase(unique(ALL(val)), val.end());
		costDead[u] = BIT(val);
	}

	S = N + 1;
	go[S] = last;

	vector<ll> ans(N, 0);
	FOR(k, 0, N - 1) {
		int u, v;
		for (u = S; u; u = go[u]) {
			while ((v = go[u]) && deg[v] <= k) {
				go[u] = go[v];
				dead[v] = true;
				// fprintf(stderr, "kill %d\n", v);
				if (par[v]) costDead[par[v]].toggle(W[v]);
			}
		}
		for (u = go[S]; u; u = go[u]) costAlive[u].clear();

		ll curAns = 0;
		for (u = go[S]; u; u = go[u]) {
			sort(ALL(costAlive[u]));
			int toRem = max(0, deg[u] - k);

			ll keepPar = costDead[u].get(toRem), remPar = costDead[u].get(toRem - 1) + W[u];
			ll prefSum = 0;
			FOR(i, 0, SZ(costAlive[u]) - 1) {
				prefSum += costAlive[u][i];

				keepPar = min(keepPar, costDead[u].get(toRem - (i + 1)) + prefSum);
				remPar = min(remPar, costDead[u].get(toRem - 1 - (i + 1)) + W[u] + prefSum);
			}
			// fprintf(stderr, "k = %d, u = %d, keepPar = %lld, remPar = %lld, toRem = %d\n", k, u, keepPar, remPar, toRem);

			// fprintf(stderr, "k = %d, u = %d, keepPar = %lld, remPar = %lld\n", k, u, keepPar, remPar);
			curAns += min(keepPar, remPar);
			if (par[u] && !dead[par[u]]) {
				costAlive[par[u]].push_back(remPar - min(keepPar, remPar));
			}
		}

		ans[k] = curAns;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> u(n - 1), v(n - 1), w(n - 1);
	FOR(i, 0, n - 2) cin >> u[i] >> v[i] >> w[i];
	FOR(i, 0, n - 2) --u[i], --v[i];
	auto ans = minimum_closure_costs(n, u, v, w);
	for (auto k : ans) cout << k << ' ';
}