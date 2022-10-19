#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MAXN = 2e3 + 5;

struct myBitset {
	ull mask[32];
	
	myBitset() {
		memset(mask, 0, sizeof mask);
	}
	
	void flip(int lo, int hi) {
		if (lo) {
			flip(0, lo);
			flip(0, hi);
			return;
		}
		int idx = hi >> 6;
		for (int i = 0; i < idx; i++)
			mask[i] = ~mask[i];
		mask[idx] ^= (1ull << (hi & 63)) - 1;
	}
	
	int count() {
		int res = 0;
		for (int i = 0; i < 32; i++)
			res += __builtin_popcountll(mask[i]);
		return res;
	}
};

int N, M, Q;
myBitset row[MAXN];
int blue[MAXN];
unordered_set <int> good;

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (blue[lhs] != blue[rhs])
			return blue[lhs] < blue[rhs];
		return lhs < rhs;		
	}
};

set <int, cmp> sorted;

int check_subset(int x, int y) {
	for (int i = 0; i < 32; i++) {
		ull diff = (row[x].mask[i] & row[y].mask[i]) ^ row[x].mask[i];
		if (diff)
			return (i << 6) | __builtin_ctzll(diff);
	}
	return -1;
}

void out(int x) {
	auto it = sorted.find(x);
	int prv = 0, nxt = 0;
	if (it != sorted.begin()) {
		auto it1 = it;
		prv = *(--it1);
	}
	if (it != --sorted.end()) {
		auto it2 = it;
		nxt = *(++it2);
	}
	good.erase(prv);
	good.erase(x);
	if (prv && nxt && check_subset(prv, nxt) != -1)
		good.insert(prv);
	sorted.erase(x);
}

void in(int x) {
	sorted.insert(x);
	auto it = sorted.find(x);
	int prv = 0, nxt = 0;
	if (it != sorted.begin()) {
		auto it1 = it;
		prv = *(--it1);
	}
	if (it != --sorted.end()) {
		auto it2 = it;
		nxt = *(++it2);
	}
	good.erase(prv);
	if (prv && check_subset(prv, x) != -1)
		good.insert(prv);
	if (nxt && check_subset(x, nxt) != -1)
		good.insert(x);
}

void construct(int x1, int x2) {
	int y1 = check_subset(x1, x2) + 1;
	int y2 = check_subset(x2, x1) + 1;
	printf("%d %d %d %d\n", min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2));
}

void update(int x, int l, int r) {
	out(x);
	row[x].flip(l - 1, r);
	blue[x] = row[x].count();
	in(x);
	if (good.empty()) {
		puts("-1");
		return;
	}
	int ans = *good.begin();
	construct(ans, *(++sorted.find(ans)));
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	
	for (int i = 1; i <= N; i++)
		sorted.insert(i);
		
	while (Q--) {
		int x, l, r;
		scanf("%d%d%d", &x, &l, &r);
		update(x, l, r);
	}
	
	return 0;
}