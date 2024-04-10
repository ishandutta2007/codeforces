#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 200100;

ll ans = 1e18, n;
vector<int> g[M];
int d[M];
bool used[M];
bool done[M];
int son[M];
int q[M], qs = 0, qf = 0;
ll x, y;

void relax(ll x) {
  ans = min(ans, x);
}

void read() {
  cin >> n;
  cin >> x >> y;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}


int par(int x) {
  assert(d[x] == 1);
  for (int y : g[x])
    if (!done[y])
      return y;
  assert(false);
}

void rem(int x) {
  done[x] = true;
  for (int y : g[x])
    if (!done[y]) {
      d[y]--;
      if (d[y] == 1) {
        q[qf++] = y;
      }
    }
}


void kill() {
  bool is = false;
  for (int i = 1; i <= n; ++i) {
    d[i] = g[i].size();
    is |= d[i] == n - 1;
  }

  if (is) {
    relax(x + y * (n - 2));
    if (n > 2)
      relax(2 * x + y * (n - 3));
  } else {
    relax(y * (n - 1));

    for (int i = 1; i <= n; ++i)
      if (d[i] == 1) {
        q[qf++] = i;
        used[i] = true;
      }
    
    while (qs < qf) {
      int v = q[qs++];
      assert(0 <= d[v] && d[v] <= 1);
      if (d[v] == 0) {
        done[v] = true;
        continue;
      }

      int p = par(v);
      if (son[v] < 2)
        son[p] = min(2, son[p] + 1);

      rem(v);
    }

    ll sum = accumulate(son, son + (n + 1), 0);
    relax(x * sum + (n - 1 - sum) * y);
  }
  
  cout << ans << endl;
}


int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill();
}