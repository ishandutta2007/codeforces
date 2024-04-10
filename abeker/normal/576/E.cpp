#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;
const int offset = 1 << 19;
const int MAXK = 55;

class UnionFind {
	private:
		int dad[MAXN], rnk[MAXN], clr[MAXN];
		void modify(int *ptr, int val) {
			ch.push({ptr, *ptr});
			*ptr = val;
		}
	public:
		stack <pair <int*, int>> ch;
		void init(int n) {
			for (int i = 1; i <= n; i++) {
				rnk[i] = clr[i] = 0;
				dad[i] = i;
			}
		}
		void revert(int sz) {
			for (; ch.size() > sz; ch.pop())
				*ch.top().first = ch.top().second;
		}
		pii find(int x) {
			if (dad[x] == x)
				return {x, 0};
			pii tmp = find(dad[x]);
			return {tmp.first, tmp.second ^ clr[x]};
		}
		void join(int x, int y) {
			pii rootX = find(x);
			pii rootY = find(y);
			if (rootX.first == rootY.first)
				return;
			if (rnk[rootX.first] > rnk[rootY.first])
				swap(rootX, rootY);
			modify(dad + rootX.first, rootY.first);
			if (rnk[rootX.first] == rnk[rootY.first])
				modify(rnk + rootY.first, rnk[rootY.first] + 1);
			modify(clr + rootX.first, rootX.second ^ rootY.second ^ 1);
		}
};

int N, M, K, Q;
int a[MAXN], b[MAXN];
int e[MAXN], c[MAXN];
int nxt[MAXN], lst[MAXN];
vector <pii> todo[2 * offset];
UnionFind byColour[MAXK];
int curr[MAXN];

void load() {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	for (int i = 1; i <= M; i++)
		scanf("%d%d", a + i, b + i);	
	for (int i = 0; i < Q; i++)
		scanf("%d%d", e + i, c + i);
}

void update(int x, int lo, int hi, int from, int to, pii toadd) {
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		todo[x].push_back(toadd);
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, toadd);
	update(2 * x + 1, mid, hi, from, to, toadd);
}

void dfs(int x) {
	vector <int> len(K + 1);
	for (int i = 1; i <= K; i++)
		len[i] = byColour[i].ch.size();
	for (auto it : todo[x])
		byColour[it.second].join(a[it.first], b[it.first]);
	if (x < offset) {
		dfs(2 * x);
		dfs(2 * x + 1);
	}
	else {
		int pos = x - offset;
		if (pos >= Q)
			exit(0);
		if (byColour[c[pos]].find(a[e[pos]]) != byColour[c[pos]].find(b[e[pos]])) {
			curr[e[pos]] = c[pos];
			puts("YES");
		}
		else
			puts("NO");
		if (curr[e[pos]])
			update(1, 0, offset, pos + 1, nxt[pos] + 1, {e[pos], curr[e[pos]]});
	}
	for (int i = 1; i <= K; i++)
		byColour[i].revert(len[i]);
}

void solve() {
	for (int i = 1; i <= K; i++)
		byColour[i].init(N);
		
	for (int i = 1; i <= M; i++)
		lst[i] = Q - 1;
	for (int i = Q - 1; i >= 0; i--) {
		nxt[i] = lst[e[i]];
		lst[e[i]] = i;
	}
	
	dfs(1);
}

int main() {
	load();
	solve();
	return 0;
}