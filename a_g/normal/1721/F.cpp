#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

vector<int> match;

vi cover(vector<vi>& g, int n, int m) {
  match.resize(m, -1);
	int res = hopcroftKarp(g, match);
	vector<bool> lfound(n, true), seen(m);
	for (int it : match) if (it != -1) lfound[it] = false;
	vi q, cover;
	rep(i,0,n) if (lfound[i]) q.push_back(i);
	while (!q.empty()) {
		int i = q.back(); q.pop_back();
		lfound[i] = 1;
		for (int e : g[i]) if (!seen[e] && match[e] != -1) {
			seen[e] = true;
			q.push_back(match[e]);
		}
	}
	rep(i,0,n) if (!lfound[i]) cover.push_back(i);
	rep(i,0,m) if (seen[i]) cover.push_back(n+i);
	assert(sz(cover) == res);
	return cover;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n1, n2, m, q;
  cin >> n1 >> n2 >> m >> q;
  vector<vector<int>> g(n1);
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    edges[i] = make_pair(x, n1+y);
  }

  vector<int> c = cover(g, n1, n2);
  vector<int> vtx_to_edge_index(n1+n2);
  for (int i = 0; i < m; i++) {
    int x = edges[i].first;
    int y = edges[i].second;
    if (match[y-n1] == x) {
      if (binary_search(c.begin(), c.end(), x)) {
        vtx_to_edge_index[x] = i+1;
      }
      else {
        assert(binary_search(c.begin(), c.end(), y));
        vtx_to_edge_index[y] = i+1;
      }
    }
  }
  for (int v: c) {
    assert(vtx_to_edge_index[v]);
  }

  long long cur_weight = accumulate(vtx_to_edge_index.begin(), vtx_to_edge_index.end(), 0LL);

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      assert(c.size());
      cout << "1\n";
      int v = c.back();
      cur_weight -= vtx_to_edge_index[v];
      if (v < n1) v++;
      else v = -(v-n1+1);
      cout << v << '\n';
      cout << cur_weight << endl;
      c.pop_back();
    }
    else {
      assert(type == 2);
      cout << c.size() << '\n';
      for (int v: c) {
        cout << vtx_to_edge_index[v] << ' ';
      }
      cout << endl;
    }
  }
}