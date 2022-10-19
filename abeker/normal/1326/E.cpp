#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const int offset = 1 << 19;

struct node {
	int maks, lazy;
};

int N;
int inv[MAXN];
int q[MAXN];
bool bio[MAXN];
node t[2 * offset];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		inv[x] = i;
	}
	for (int i = 1; i <= N; i++)
		scanf("%d", q + i);
}

node merge(node lft, node rig) {
	return {max(lft.maks, rig.maks), lft.lazy + rig.lazy};
}

void prop(int x) {
	t[x].maks += t[x].lazy;
	if (x < offset) {
		t[2 * x].lazy += t[x].lazy;
		t[2 * x + 1].lazy += t[x].lazy;
	}
	t[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, int val) {
	prop(x);
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		t[x].maks += val;
		if (x < offset) {
			t[2 * x].lazy += val;
			t[2 * x + 1].lazy += val;
		}
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, val);
	update(2 * x + 1, mid, hi, from, to, val);
	t[x] = merge(t[2 * x], t[2 * x + 1]);
}

void update(int from, int to, int val) {
	if (val == -1 || !bio[to])
		update(1, 0, offset, from, to, val);
	if (val == 1)
		bio[to] = true;
}

int query() {
	prop(1);
	return t[1].maks;
}

void solve() {
	int ptr = N;
	for (int i = 1; i <= N; i++) {
		while (1) {
			update(1, inv[ptr] + 1, 1);
			if (query() > 0)
				break;
			ptr--;
		}
		printf("%d ", ptr);
		update(1, q[i] + 1, -1);
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}