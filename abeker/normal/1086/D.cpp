#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const char shape[] = "RSP";

struct fenwick {
	int f[MAXN];
	fenwick() {
		memset(f, 0, sizeof f);
	}
	void update(int x, int val) {
		for (; x < MAXN; x += x & -x)
			f[x] += val;
	}
	int get(int x) {
		int res = 0;
		for (; x > 0; x -= x & -x)
			res += f[x];
		return res;
	}
	int get(int lo, int hi) {
		return lo > hi ? 0 : get(hi) - get(lo - 1);
	}
};

int N, Q;
char s[MAXN];
set <int> pos[3];
fenwick cnt[3];

void load() {
	scanf("%d%d%s", &N, &Q, s + 1);
}

inline int which(char c) {
	return strchr(shape, c) - shape;
}

void in(int x, int y) {
	pos[y].insert(x);
	cnt[y].update(x, 1);
}

void out(int x, int y) {
	pos[y].erase(x);
	cnt[y].update(x, -1);
}

int mini(int x) {
	return pos[x].empty() ? N + 1 : *pos[x].begin();
}

int maks(int x) {
	return pos[x].empty() ? 0 : *pos[x].rbegin();
}

int query() {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		int hi1 = mini((i + 1) % 3);
		int lo1 = min(hi1, mini((i + 2) % 3));
		int lo2 = maks((i + 1) % 3);
		int hi2 = max(lo2, maks((i + 2) % 3));		
		if (lo2 || !hi2)
			res += (int)pos[i].size() - cnt[i].get(lo1, hi1) - cnt[i].get(lo2, hi2);
	}
	
	return res;
}

void solve() {
	for (int i = 1; i <= N; i++)
		in(i, which(s[i]));

	printf("%d\n", query());		
	while (Q--) {
		int p;
		char c;
		scanf("%d %c", &p, &c);
		out(p, which(s[p]));
		s[p] = c;
		in(p, which(s[p]));
		printf("%d\n", query());
	}
}

int main() {
	load();
	solve();
	return 0;
}