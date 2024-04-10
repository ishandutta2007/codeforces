#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int MAXV = 1e7 + 5;
const int LOGN = 18;
const int LOGV = 24;
const int MOD = 1e9 + 7;

struct str {
	int id, pos, sgn;
};

int N, Q;
vector <int> E[MAXN];
vector <pii> fact[MAXN];
vector <str> todo[MAXN];
vector <pii> nums[MAXN];
vector <int> ans[MAXN];
int st[MAXN], en[MAXN], val[MAXN];
int prime[MAXV], idx[MAXV];
int anc[MAXN][LOGN];
int freq[8 * MAXN][LOGV];
int dep[MAXN];
int a[MAXN];

void sieve() {
	for (int i = 2; i < MAXV; i++)
		if (!prime[i])
			for (int j = i; j < MAXV; j += i)
				if (!prime[j])
					prime[j] = i;
}

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
		scanf("%d%d%d", st + i, en + i, val + i);
}

vector <pii> factorize(int x) {
	vector <pii> res;
	while (x > 1) {
		int tmp = prime[x], ex = 0;
		for (; !(x % tmp); x /= tmp)
			ex++;
		res.push_back({tmp, ex});
		idx[tmp] = 1;
	}
	return res;
}

int lca(int x, int y) {
	if (dep[x] < dep[y])
		swap(x, y);
	int diff = dep[x] - dep[y];
	for (int i = 0; i < LOGN; i++)
		if (diff >> i & 1)
			x = anc[x][i];
	if (x == y)
		return x;
	for (int i = LOGN - 1; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	return anc[x][0];
}

void dfs(int x, int p) {
	anc[x][0] = p;
	dep[x] = dep[p] + 1;
	for (auto it : E[x])
		if (it != p)
			dfs(it, x);
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

void sweep(int x, int p) {
	for (auto it : fact[x])
		freq[idx[it.first]][it.second]++;
	
	for (auto it : todo[x]) 
		for (int i = 0; i < LOGV; i++) {
			pii tmp = nums[it.id][it.pos];
			ans[it.id][it.pos] += it.sgn * freq[idx[tmp.first]][i] * min(tmp.second, i);
		}
	
	for (auto it : E[x])
		if (it != p)
			sweep(it, x);
	
	for (auto it : fact[x])
		freq[idx[it.first]][it.second]--;
}

void solve() {
	for (int i = 1; i <= N; i++)
		fact[i] = factorize(a[i]);
	
	for (int i = 0; i < Q; i++)
		nums[i] = factorize(val[i]);
	
	for (int i = 1; i < MAXV; i++)
		idx[i] += idx[i - 1];
	
	dfs(1, 0);
	
	for (int j = 1; j < LOGN; j++)
		for (int i = 1; i <= N; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		
	for (int i = 0; i < Q; i++) {
		int l = lca(st[i], en[i]);
		ans[i].resize(nums[i].size());
		for (int j = 0; j < nums[i].size(); j++) {
			todo[st[i]].push_back({i, j, 1});
			todo[en[i]].push_back({i, j, 1});
			todo[l].push_back({i, j, -1});
			todo[anc[l][0]].push_back({i, j, -1});
		}
	}
	
	sweep(1, 0);
	
	for (int i = 0; i < Q; i++) {
		int sol = 1;
		for (int j = 0; j < nums[i].size(); j++)
			sol = mul(sol, pot(nums[i][j].first, ans[i][j]));
		printf("%d\n", sol);
	}
}

int main() {
	sieve();
	load();
	solve();
	return 0;
}