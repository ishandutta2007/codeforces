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

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> small, big;
  while (n--) {
    int t;
    cin >> t;
    if (t > m/2) {
      cout << "-1\n";
      return 0;
    }
    if (t > m/3) {
      big.push_back(t);
    }
    else {
      small.push_back(t);
    }
  }
  int l = big.size();
  int r = small.size();
  vector<vector<int>> g(l);
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < r; j++) {
      if (big[i]%small[j] == 0 && 2LL*big[i]+small[j] <= m) {
        g[i].push_back(j);
      }
    }
  }
  vector<int> btoa(r, -1);
  if (hopcroftKarp(g, btoa) < l) {
    cout << "-1\n";
    return 0;
  }
  cout << r << '\n';
  for (int i = 0; i < r; i++) {
    if (btoa[i] == -1) {
      cout << 3*small[i] << " " << 2*small[i] << '\n';
    }
    else {
      cout << 2*big[btoa[i]]+small[i] << " " << big[btoa[i]]+small[i] << '\n';
    }
  }
}