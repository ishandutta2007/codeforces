#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 1010;

int n;
vector<int> g[M];
bool me[M], chen[M];
int any = 0;
int that;

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
    me[i] = false;
    chen[i] = false;
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    me[x] = true;
  }

  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    chen[x] = true;
    any = x;
  }
}

int ask(char type, int x) {
  ++x;
  cout << type << " " << x << endl;
  int res;
  cin >> res;
  --res;
  return res;
}

void dfs(int v, int from) {
  if (me[v] && that == -1) {
    that = v;
  }
  for (int to : g[v])
    if (to != from)
      dfs(to, v);
}

void kill() {
  int from = ask('B', any);
  that = -1;
  dfs(from, -1);
  assert(that != -1);
  int x = ask('A', that);
  if (chen[x]) {
    cout << "C " << that + 1 << endl;
  } else {
    cout << "C " << -1 << endl;
  }
}

int main() {
#ifdef LOCAL
  //assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    read();
    kill();
  }
}