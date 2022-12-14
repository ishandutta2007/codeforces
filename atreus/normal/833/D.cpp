#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 4e5 + 10;
const int mod = 1e9 + 7;

vector<pair<int, int> > t[maxn];
int n, dp[maxn], parsum[maxn], parmul[maxn], dpup[maxn], sz[maxn], answer = 1, fenmul[maxn], fensum[maxn];
bool mark[maxn];

struct edge{
	int v;
	int u;
	int w;
	int col;
	edge(int v_ = 0, int u_ = 0, int w_ = 0, int col_ = 0){
		v = v_, u = u_, w = w_, col = col_;
	}
} e[maxn];

int power(int a, int b){
	if (b == 0)
		return 1;
	int ret = power(a, b / 2);
	ret = 1ll * ret * ret % mod;
	if (b & 1)
		return 1ll * ret * a % mod;
	return ret;
}

pair<int, int> get(int idx){
	idx += 2 * n;
	if (idx < 0)
		return {0, 1};
	int sum = 0, mul = 1;
	for (; idx; idx -= idx & -idx){
		sum += fensum[idx];
		mul = 1ll * fenmul[idx] * mul % mod;
	}
	return {sum, mul};
}

void add(int idx, int mul, int sum){
	idx += 2 * n;
	for (; idx < maxn; idx += idx & -idx){
		fenmul[idx] = 1ll * fenmul[idx] * mul % mod;
		fensum[idx] += sum;
	}
}

int dfssz(int v, int par = -1){
	if (mark[v])
		return 0;
	sz[v] = 1;
	for (auto u : t[v])
		if (u.first != par)
			sz[v] += dfssz(u.first, v);
	return sz[v];
}

void dfspar(int v, int par = -1, bool type = 0){
	if (par != -1 and type == 0){
		pair<int, int> tmp = get(parsum[v] - 1);
		ll frac = 1ll * power(parmul[v], tmp.first) * tmp.second % mod;
		answer = 1ll * answer * power(frac, mod - 2) % mod;
	}
	if (par == -1 or type == 1)
		add(-parsum[v], parmul[v], +1);
	for (auto it : t[v]){
		int u = it.first;
		if (!mark[u] and u != par){
			parsum[u] = parsum[v] + e[it.second].col;
			parmul[u] = 1ll * parmul[v] * e[it.second].w % mod;
			dfspar(u, v, type);
			if (par == -1)
				dfspar(u, v, type ^ 1);
		}
	}
}

void vitex(int v, int par = -1){
	add(-parsum[v], power(parmul[v], mod - 2), -1);
	for (auto u : t[v])
		if (!mark[u.first] and u.first != par)
			vitex(u.first, v);
}

void centroidDecomposition(int v){
	int Max = dfssz(v);
	int par = -1;
	bool found = 0;
	while (found == 0){
		found = 1;
		for (auto it : t[v]){
			int u = it.first;
			if (!mark[u] and u != par and 2 * sz[u] >= Max){
				par = v;
				v = u;
				found = 0;
				break;
			}
		}
	}
	parsum[v] = 0;
	parmul[v] = 1;
	dfspar(v);
	vitex(v);
	mark[v] = 1;
	for (auto u : t[v])
		if (!mark[u.first])
			centroidDecomposition(u.first);
}

int dfs(int v, int par = -1, int idx = -1){
	dp[v] = 1;
	for (auto u : t[v])
		if (u.first != par)
			dp[v] += dfs(u.first, v, u.second);
	if (idx != -1)
		answer = 1ll * answer * power(e[idx].w, 1ll * dp[v] * (n - dp[v]) % (mod - 1)) % mod;
	return dp[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int v, u, x, col;
		scanf("%d%d%d%d", &v, &u, &x, &col);
		e[i] = edge(v, u, x, col);
		t[v].push_back({u, i});
		t[u].push_back({v, i});
	}
	dfs(1);
	for (int i = 0; i < n - 1; i++)
		if (e[i].col == 0)
			e[i].col = -2;
	
	for (int i = 0; i < maxn; i++)
		fenmul[i] = 1;
	centroidDecomposition(1);
	memset(mark, 0, sizeof mark);
	for (int i = 0; i < n - 1; i++){
		if (e[i].col == -2)
			e[i].col = 1;
		else
			e[i].col = -2;
	}
	centroidDecomposition(1);
	printf("%d\n", answer);
}