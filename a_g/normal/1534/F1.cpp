#include <bits/stdc++.h>
using namespace std;

// KACTL
//
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  for (string& row: grid) cin >> row;
  vector<int> a(m);
  for (int& x: a) cin >> x;
  vector<vector<int>> icol(m);
  int z = 0;
  vector<vector<int>> id(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#') {
        id[i][j] = z++;
        icol[j].push_back(i);
      }
    }
  }
  if (!z) {
    cout << "0\n";
    return 0;
  }

  vector<vector<int>> G(z);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#') {
        int k = id[i][j];
        if (i && grid[i-1][j] == '#') {
          G[k].push_back(id[i-1][j]);
        }
        auto it = lower_bound(icol[j].begin(), icol[j].end(), i+1);
        if (it != icol[j].end()) {
          G[k].push_back(id[*it][j]);
        }
        if (j) {
          auto it = lower_bound(icol[j-1].begin(), icol[j-1].end(), i);
          if (it != icol[j-1].end()) {
            G[k].push_back(id[*it][j-1]);
          }
        }
        if (j < m-1) {
          auto it = lower_bound(icol[j+1].begin(), icol[j+1].end(), i);
          if (it != icol[j+1].end()) {
            G[k].push_back(id[*it][j+1]);
          }
        }

        /*
        cout << k << endl;
        for (int v: G[k]) {
          cout << v << ' ';
        }
        cout << endl << endl;
        */
      }
    }
  }

  auto f = [&] (vector<int> v) {};
  scc(G, f);
  int l = *max_element(comp.begin(), comp.end())+1;
  vector<vector<int>> G2(l);
  for (int i = 0; i < z; i++) {
    for (int v: G[i]) {
      if (comp[v] != comp[i]) G2[comp[i]].push_back(comp[v]);
    }
  }


  vector<int> indeg(l);
  for (int i = 0; i < l; i++) {
    sort(G2[i].begin(), G2[i].end());
    G2[i].resize(unique(G2[i].begin(), G2[i].end())-G2[i].begin());
    for (int v: G2[i]) {
      indeg[v]++;
    }
    /*
    cout << i << endl;
    for (int v: G2[i]) {
      cout << v << ' ';
    }
    cout << endl << endl;
    */
  }

  int ans = 0;
  for (int i = 0; i < l; i++) {
    if (indeg[i] == 0) {
      ans++;
    }
  }
  cout << ans << '\n';
}