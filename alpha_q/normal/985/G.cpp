#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef unsigned long long ull;

const int N = 200005;

bitset <N> vis;
int n, m, d[N], bound;
vector <int> g[N];
set <int> h[N];
ull a, b, c, ans, sum[N];

inline ull get (int u, int v) {
	if (u > v) swap(u, v);
	ull x = a * u * 1LLU * (u - 1) / 2 + u * (b * u + c * v);
	ull y = b * (v * 1LLU * (v - 1) - u * 1LLU * (u + 1)) / 2 + (v - u - 1) * (a * u + c * v);
	ull z = c * (n * 1LLU * (n - 1) - v * 1LLU * (v + 1)) / 2 + (n - v - 1) * (a * u + b * v);
	return x + y + z;
}

inline ull val (int u, int v, int w) {
	int x[3] = {u, v, w};
	sort(x, x + 3);
	return a * x[0] + b * x[1] + c * x[2];
}

// void dfs (ull u, ull from = n) {
// 	vis[u] = 1;
// 	for (ull v : g[u]) {
// 		if (v == from) {
// 			continue;
// 		}
// 		if (vis[v]) {
// 			if (binary_search(g[v].begin(), g[v].end(), from)) {
// 				ans -= val(u, v, from);
// 			}
// 			continue;
// 		}
// 		dfs(v, u);
// 	}
// }

typedef pair <int, int> pii;

vector <pii> edges;
bitset <N> isHeavy;
vector <int> heavy;

inline bool isEdge (int u, int v) {
	return h[u].find(v) != h[u].end();
}

void triangles() {
	for (int i = 0; i < n; ++i) {
		if (d[i] > bound) {
			heavy.push_back(i);
			isHeavy[i] = 1;
		}
	}
	// heavy
	for (int u : heavy) {
		for (pii e : edges) {
			int v = e.first, w = e.second;
			if (isHeavy[v] and v < u) continue;
			if (isHeavy[w] and w < u) continue;
			if (isEdge(u, v) and isEdge(u, w)) {
				ans -= val(u, v, w);
			}
		}
	}
	// light
	for (pii e : edges) {
		int u = e.first, v = e.second;
		if (u > v) swap(u, v);
		if (isHeavy[u] or isHeavy[v]) continue;
		for (int i = 0, j = 0; i < g[u].size() and j < g[v].size();) {
			if (g[u][i] == g[v][j]) {
				int w = g[u][i];
				if (!isHeavy[w] and w > v) {
					ans -= val(u, v, w);
				}
				++i;
			} else if (g[u][i] < g[v][j]) {
				++i;
			} else {
				++j;
			}
		}
	}
}

int main() {
	scanf("%d %d %llu %llu %llu", &n, &m, &a, &b, &c);
	bound = 1000;
  for (ull k = 0; k < n; ++k) {
  	ull x = k * (k - 1) / 2;
  	ull y = k * (a + 2 * b + 3 * c) - (2 * a + b);
  	if (x % 3 == 0) x /= 3;
  	else y /= 3;
  	ans += x * y;
  }
  while (m--) {
  	int u, v;
  	scanf("%d %d", &u, &v);
  	++d[u], ++d[v];
  	edges.emplace_back(u, v);
  	ans -= get(u, v);
  	g[u].push_back(v);
  	g[v].push_back(u);
  	h[u].insert(v);
  	h[v].insert(u);
  }
  for (int i = 0; i < n; ++i) {
  	sort(g[i].begin(), g[i].end());
  	int sz = g[i].size();
  	for (int j = 0; j < sz; ++j) {
  		sum[j + 1] = sum[j] + g[i][j];
  	}
  	int at = 0;
  	while (at < sz and g[i][at] < i) {
  		++at;
  	}
  	for (int j = 0; j < sz; ++j) {
  		ull cur;
  		int u = g[i][j];
  		if (u > i) {
  			cur = (sz - 1 - j) * (a * i + b * u) + c * (sum[sz] - sum[j + 1]);
  			ans += cur;
  		}
  		if (u < i) {
	  		cur = (sz - at) * (a * u + b * i) + c * (sum[sz] - sum[at]);
	  		ans += cur;
	  		cur = j * (b * u + c * i) + a * sum[j];
	  		ans += cur;
  		}
  	}
  }
  triangles();
  printf("%llu\n", ans);
  return 0;
}