#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e6 + 5;
const int offset = 1 << 22;

struct node {
	int mx, lazy;
};

int N, M, Q;
int a[MAXN], b[MAXN];
node t[2 * offset];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= M; i++)
		scanf("%d", b + i);
}

node merge(node lft, node rig) {
	return {max(lft.mx, rig.mx), lft.lazy + rig.lazy};
}

void prop(int x) {
	t[x].mx += t[x].lazy;
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
		t[x].mx += val;
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

void update(int pos, int val) {
	update(1, 0, offset, MAXN - pos, MAXN, val);
}

int query(int x, int lo, int hi) {
	prop(x);
	if (hi - lo == 1)
		return lo;
	prop(2 * x);
	prop(2 * x + 1);
	int mid = (lo + hi) / 2;
	if (t[2 * x].mx > 0)
		return query(2 * x, lo, mid);
	return query(2 * x + 1, mid, hi);
}

void solve() {
	for (int i = 1; i <= N; i++)
		update(a[i], 1);
	for (int i = 1; i <= M; i++)
		update(b[i], -1);
		
	scanf("%d", &Q);
	while (Q--)	{
		int type, who, val;
		scanf("%d%d%d", &type, &who, &val);
		if (type == 1) {
			update(a[who], -1);
			a[who] = val;
			update(a[who], 1);
		}
		else {
			update(b[who], 1);
			b[who] = val;
			update(b[who], -1);
		}
		int ans = query(1, 0, offset);
		printf("%d\n", ans < MAXN ? MAXN - ans : -1);
	}
}

int main() {
	load();
	solve();
	return 0;
}