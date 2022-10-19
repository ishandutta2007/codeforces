#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 500005;
const int INF = 0x3f3f3f3f;
const int offset = 1 << 19;

struct node {
	int maks, lazy;
	node(int maks, int lazy) : maks(maks), lazy(lazy) {}
	node() : maks(-INF), lazy(0) {}
};

struct tournament {	
	node t[2 * offset];
	
	node merge(node l, node r) {
		return {max(l.maks, r.maks), l.lazy + r.lazy};
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
	
	node query(int x, int lo, int hi, int from, int to) {
		prop(x);
		if (lo >= to || hi <= from)
			return node();
		if (lo >= from && hi <= to) 
			return t[x];
		int mid = (lo + hi) / 2;
		return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
	}
	
	int query(int from, int to) {
		return query(1, 0, offset, from, to).maks;
	}
	
	int get(int x) {
		if (x >= offset)
			return x - offset;
		prop(2 * x);
		prop(2 * x + 1);
		if (t[2 * x].maks >= 0)
			return get(2 * x);
		return get(2 * x + 1);
	}
};

int N;
pii p[MAXN];
int pos[MAXN];
tournament T1, T2;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
}

void solve() {
	sort(p, p + N);
	for (int i = 0; i < N; i++)
		pos[p[i].second] = i;
	
	for (int i = 0; i < N; i++) {
		T1.update(pos[i], pos[i] + 1, p[pos[i]].first + INF);
		T1.update(pos[i] + 1, offset, 1);
		T2.update(pos[i], pos[i] + 1, INF - p[pos[i]].first);
		T2.update(0, pos[i], -1);
		int tmp = T1.get(1);
		if (tmp >= N) {
			printf("%d\n", -i - 1);
			continue;
		}
		int sol = p[tmp].first - T1.query(tmp, tmp + 1);
		sol = min(-T2.query(tmp + 1, offset), sol - p[tmp].first - T2.query(tmp, tmp + 1) + (sol < p[tmp].first));
		printf("%d\n", sol);
	}
}

int main() {
	load();
	solve();
	return 0;
}