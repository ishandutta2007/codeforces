#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 100005;
const int offset = 1 << 17;
const int INF = 0x3f3f3f3f;

struct node {
	int maks, pos, lazy;
};

struct worker {
	int l, r, v, id;
	worker(int l, int r, int v, int id) : 
		l(l), r(r), v(v), id(id) {}
	worker() {}
	bool operator <(const worker &rhs) const {
		if (v != rhs.v)
			return v < rhs.v;
		return id < rhs.id;
	}
};

int N;
worker w[MAXN];
node t[2 * offset];

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (w[lhs].l != w[rhs].l)
			return w[lhs].l > w[rhs].l;
		return lhs < rhs;
	}
};

set <int, cmp> S;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &w[i].l, &w[i].v, &w[i].r);
		w[i].id = i;
	}
}

node merge(node l, node r) {
	return {max(l.maks, r.maks), l.maks < r.maks ? r.pos : l.pos, l.lazy + r.lazy};
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
	update(1, 0, offset, from, to, val);
}

node query() {
	prop(1);
	return t[1];
}

void out(int x) {
	S.erase(x);
	update(x, lower_bound(w, w + N, worker(0, 0, w[x].r + 1, -1)) - w, -1); 
	update(x, x + 1, -INF);
}

void in(int x) {
	S.insert(x);
	update(x, lower_bound(w, w + N, worker(0, 0, w[x].r + 1, -1)) - w, 1);
	update(x, x + 1, INF);
}

void solve() {
	sort(w, w + N);
	
	for (int i = 0; i < offset; i++)
		t[i + offset] = {-INF, i, 0};
	
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	int sol = 0;
	int left = 0, right = 0;
	for (int i = N - 1; i >= 0; i--) {
		while (!S.empty() && w[*S.begin()].l > w[i].v)
			out(*S.begin());
		in(i);
		node ans = query();
		if (ans.maks > sol) {
			left = i;
			right = ans.pos;
			sol = ans.maks;
		}
	}

	printf("%d\n", sol);
	for (int i = left; i <= right; i++)
		if (w[i].l <= w[left].v && w[i].r >= w[right].v)
			printf("%d ", ++w[i].id);
	puts(""); 
}

int main() {
	load();
	solve();
	return 0;
}