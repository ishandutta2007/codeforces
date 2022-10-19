#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2e5 + 5;
const int offset = 1 << 18;
const ll INF = 1e18;

struct node {
	ll mini, lazy;
};

int N, M, Q;
int x[MAXN], y[MAXN];
vector <pii> E[MAXN];
ll sol[MAXN];
node t[2 * offset];
multiset <ll> S;

void load() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i < N; i++)
		scanf("%d%d", x + i, y + i);
	while (M--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E[u].push_back({v, w});
	}
}

node merge(node l, node r) {
	return {min(l.mini, r.mini), l.lazy + r.lazy};
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

ll query() {
	prop(1);
	return t[1].mini;
}

void solve() {
	for (int i = 0; i < offset; i++)
		t[i + offset].mini = i >= 1 && i <= N ? y[i - 1] : INF;
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	for (int i = 1; i <= N; i++) {
		for (auto it : E[i])
			update(1, 0, offset, 1, it.first + 1, it.second);
		sol[i] = query() + x[i];
		S.insert(sol[i]);
	}
	
	printf("%lld\n", *S.begin());
	while (Q--) {
		int v, w;
		scanf("%d%d", &v, &w);
		S.erase(S.find(sol[v]));
		sol[v] += w - x[v];
		x[v] = w;
		S.insert(sol[v]);
		printf("%lld\n", *S.begin());
	}
}

int main() {
	load();
	solve();
	return 0;
}