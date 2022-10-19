#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const int MOD = 998244353;

struct event {
	int num, denom, pos, type;
	bool operator <(const event &rhs) const {
		return (ll)num * rhs.denom < (ll)denom * rhs.num;
	}
	void output() const {
		printf("%d/%d %d %d\n", num, denom, pos, type);
	}
};

struct node {
	int zero, one, mono;
	node() {
		zero = one = mono = 1;
	}
	node(int zero, int one, int mono) : 
		zero(zero), one(one), mono(mono) {}
};

int N;
node t[2 * offset];
int x[MAXN], v[MAXN], p[MAXN];
int dad[MAXN], lft[MAXN], rig[MAXN];
int last_zero[MAXN], first_one[MAXN];
int value[MAXN];
int dir[MAXN];
int prob;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d%d", x + i, v + i, p + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	if (x < 0)
		return x + MOD;
	return x;
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int divide(int x, int y) {
	assert(y);
	return mul(x, pot(y, MOD - 2));
}

node merge(node lhs, node rhs) {
	return node(mul(lhs.zero, rhs.zero), mul(lhs.one, rhs.one), add(add(mul(lhs.zero, rhs.mono), mul(lhs.mono, rhs.one)), -mul(lhs.zero, rhs.one)));
}

node query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return node();
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

node query(int from, int to) {
	return query(1, 0, offset, from, to);
}

void recalc(int x) {
	if (last_zero[x] > first_one[x]) 
		value[x] = 0;
	else {
		node pref = query(lft[x], last_zero[x] + 1);
		node middle = query(max(lft[x], last_zero[x] + 1), min(rig[x] + 1, first_one[x]));
		node suff = query(first_one[x], rig[x] + 1);
		value[x] = mul(mul(pref.zero, suff.one), middle.mono);
	}
	prob = mul(prob, value[x]);
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	prob = divide(prob, value[x]);
	prob = divide(prob, value[y]);
	if (rig[x] - lft[x] > rig[y] - lft[y])
		swap(x, y);
	dad[x] = y;
	lft[y] = min(lft[x], lft[y]);
	rig[y] = max(rig[x], rig[y]);
	last_zero[y] = max(last_zero[x], last_zero[y]);
	first_one[y] = min(first_one[x], first_one[y]);
	recalc(y);
}

void update(int x, int val) {
	if (dir[x] != -1 && dir[x] != val) {
		prob = 0;
		return;
	}
	dir[x] = val;
	int root = find(x);
	if (val)	
		first_one[root] = min(first_one[root], x);
	else
		last_zero[root] = max(last_zero[root], x);
	prob = divide(prob, value[root]);
	recalc(root);
}

int solve() {
	for (int i = 0; i < N; i++)
		t[i + offset] = {divide(100 - p[i], 100), divide(p[i], 100), 1};
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	memset(dir, -1, sizeof dir);
	for (int i = 0; i < N; i++) {
		dad[i] = lft[i] = rig[i] = i;
		last_zero[i] = -1;
		first_one[i] = N;
		value[i] = 1;
	}
	
	vector <event> E;
	for (int i = 1; i < N; i++) {
		E.push_back({x[i] - x[i - 1], v[i - 1] + v[i], i - 1, -1});
		if (v[i - 1] > v[i])
			E.push_back({x[i] - x[i - 1], v[i - 1] - v[i], i - 1, 0});
		if (v[i - 1] < v[i])
			E.push_back({x[i] - x[i - 1], v[i] - v[i - 1], i, 1});
	}
	
	sort(E.begin(), E.end());
	
	prob = 1;
	int sol = 0, prv = 0;
	for (auto it : E) {
		int curr = divide(it.num, it.denom);
		sol = add(sol, mul(prob, add(curr, -prv)));
		prv = curr;
		if (!prob)
			continue;
		if (it.type == -1)
			join(it.pos, it.pos + 1);
		else 
			update(it.pos, it.type);
	}
	sol = add(sol, -mul(prob, prv));
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}