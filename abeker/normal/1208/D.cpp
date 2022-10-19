#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;
const ll INF = 1e18;

struct node {
	ll mini, lazy;
	int pos;
};

int N;
ll sum[MAXN];
int perm[MAXN];
node t[2 * offset];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", sum + i);
}

node merge(node lft, node rig) {
	return {min(lft.mini, rig.mini), lft.lazy + rig.lazy, lft.mini < rig.mini ? lft.pos : rig.pos};
}

void prop(int x) {
	t[x].mini += t[x].lazy;
	if (x < offset) {
		t[2 * x].lazy += t[x].lazy;
		t[2 * x + 1].lazy += t[x].lazy;
	}
	t[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, ll val) {
	prop(x);
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		t[x].mini += val;
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

void update(int from, int to, ll val) {
	update(1, 0, offset, from, to, val);
}

int query() {
	prop(1);
	return t[1].pos;
}

void solve() {
	for (int i = 0; i < offset; i++)
		t[i + offset] = {i >= 1 && i <= N ? sum[i] : INF, 0, i};
	
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	for (int i = 1; i <= N; i++) {
		int where = query();
		perm[where] = i;
		update(where, where + 1, INF);
		update(where + 1, N + 1, -i);
	}
	
	for (int i = 1; i <= N; i++)
		printf("%d ", perm[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}