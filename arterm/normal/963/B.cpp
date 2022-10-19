#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 200200;
const int ROOT = 239;

int n;
vector<int> g[M];
bool t[M];

void add_edge(int x, int y) {
  g[x].push_back(y);
  g[y].push_back(x);
}

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    if (p != 0)
      add_edge(i, p - 1);
  }
}

int dfs(int v, int from) {
  int A = 0, B = 0;
  for (int u : g[v])
    if (u != from) {
      int tu = dfs(u, v);
      if (tu == 1)
        ++A;
      else
        ++B;
    }
  if (B % 2 == 0)
    return t[v] = 0;
  else
    return t[v] = 1;
}

vector<int> ans;

void ffs(int v, int from) {
  for (int u : g[v])
    if (u != from) {
      if (t[u] == 1)
        ffs(u, v);
    }
  ans.push_back(v);
  for (int u : g[v])
    if (u != from) {
      if (t[u] == 0)
        ffs(u, v);
    }
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  int root = ROOT % n;
  int res = dfs(root, -1);
  if (res == 1) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  ffs(root, -1);
  for (int x : ans)
    cout << x + 1 << "\n";
}