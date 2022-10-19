#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N, K;
char s[MAXN];
int val[MAXN];
vector <int> subs[MAXN];
vector <int> comp[MAXN];
int clr[MAXN], opt[MAXN];
int cnt[MAXN][2];
int fix[MAXN];
int dad[MAXN];

void load() {
	scanf("%d%d%s", &N, &K, s);
	for (int i = 0; i < K; i++) {
		int c;
		scanf("%d", &c);
		while (c--) {
			int x;
			scanf("%d", &x);
			subs[--x].push_back(i);
		}
	}
}

void update_one(int x, int toggle, int &ref) {
	int root = dad[x];
	val[x] = toggle;
	fix[root] = x;
	ref -= opt[root];
	opt[root] = cnt[root][clr[x] ^ toggle ^ 1];
	ref += opt[root];
}

void update_two(int x, int y, int toggle, int &ref) {
	int rootx = dad[x];
	int rooty = dad[y];
	if (rootx == rooty)
		return;
	if (comp[rootx].size() > comp[rooty].size()) {
		swap(rootx, rooty);
		swap(x, y);
	}
	ref -= opt[rootx] + opt[rooty];
	int diff = clr[x] ^ clr[y] ^ toggle;
	for (auto it : comp[rootx]) {
		comp[rooty].push_back(it);
		dad[it] = rooty;
		clr[it] ^= diff;
		cnt[rooty][clr[it]]++;
	}
	if (fix[rootx] != -1)
		fix[rooty] = fix[rootx];
	if (fix[rooty] != -1)
		opt[rooty] = cnt[rooty][clr[fix[rooty]] ^ val[fix[rooty]] ^ 1];
	else
		opt[rooty] = min(cnt[rooty][0], cnt[rooty][1]);
	ref += opt[rooty];
}

void solve() {
	for (int i = 0; i < K; i++) {
		dad[i] = i;
		cnt[i][0] = 1;
		fix[i] = -1;
		comp[i].push_back(i);
	}
	
	int sol = 0;
	for (int i = 0; i < N; i++) {
		assert(subs[i].size() <= 2);
		if (subs[i].size() == 1)
			update_one(subs[i][0], '1' - s[i], sol);
		else if (subs[i].size() == 2)
			update_two(subs[i][0], subs[i][1], '1' - s[i], sol);
		printf("%d\n", sol);
	}
}

int main() {
	load();
	solve();
	return 0;
}