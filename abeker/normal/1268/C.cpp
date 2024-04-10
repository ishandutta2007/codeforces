#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;

struct node {
	int lft, rig;
	ll sum_lft, sum_rig;
	int lazy_lft, lazy_rig;
	void output() const {
		printf("%d %d %lld %lld %d %d\n", lft, rig, sum_lft, sum_rig, lazy_lft, lazy_rig);
	}
};

int N;
int pos[MAXN];
node t[2 * offset];
bool bio[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		pos[x] = i;
	}
}

node merge(node lhs, node rhs) {
	if (lhs.lft == -1)
		return rhs;
	if (rhs.lft == -1)
		return lhs;
	return {rhs.lft, lhs.rig, lhs.sum_lft + rhs.sum_lft, lhs.sum_rig + rhs.sum_rig, lhs.lazy_lft + rhs.lazy_lft, lhs.lazy_rig + rhs.lazy_rig};
}

void prop(int x, int len) {
	t[x].lft += t[x].lazy_lft;
	t[x].rig += t[x].lazy_rig;
	t[x].sum_lft += (ll)len * t[x].lazy_lft;
	t[x].sum_rig += (ll)len * t[x].lazy_rig;
	if (x < offset) {
		t[2 * x].lazy_lft += t[x].lazy_lft;
		t[2 * x].lazy_rig += t[x].lazy_rig;
		t[2 * x + 1].lazy_lft += t[x].lazy_lft;
		t[2 * x + 1].lazy_rig += t[x].lazy_rig;
	}
	t[x].lazy_lft = t[x].lazy_rig = 0;
}

void update(int x, int lo, int hi, int from, int to, int l, int r) {
	prop(x, hi - lo);
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		t[x].lft += l;
		t[x].rig += r;
		t[x].sum_lft += (hi - lo) * l;
		t[x].sum_rig += (hi - lo) * r;
		if (x < offset) {
			t[2 * x].lazy_lft += l;
			t[2 * x].lazy_rig += r;
			t[2 * x + 1].lazy_lft += l;
			t[2 * x + 1].lazy_rig += r;
		}
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, l, r);
	update(2 * x + 1, mid, hi, from, to, l, r);
	t[x] = merge(t[2 * x], t[2 * x + 1]); 
}

void update(int from, int to, int l, int r) {
	update(1, 0, offset, from, to, l, r);
}

node query(int x, int lo, int hi, int from, int to) {
	prop(x, hi - lo);
	if (lo >= to || hi <= from)
		return {-1, -1, 0, 0, 0, 0};
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

node query(int from, int to) {
	return query(1, 0, offset, from, to);
}

int search(int x, int lo, int hi) {
	if (x >= offset)
		return x - offset;
	int mid = (lo + hi) / 2;
	prop(2 * x, mid - lo);
	prop(2 * x + 1, hi - mid);
	if (t[2 * x].lft >= t[2 * x + 1].rig + bio[mid])
		return search(2 * x, lo, mid);
	return search(2 * x + 1, mid, hi);
}

ll gauss(int x) {
	return (ll)x * (x + 1) / 2;
}

ll calc(int k) {
	return k % 2 ? 2 * gauss(k / 2) - k / 2 : 2 * gauss(k / 2 - 1);
}

void solve() {
	ll inv = 0;
	for (int i = 1; i <= N; i++) {
		inv += query(pos[i], pos[i] + 1).rig;
		bio[pos[i]] = true;
		update(0, pos[i], 0, 1);
		update(pos[i] + 1, offset, 1, 0);
		int peak = search(1, 0, offset);
		printf("%lld ", query(1, peak).sum_lft + query(peak, N + 1).sum_rig - calc(i) + inv);
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}