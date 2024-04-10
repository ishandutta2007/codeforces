#include <bits/stdc++.h>
using  namespace std;
typedef bool boolean;

#define ll long long

const int N = 1e4 + 5;
const ll llf = (signed ll) (~0ull >> 2);

int cmp_sgn = -1;

typedef class Node {
	public:
		int p;
		ll d;
		int org;

		Node() {	}
		Node(int p, ll d, int org) : p(p), d(d), org(org) {	}

		boolean operator < (Node b) const {
			return (d ^ b.d) ? (d > b.d) : (org * cmp_sgn > b.org * cmp_sgn);
		}
} Node;

typedef class Edge {
	public:
		int v, w, l, r, type, id;

		Edge(int v, int w) : v(v), w(w), type(0) {	}
		Edge(int v, int l, int r) : v(v), w(l), l(l), r(r), type(1) {	}
} Edge;

int n, m, K;
int s1, s2, fin;
vector<Edge> G[N];

ll f[2][N];
void dijkstra() {
	priority_queue<Node> Q;
	for (int i = 1; i <= n; i++) {
		f[0][i] = f[1][i] = llf;
	}
	Q.push(Node(s1, f[0][s1] = 0, 0));
	Q.push(Node(s2, f[1][s2] = 0, 1));
	while (!Q.empty()) {
		Node e = Q.top();
		Q.pop();
		int p = e.p, org = e.org;
		if (e.d ^ f[org][p])
			continue;
		for (auto& E : G[p]) {
			int q = E.v, &type = E.type, &w = E.w;
			if (type == 1) {
				type = 2;
				w = (!org) ? (E.l) : (E.r);
			}
			ll d = e.d + w;
			if (d < f[org][q]) {
				Q.push(Node(q, f[org][q] = d, org));
			}
		}
	}
}

int ans[N];
int main() {
	scanf("%d%d%d", &n, &m, &K);
	scanf("%d%d%d", &s1, &s2, &fin);
	for (int i = 1, u, v, w; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].emplace_back(v, w);
	}
	for (int i = 1, u, v, l, r; i <= K; i++) {
		scanf("%d%d%d%d", &u, &v, &l, &r);
		G[u].emplace_back(v, l, r);
		G[u].back().id = i;
	}
	dijkstra();
	if (f[0][fin] < f[1][fin]) {
		puts("WIN");
		for (int i = 1; i <= n; i++) {
			for (auto E : G[i]) {
				if (E.type) {
					ans[E.id] = E.w;
				}
			}
		}
		for (int i = 1; i <= K; i++) {
			printf("%d ", ans[i]);
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (auto& E : G[i]) {
			if (E.type) {
				E.type = 1;
			}
		}
	}
	cmp_sgn = 1;
	dijkstra();
	if (f[0][fin] <= f[1][fin]) {
		puts("DRAW");
		for (int i = 1; i <= n; i++) {
			for (auto E : G[i]) {
				if (E.type) {
					ans[E.id] = E.w;
				}
			}
		}
		for (int i = 1; i <= K; i++) {
			printf("%d ", ans[i]);
		}
	} else {
		puts("LOSE");
	}
	return 0;
}