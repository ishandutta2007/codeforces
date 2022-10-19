#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N, M;
vector <int> E[MAXN];
int a[MAXN], b[MAXN];
ll c[MAXN];
int color[MAXN];
vector <int> out;
ll sol[MAXN];
vector <int> ch[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%lld", c + i);
	for (int i = 0; i < M; i++)
		scanf("%d%d", a + i, b + i);		
}

void dfs(int x, int p) {
	color[x] = color[p] ^ 1;
	for (auto it : E[x]) {
		int nxt = a[it] + b[it] - x;
		if (nxt == p)
			continue;
		if (color[nxt] != -1) {
			out.push_back(it);
			continue;
		}
		ch[x].push_back(it);
		dfs(nxt, x);
	}
}

ll calc(int x) {
	ll res = 0;
	for (auto it : ch[x]) {
		int nxt = a[it] + b[it] - x;
		sol[it] = c[nxt] - calc(nxt);
		res += sol[it];
	}
	return res;
}

void solve() {
	for (int i = 0; i < M; i++) {
		E[a[i]].push_back(i);
		E[b[i]].push_back(i);
	}

	memset(color, -1, sizeof color);	
	color[0] = 1;
	
	dfs(1, 0);
	
	ll diff = 0;
	for (int i = 1; i <= N; i++)
		diff += color[i] ? c[i] : -c[i];
		
	bool ok = false;
	for (auto it : out) 
		if (color[a[it]] == color[b[it]]) {
			sol[it] = color[a[it]] ? diff / 2 : -diff / 2;
			c[a[it]] -= sol[it];
			c[b[it]] -= sol[it];
			ok = true;
			break;
		}
	
	if (!ok && diff) {
		puts("NO");
		return;
	}
	
	calc(1);
	
	puts("YES");
	for (int i = 0; i < M; i++)
		printf("%lld\n", sol[i]);
}

int main() {
	load();
	solve();
	return 0;
}