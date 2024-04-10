#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 5e5 + 5;
const ll INF = 1e18;

struct child {
	ll k, l;
	int idx;
	bool operator <(const child &rhs) const {
		if (k != rhs.k)
			return k > rhs.k;
		return l > rhs.l;
	}
};

int N;
vector <int> adj[MAXN];
int sub[MAXN];
ll sq[MAXN];
ll mini = INF;

void add(int u, int v) {
	adj[u].push_back(v);
}

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
}

int dfs(int x, int p) {
	sub[x] = 1;
	for (auto it : adj[x])
		if (it != p)
			sub[x] += dfs(it, x);
	return sub[x];
}

inline ll sqr(int x) {
	return (ll)x * x;
}

void calc(int x, int p) {
	sq[x] += sqr(sub[x]);
	for (auto it : adj[x])
		if (it != p) {
			sq[it] = sq[x] - sqr(sub[x]) + sqr(sub[x] - sub[it]);
			calc(it, x);
		}
}

bool ccw(child a, child b, child c) {
	return (ld)a.k * (b.l - c.l) + (ld)b.k * (c.l - a.l) + (ld)c.k * (a.l - b.l) >= 0;
}

ll dp(child p, child q) {
	return 2 * p.k * q.k + p.l + q.l;
}

void process(vector <child> v) {
	sort(v.begin(), v.end());
	vector <child> hull;
	for (auto it : v) {
		while (hull.size() > 1 && ccw(hull[(int)hull.size() - 2], hull.back(), it))
			hull.pop_back();
		hull.push_back(it);
	}
	
	for (auto it : v) {
		int lo = 0, hi = (int)hull.size() - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (dp(it, v[mid]) < dp(it, v[mid + 1]))
				hi = mid;
			else
				lo = mid + 1;
		}
		for (int i = -1; i <= 1; i++)
			if (lo + i >= 0 && lo + i < hull.size() && v[lo + i].idx != it.idx)
				mini = min(mini, dp(it, v[lo + i]));
	}
}

ll go(int x, int p) {
	ll res = sq[x];
	vector <child> cands;
	for (auto it : adj[x]) 
		if (it != p) {
			ll tmp = go(it, x);
			res = min(res, tmp);
			cands.push_back({sub[it], tmp - sq[x] + sqr(sub[x]) - sqr(sub[x] - sub[it]) - 2ll * N * sub[it] + sqr(sub[it]), it});
		}
	process(cands);
	return res;
}

ll solve() {
	int root = 0;
	for (int i = 1; i <= N; i++)
		if (adj[i].size() > 1) {
			root = i;
			break;
		}
	
	if (!root)
		return 2;
	
	dfs(root, 0);
	calc(root, 0);
	go(root, 0);
	
	return (ll)N * (N - 1) / 2 - mini / 2;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}