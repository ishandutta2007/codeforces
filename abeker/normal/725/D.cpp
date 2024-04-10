#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const int MAXN = 300005;
const int offset = 1 << 19;
const ll INF = (ll)2e18;

struct node {
	int mini, sum;
	node(int mini, int sum) : mini(mini), sum(sum) {}
	node() : mini(0), sum(0) {}
};

int N;
pii p[MAXN];
ll a[2 * offset];
node t[2 * offset];

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld%lld", &p[i].first, &p[i].second);
}

node merge(node l, node r) {
	node res;
	res.mini = a[l.mini] < a[r.mini] ? l.mini : r.mini;
	res.sum = l.sum + r.sum;
	return res;
}

void update(int x) {
	a[x] = INF;
	x += offset;
	t[x].sum = 0;
	for (x /= 2; x; x /= 2)
		t[x] = merge(t[2 * x], t[2 * x + 1]);
}

node query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from) return node();
	if (lo >= from && hi <= to) return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

node get(ll val) {
	int pos = upper_bound(p + 1, p + N, pii(val, INF)) - p;
	return query(1, 0, offset, pos, N);
}

int solve() {
	sort(p + 1, p + N);
	
	for (int i = 0; i < offset; i++) {
		a[i] = i > 0 && i < N ? p[i].second - p[i].first + 1 : INF;
		t[i + offset] = node(i, a[i] != INF);
	}

	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
	
	ll curr = p[0].first;
	int sol = get(curr).sum + 1;
	while (curr > 0) {
		node tmp = get(curr);
		curr -= a[tmp.mini];
		update(tmp.mini);
		if (curr >= 0)
			sol = min(sol, get(curr).sum + 1);
	}
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}