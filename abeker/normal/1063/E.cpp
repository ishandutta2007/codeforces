#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
int perm[MAXN];
char ans[MAXN][MAXN];
bool bio[MAXN];
int curr;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", perm + i);
}

void finish(int maks) {
	printf("%d\n", maks);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%c", ans[i][j]);
		puts("");
	}
	exit(0);
}

inline void put(int x, int y, char c) {
	ans[x][y] = c;
}

void decompose(int x) {
	bool flag = x == 1;
	vector <int> cycle;
	for (; !bio[x]; x = perm[x]) {
		cycle.push_back(x);
		bio[x] = true;
	}
	
	if (cycle.size() == 1)
		return;
	
	if (flag)
		rotate(cycle.begin(), cycle.begin() + 1, cycle.end());
	else {
		rotate(cycle.begin(), max_element(cycle.begin(), cycle.end()), cycle.end());
		rotate(cycle.begin(), --cycle.end(), cycle.end());
	}
	
	int sz = cycle.size();
	for (int i = sz - 2; i >= 0; i--) {
		put((flag ? 0 : curr - sz) + i + 1, cycle[i], "\\/"[cycle[i] < cycle[i + 1]]);
		put((flag ? 0 : curr - sz) + i + 1, cycle[i + 1], "\\/"[cycle[i] < cycle[i + 1]]);
	}
	
	if (!flag) {
		put(curr, cycle[sz - 1], '\\');
		put(curr, 1, '\\');
		put(curr - sz + 1, 1, '/');
		curr -= sz;
	}
}

void solve() {
	memset(ans, '.', sizeof ans);
	
	bool id = true;
	for (int i = 1; i <= N; i++)
		id &= perm[i] == i;
	
	if (id)
		finish(N);
	
	curr = N;
	for (int i = 1; i <= N; i++)
		if (!bio[i])
			decompose(i);	
		
	finish(N - 1);
}

int main() {
	load();
	solve();
	return 0;
}