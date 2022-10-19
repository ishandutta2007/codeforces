#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 300300;
const int inf = 1e9;

int n, m;
vector<int> g[M];
int S, T;
int q[M], qs, qf;
bool used[M];
int d[M];
int from[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i)
    sort(all(g[i]));
  S = 0, T = n - 1;
}

void bfs(int v) {
  d[v] = 0;
  used[v] = true;
  from[v] = v;
  qs = qf = 0;
  q[qf++] = v;

  while (qs < qf) {
    int u = q[qs++];
    for (int to : g[u])
      if (!used[to]) {
        q[qf++] = to;
        d[to] = d[u] + 1;
        used[to] = true;
        from[to] = u;
      }
  }
}

vector<int> restore(int x) {
  vector<int> res;
  while (x != S) {
    res.push_back(x);
    x = from[x];
  }
  res.push_back(x);
  reverse(all(res));
  return res;
}

void print(const vector<int> ans) {
  cout << ans.size() - 1 << endl;
  for (int x : ans)
    cout << x + 1 << " ";
  cout << endl;
}

bool conn(int x, int y) {
  return binary_search(all(g[x]), y);
}

void kill() {
  fill(used, used + n, false);
  fill(d, d + n, inf);
  bfs(S);

  int ans = inf;
  if (d[T] < inf) {
    ans = min(ans, d[T]);
  }

  if (ans <= 3) {
    vector<int> path = restore(T);
    print(path);
    return;
  }

  for (int u = 0; u < n; ++u)
    if (d[u] == 2) {
      assert(from[from[u]] == S);
      vector<int> ans = {S, from[u], u, S, T};
      print(ans);
      return;
    }

  for (int u = 0; u < n; ++u)
    if (d[u] == 1) {
      for (int i = 1; i < (int) g[u].size(); ++i) {
        int x = g[u][i];
        int a = 0;
        for (int j = i + 1; j < (int) g[u].size(); ++j) {
          int y = g[u][j];
          while (a < (int) g[x].size() && g[x][a] < y)
            ++a;
          bool ok = (a == (int) g[x].size()) || g[x][a] > y;
          if (ok) {
            assert(d[x] == 1);
            assert(d[y] == 1);
            vector<int> ans = {S, x, u, y, x, T};
            print(ans);
            return;
          }
        }
      }
    }

  cout << "-1\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}