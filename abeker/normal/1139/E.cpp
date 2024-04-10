#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 5;

int N, M, D;
unordered_set <int> adj[MAXN];
int pot[MAXN], club[MAXN];
int leave[MAXN], ans[MAXN];
bool bio[MAXN], alive[MAXN];
int conn[MAXN];
int cnt;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) 
		scanf("%d", pot + i);
	for (int i = 1; i <= N; i++)
		scanf("%d", club + i);
	scanf("%d", &D);
	for (int i = 0; i < D; i++)
		scanf("%d", leave + i);
}

bool dfs(int x) {
	if (bio[x])
		return false;
	bio[x] = true;
	for (auto it : adj[x])
		if (conn[it] == -1 || dfs(conn[it])) {
			conn[it] = x;
			return true;
		}
	return false;
}

void matching(int pref) {
	memset(bio, false, sizeof bio);
	cnt += dfs(pref);	
}

void in(int x) {
	adj[pot[x]].insert(club[x]);
}

void solve() {
	memset(conn, -1, sizeof conn);
	memset(alive, true, sizeof alive);
	for (int i = 0; i < D; i++)
		alive[leave[i]] = false;
	
	for (int i = 1; i <= N; i++)
		if (alive[i])
			in(i);
			
	int ptr = 0;
	for (int i = D - 1; i >= 0; i--) {
		for (; ; ptr++) {
			matching(ptr);
			if (cnt <= ptr)
				break;
		}
		alive[leave[i]] = true;
		in(leave[i]);
		ans[i] = ptr;
	}
	
	for (int i = 0; i < D; i++)
		printf("%d\n", ans[i]);
}

int main() {
	load();
	solve();
	return 0;
}