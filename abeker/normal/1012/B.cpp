#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M, Q;
vector <int> E[2 * MAXN];
bool bio[2 * MAXN];
set <int> all;

void load() {
	scanf("%d%d%d", &N, &M, &Q);
	while (Q--) {
		int r, c;
		scanf("%d%d", &r, &c);		
		E[r].push_back(c + MAXN);
		E[c + MAXN].push_back(r);
		all.insert(r);
		all.insert(c + MAXN);
	}
}

void dfs(int x) {
	bio[x] = true;
	for (auto it : E[x])
		if (!bio[it])
			dfs(it);
}

int solve() {
	int sol = N + M - (int)all.size() - 1;
	for (auto it : all)
		if (!bio[it]) {
			dfs(it);
			sol++;
		}
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}