#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;
const int offset = 1 << 19;

struct node {
	int last;
	node *l, *r;
	node() : last(0), l(0), r(0) {}
	node(int last, node *l, node *r) : last(last), l(l), r(r) {}
};

struct persistent {
	node *NIL;
	node *root[MAXN];
	
	void init(int n) {
		NIL = new node();
		NIL -> l = NIL -> r = NIL;
		root[n] = root[n + 1] = NIL;
	}
	
	node *insert(node *x, int lo, int hi, int pos, int val) {
		if (pos < lo || pos >= hi)
			return x;
		if (hi - lo == 1)
			return new node(val, NIL, NIL);
		int mid = (lo + hi) / 2;
		node *L = insert(x -> l, lo, mid, pos, val);
		node *R = insert(x -> r, mid, hi, pos, val);
		return new node(0, L, R);
	}
	
	int query(node *x, int lo, int hi, int pos) {
		if (hi - lo == 1)
			return x -> last;
		int mid = (lo + hi) / 2;
		if (pos < mid)
			return query(x -> l, lo, mid, pos);
		return query(x -> r, mid, hi, pos);
	}
	
	void update(int idx, int dad, int val) {
		root[idx] = insert(root[dad], 0, offset, val, idx);
	}
	
	int query(int idx, int pos) {
		return query(root[idx], 0, offset, pos);
	}
};

int N;
int a[MAXN];
persistent Tree;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

ll solve() {
	ll sol = 0;
	vector <int> dp(N + 5, 0);
	Tree.init(N);
	for (int i = N - 1; i >= 0; i--) {
		int parent = Tree.query(i + 1, a[i]) + 1;
		if (parent == 1)
			parent = N + 1;
		else
			dp[i] = dp[parent] + 1;
		Tree.update(i, parent, a[i]);
		sol += dp[i];
	}
	return sol;
}

int main() {
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		load();
		printf("%lld\n", solve());
	}
	return 0;
}