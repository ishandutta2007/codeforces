#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 300300;

int n, m;
vector<int> g[M];

struct Player {
  int id;
  int x, y;

  int d() const {
    return x - y;
  }

  bool operator<(const Player&to) const {
    return d() < to.d();
  }

  void read() {
    cin >> x >> y;
  }
} p[M];

ll sx[M], sy[M];
ll res[M];
int to[M];

void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    p[i].read();
    p[i].id = i;
  }

  sort(p, p + n);

  for (int i = 0; i < n; ++i)
    to[p[i].id] = i;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;

    u = to[u];
    v = to[v];

    g[u].push_back(v);
    g[v].push_back(u);
  }
}

ll fun(int i, int j) {
  return min(p[i].x + p[j].y, p[i].y + p[j].x);
}

void kill() {
  for (int i = 0; i < n; ++i) {
    sx[i + 1] = sx[i] + p[i].x;
    sy[i + 1] = sy[i] + p[i].y;
  }

  for (int i = 0; i < n; ++i) {
    ll ans = sx[i] - sx[0] + 1ll * i * p[i].y
      + (sy[n] - sy[i + 1]) + 1ll * (n - i - 1) * p[i].x;

    for (int j : g[i])
      ans -= fun(i, j);

    res[p[i].id] = ans;
  }

  for (int i = 0; i < n; ++i)
    cout << res[i] << " ";
  cout << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}