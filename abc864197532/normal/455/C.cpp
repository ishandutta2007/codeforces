#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second

struct Dsu {
	int n;
	vector <int> dsu, size;
	Dsu (int _n): n(_n) {
		dsu.resize(n);
		size.resize(n);
		for (int i = 0; i < n; ++i) {
			dsu[i] = i;
			size[i] = 1;
		}
	}
	int Find(int a) {
		if (dsu[a] == a) return a;
		return dsu[a] = Find(dsu[a]);
	}
	bool Union(int a, int b) {
		int x = Find(a), y = Find(b);
		if (x == y) return false;
		if (size[x] > size[y]) {
			dsu[x] = y;
			size[y] += size[x];
			size[x] = 0;
		} else {
			dsu[y] = x;
			size[x] += size[y];
			size[y] = 0;
		}
		return true;
	}
};
 
const int N = 300087;
vector <int> adj[N];
int ans[N];
vector <bool> vis;

pii dfs(int v, int pa, int dist = 0) {
  pii A = {dist, v};
  vis[v] = true;
  for (int u : adj[v]) {
    if (u != pa) A = max(A, dfs(u, v, dist + 1));
  }
  return A;
}

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, q, u, v, t;
  cin >> n >> m >> q;
  Dsu dsu(n);
  vis.resize(n, false);
  fop (i,0,m) {
    cin >> u >> v; u--, v--;
    adj[u].pb(v);
    adj[v].pb(u);
    dsu.Union(u, v);
  }
  fop (i,0,n) {
    if (!vis[i]) {
      tie(u, v) = dfs(i, -1);
      tie(ans[dsu.Find(i)], ignore) = dfs(v, -1);
    }
  }
  while (q--) {
    cin >> t >> u; u--;
    if (t == 1) cout << ans[dsu.Find(u)] << endl;
    else {
      cin >> v; v--;
      u = dsu.Find(u), v = dsu.Find(v);
      if (dsu.Union(u, v)) {
        ans[dsu.Find(u)] = max({(ans[u] + 1) / 2 + (ans[v] + 1) / 2 + 1, ans[u], ans[v]});
      }
    }
  }
}