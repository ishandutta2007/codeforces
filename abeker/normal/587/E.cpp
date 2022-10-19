#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define leading __builtin_clz

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;

struct Node {
	int lazy;
	int lft, rig;
	vector <pii> basis;
	Node(int lazy, int lft, int rig, vector <pii> basis) : lazy(lazy), lft(lft), rig(rig), basis(basis) {}
	Node() : lazy(-1), lft(-1), rig(-1), basis({}) {}
	void add(int x) {
		bool ok = false;
		vector <pii> nxt;
		for (auto it : basis) {
			if (!ok && x) {
				int tmp = leading(x);
				if (tmp < it.second) {
					nxt.push_back({x, tmp});
					ok = true;
				}
				else if (tmp == it.second)
					x ^= it.first;
			}
			nxt.push_back(it);
		}
		if (!ok && x)
			nxt.push_back({x, leading(x)});
		basis = nxt;
	}
	int rnk() {
		add(lft);
		return basis.size();
	}
};

int N, Q;
int a[MAXN];
Node tour[2 * offset];

void load() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

Node merge(Node L, Node R) {
	if (L.lazy == -1)
		return R;
	if (R.lazy == -1)
		return L;
	L.add(L.rig ^ R.lft);
	for (auto it : R.basis)
		L.add(it.first);
	L.rig = R.rig;
	return L;
}

void prop(int x) {
	tour[x].lft ^= tour[x].lazy;
	tour[x].rig ^= tour[x].lazy;
	if (x < offset) {
		tour[2 * x].lazy ^= tour[x].lazy;
		tour[2 * x + 1].lazy ^= tour[x].lazy;
	}
	tour[x].lazy = 0;
}

void update(int x, int lo, int hi, int from, int to, int val) {
	prop(x);
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		tour[x].lft ^= val;
		tour[x].rig ^= val;
		if (x < offset) {
			tour[2 * x].lazy ^= val;
			tour[2 * x + 1].lazy ^= val;
		}
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, val);
	update(2 * x + 1, mid, hi, from, to, val);
	tour[x] = merge(tour[2 * x], tour[2 * x + 1]);
}

Node query(int x, int lo, int hi, int from, int to) {
	prop(x);
	if (lo >= to || hi <= from)
		return Node();
	if (lo >= from && hi <= to)
		return tour[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

void solve() {
	for (int i = 1; i <= N; i++) 
		tour[i + offset] = Node(0, a[i], a[i], {});
	for (int i = offset - 1; i >= 0; i--)
		tour[i] = merge(tour[2 * i], tour[2 * i + 1]);
		
	while (Q--) {
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) {
			int k;
			scanf("%d", &k);
			update(1, 0, offset, l, r + 1, k);
		}
		else 
			printf("%d\n", 1 << query(1, 0, offset, l, r + 1).rnk());
	}
}

int main() {
	load();
	solve();
	return 0;
}