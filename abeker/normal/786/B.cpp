#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int offset = 1 << 17;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int N, Q, S;
vector <pii> E[4 * offset];
ll dist[4 * offset];

struct cmp {
	bool operator()(const int &lhs, const int &rhs) const {
		if (dist[lhs] != dist[rhs])
			return dist[lhs] < dist[rhs];
		return lhs < rhs;
	}
};

set <int, cmp> curr;

void add_edge(int u, int v, int w) {
	E[u].push_back({v, w});
}

void update(int x, int lo, int hi, int from, int to, int t, int v, int w) {
	if (lo >= to || hi <= from)
		return;
	if (lo >= from && hi <= to) {
		if (t == 2)
			add_edge(v, x, w);
		else
			add_edge(x >= offset ? x : x + 2 * offset, v, w);
		return;
	}
	int mid = (lo + hi) / 2;
	update(2 * x, lo, mid, from, to, t, v, w);
	update(2 * x + 1, mid, hi, from, to, t, v, w); 
}

void load() {
	scanf("%d%d%d", &N, &Q, &S);
	S += offset;
	while (Q--) {
		int t, v;
		scanf("%d%d", &t, &v);
		v += offset;
		if (t == 1) {
			int u, w;
			scanf("%d%d", &u, &w);
			add_edge(v, u + offset, w);
		}
		else {
			int l, r, w;
			scanf("%d%d%d", &l, &r, &w);
			update(1, 0, offset, l, r + 1, t, v, w);
		}
	}
}

void solve() {
	for (int i = 1; i < offset; i++) {
		add_edge(i, 2 * i, 0);
		add_edge(i, 2 * i + 1, 0);
		add_edge(2 * i >= offset ? 2 * i : 2 * i + 2 * offset, i + 2 * offset, 0);
		add_edge(2 * i + 1 >= offset ? 2 * i + 1 : 2 * i + 1 + 2 * offset, i + 2 * offset, 0);
	}
	
	memset(dist, INF, sizeof dist);
	dist[S] = 0;
	for (int i = 1; i < 4 * offset; i++)
		curr.insert(i);
	
	while (!curr.empty()) {
		int x = *curr.begin();
		curr.erase(x);
		for (auto it : E[x])
			if (curr.count(it.first)) {
				ll cand = dist[x] + it.second;
				if (cand < dist[it.first]) {
					curr.erase(it.first);
					dist[it.first] = cand;
					curr.insert(it.first);
				}
			}
	}
	
	for (int i = 1; i <= N; i++)
		printf("%lld ", dist[i + offset] == INF ? -1 : dist[i + offset]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}