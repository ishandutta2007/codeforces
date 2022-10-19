#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
// KACTL

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
  vector<vector<int>>G(n);
  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    G[a-1].push_back(b-1);
    edges.emplace_back(a-1, b-1, l);
  }
  vector<int> ind(n);
  vector<vector<int>> components;
  scc(G, [&](vector<int>& v) {
      for (int x: v) {
        ind[x] = components.size();
      }
      components.push_back(v);
  });

  vector<vector<pair<int, int>>> Gcomp(n);
  for (tuple<int, int, int>& t: edges) {
    if (ind[get<0>(t)] == ind[get<1>(t)]) {
      Gcomp[get<0>(t)].push_back(make_pair(get<1>(t), get<2>(t)));
    }
  }

  long long g;
  vector<bool> vis(n);
  vector<long long> res(n);
  vector<long long> gcds(components.size());
  function<void(int)> dfs = [&] (int v) {
    vis[v] = 1;
    for (pair<int, int>& e: Gcomp[v]) {
      if (vis[e.first]) {
        long long diff = abs(res[e.first]-res[v]-e.second);
        g = __gcd(diff, g);
        if (g) {
          res[v] %= g;
          res[e.first] %= g;
        }
      }
      else {
        res[e.first] = res[v] + e.second;
        if (g) res[e.first] %= g;
        dfs(e.first);
      }
    }
  };
  for (int i = 0; i < (int)components.size(); i++) {
    g = 0;
    dfs(components[i][0]);
    gcds[i] = g;
  }

  int q;
  cin >> q;
  while (q--) {
    int v, s, t;
    cin >> v >> s >> t;
    v--;
    if (!s) {
      cout << "YES\n";
      continue;
    }
    long long g = gcds[ind[v]];
    if (!g) {
      cout << "NO\n";
      continue;
    }
    cout << (s % __gcd<long long>(g, t) == 0 ? "YES" : "NO") << '\n';
  }
}