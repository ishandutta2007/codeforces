#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e5 + 5;
const int offset = 1 << 17;
const int INF = 0x3f3f3f3f;

int N, R, M;
int a[MAXN];
vector <pii> t[2 * offset];
int disc[MAXN], fin[MAXN];
vector <int> E[MAXN];
int depth[MAXN];
int timer;

void load() {
	scanf("%d%d", &N, &R);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	for (int i = 1; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
}

void dfs(int x, int p) {
	depth[x] = depth[p] + 1;
	disc[x] = timer++;
	t[disc[x] + offset].push_back({depth[x], a[x]});
	for (auto it : E[x])
		if (it != p)
			dfs(it, x);
	fin[x] = timer;
}

int query(int x, int lo, int hi, int from, int to, int val) {
	if (lo >= to || hi <= from)
		return INF;
	if (lo >= from && hi <= to) {
		auto it = lower_bound(t[x].begin(), t[x].end(), pii(val + 1, 0));
		return it == t[x].begin() ? INF : (--it) -> second;
	}
	int mid = (lo + hi) / 2;
	return min(query(2 * x, lo, mid, from, to, val), query(2 * x + 1, mid, hi, from, to, val));
}

void solve() {
	dfs(R, 0);
	
	for (int i = offset - 1; i >= 0; i--) {
		for (auto it : t[2 * i])
			t[i].push_back(it);
		for (auto it : t[2 * i + 1])
			t[i].push_back(it);
		sort(t[i].begin(), t[i].end());
		for (int j = 1; j < t[i].size(); j++)
			t[i][j].second = min(t[i][j].second, t[i][j - 1].second);
	}
	
	scanf("%d", &M);
	int last = 0;
	while (M--) {
		int p, q;
		scanf("%d%d", &p, &q);
		int x = (p + last) % N + 1;
		int k = (q + last) % N;
		last = query(1, 0, offset, disc[x], fin[x], depth[x] + k);
		printf("%d\n", last);
	}
}

int main() {
	load();
	solve();
	return 0;
}