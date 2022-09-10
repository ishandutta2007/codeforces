#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1'000'007;
const int MOD = 1'000'000'007;
const LL INF = 1LL * MOD * MOD;

int n;
int fib[N];
bool used[N];
vector <PII> G[N];

void no() {
	puts("NO");
	exit(0);
}

int sz[N];
int par[N];
vector <int> S;

int dfs(int u, int p = -1) {
	sz[u] = 1;
	S.push_back(u);

	for(auto [v, id]: G[u])
		if(!used[id] and p != v) {
			par[v] = id;
			sz[u] += dfs(v, u);
		}

	return sz[u];
}

void check(int u, int k) {
	if(k <= 3)
		return;
	
	S.clear();
	dfs(u);
	
	int any = -1;
	for(auto v: S) {
		if(sz[v] == fib[k - 2])
			any = v;

		if(sz[v] == fib[k - 1])
			any = v;
	}
	
	if(any == -1)
		no();
	
	used[par[any]] = true;
	if(sz[any] == fib[k - 1]) {
		check(any, k - 1);
		check(u, k - 2);
	} else if(sz[any] == fib[k - 2]) {
		check(any, k - 2);
		check(u, k - 1);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	
	if(n == 1) {
		puts("YES");
		return 0;
	}
	
	fib[0] = fib[1] = 1;
	for(int i = 2; true; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if(fib[i] > n)
			no();
		
		if(fib[i] == n) {
			check(1, i);
			break;
		}
	}
	
	puts("YES");
	return 0;
}