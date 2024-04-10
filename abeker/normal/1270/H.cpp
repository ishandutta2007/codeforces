#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;
const int offset = 1 << 19;
const int INF = 1e9;

struct node {
	int mini, occ, lazy;
};

int N, Q;
int a[MAXN];
set <pii> sorted;
node t[2 * offset];

node merge(node lft, node rig) {
	return {min(lft.mini, rig.mini), (lft.mini <= rig.mini ? lft.occ : 0) + (rig.mini <= lft.mini ? rig.occ : 0), lft.lazy + rig.lazy};
}

void prop(int x) {
	t[x].mini += t[x].lazy;
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

void update(int from, int to, int val) {
	if (from > to)
		swap(from, to);
	if (from < 0 || to >= N)
		return;
	update(1, 0, offset, from, to, val);
}

node query(int x, int lo, int hi, int from, int to) {
	prop(x);
	if (lo >= to || hi <= from)
		return {INF, 1, 0};
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void in(int x) {
	sorted.insert({a[x], x});
	auto it = sorted.find({a[x], x});
	auto prv = it; prv--;
	auto nxt = it; nxt++;
	update(prv -> second, nxt -> second, -1);
	update(prv -> second, x, 1);
	update(x, nxt -> second, 1);
}

void out(int x) {
	auto it = sorted.find({a[x], x});
	auto prv = it; prv--;
	auto nxt = it; nxt++;
	update(prv -> second, x, -1);
	update(x, nxt -> second, -1);
	update(prv -> second, nxt -> second, 1);
	sorted.erase(it);
}

void init() {
	sorted.insert({-INF, -INF});
	sorted.insert({INF, INF});
	for (int i = 0; i < offset; i++)
		t[i + offset] = {0, 1, 0};
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
}

int solve() {
	node tmp = query(1, 0, offset, 0, N - 1);
	if (tmp.mini > 1)
		return 1;
	return a[0] < a[N - 1] ? tmp.occ + 1 : 1;
}

int main() {
	init();
	
	scanf("%d%d", &N, &Q);
	for (int i = N - 1; i >= 0; i--) {
		scanf("%d", a + i);
		in(i);
	}
	
	while (Q--) {
		int pos, val;
		scanf("%d%d", &pos, &val);
		pos = N - pos;
		out(pos);
		a[pos] = val;
		in(pos);
		printf("%d\n", solve());
	}
	
	return 0;
}