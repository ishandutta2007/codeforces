#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAXM = 42;

int N, M;
int op[MAXN];
char name[MAXN][MAXM];
vector <string> all;
unordered_set <int> curr;
ll adj[MAXM];
int val[1 << MAXM / 2], dp[1 << MAXM / 2];
int half, rest;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", op + i);
		if (op[i] == 2)
			scanf("%s", name[i]);
	}
}

void add(int a, int b) {
	adj[a] |= 1ll << b;
}

int dfs(int x) {
	if (dp[x] != -1)
		return dp[x];
	dp[x] = val[x];
	for (int i = 0; i < rest; i++)
		if (x >> i & 1)
			dp[x] = max(dp[x], dfs(x ^ 1 << i));
	return dp[x];
}

ll get(ll mask) {
	ll res = 0;
	for (int i = 0; i < M; i++)
		if (mask >> i & 1ll)
			res |= adj[i];
	return res;
}

bool indep(ll mask) {
	return !(mask & get(mask));
}

int solve() {
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < N; i++)
		if (op[i] == 2)
			all.push_back(name[i]);
	
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
		
	assert(all.size() == M);
	
	op[N++] = 1;
	for (int i = 0; i < N; i++)
		if (op[i] == 1) {
			for (auto it1 : curr)
				for (auto it2 : curr)
					if (it1 != it2)
						add(it1, it2);
			curr.clear();
		}
		else 
			curr.insert(lower_bound(all.begin(), all.end(), name[i]) - all.begin());
	
	half = (M + 1) / 2;
	rest = M / 2;
	for (int i = 0; i < 1 << rest; i++)
		if (indep(i * (1ll << half)))
			val[i] = __builtin_popcount(i);
			
	int sol = 0;
	for (int i = 0; i < 1 << half; i++)
		if (indep(i))
			sol = max(sol, __builtin_popcount(i) + dfs((get(i) ^ ((1ll << M) - 1)) >> half));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}