#include <cstdio>
using namespace std;

const int MAXN = 100005;
const int offset = 1 << 17;

struct node {
	int sum;
	node *l, *r;
	node(int sum, node *l, node *r) : sum(sum), l(l), r(r) {}
	node() : sum(0), l(0), r(0) {}
};

int N;
int a[MAXN];
int last[MAXN];
node *NIL;
node *root[2 * MAXN];
int when[MAXN];
int timer;

void init() {
	NIL = new node();
	NIL -> l = NIL -> r = NIL;
	root[0] = NIL;
}

node *update(node *x, int lo, int hi, int pos, int val) {
	if (pos < lo || pos >= hi)
		return x;
	if (hi - lo == 1)
		return new node(val, NIL, NIL);
	int mid = (lo + hi) / 2;
	node *L = update(x -> l, lo, mid, pos, val);
	node *R = update(x -> r, mid, hi, pos, val); 
	return new node(L -> sum + R -> sum, L, R);
}

void update(int pos, int val) {
	root[timer + 1] = update(root[timer], 0, offset, pos, val);
	timer++;
}

int kth(node *x, int lo, int hi, int k) {
	if (hi - lo == 1)
		return lo;
	int mid = (lo + hi) / 2;
	int left = x -> l -> sum;
	if (left >= k)
		return kth(x -> l, lo, mid, k);
	return kth(x -> r, mid, hi, k - left);
}

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

int greedy(int k) {
	int sol = 0, curr = N;
	while (curr) {
		sol++;
		int tot = root[when[curr]] -> sum;
		if (tot < k)
			break;
		curr = kth(root[when[curr]], 0, offset, tot - k); 
	}
	return sol;
}

void solve() {
	init();
	for (int i = 1; i <= N; i++) {
		if (last[a[i]])
			update(last[a[i]], 0);
		update(i, 1);
		when[i] = timer;
		last[a[i]] = i;
	}
	
	for (int k = 1; k <= N; k++)
		printf("%d ", greedy(k));
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}