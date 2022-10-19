#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200200;

int n, k, b;
vector<int> g[M];
int a[M];
int sub[M];
bool full[M];
int ans;
bool up[M];

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}


int dfs_sub(int v, int u) {
  sub[v] = 1;
  for (int to : g[v])
    if (to != u) {
      sub[v] += dfs_sub(to, v);
    }
  return sub[v];
}


bool dfs_full(int v, int u) {
  full[v] = a[v] >= b;
  for (int to : g[v])
    if (to != u) {
      full[v] &= dfs_full(to, v);
    }
  return full[v];
}

void dfs_up(int v, int u) {
  assert(up[v]);

  int sum = 0;
  int cnt = 0;

  for (int to : g[v])
    if (to != u) {
      sum += full[to];
      cnt++;
    }

  if (a[v] >= b)
    for (int to : g[v])
      if (to != u) {
        if (sum - full[to] == cnt - 1) {
          up[to] = true;
          dfs_up(to, v);
        }
      }
}


int dfs(int v, int u) {
  int cur = 1;
  int mx1 = 0, mx2 = 0;

  for (int to : g[v])
    if (to != u) {
      int x = dfs(to, v);

      if (x == sub[to]) {
        cur += x;
      } else if (x > mx1) {
        mx2 = mx1;
        mx1 = x;
      } else if (x > mx2) {
        mx2 = x;
      }
    }

  if (a[v] >= b) {
    int bon = cur + mx1 + mx2;
    if (up[v])
      bon += n - sub[v];
    ans = max(ans, bon);
    return cur + mx1;
  } else {
    return 0;
  }
}

bool pos(int m) {
  b = m;

  int st = 0;

  dfs_full(st, n);

  fill(up, up + n, false);
  up[0] = true;
  dfs_up(st, n);

  ans = 0;
  dfs(st, n);

  return ans >= k;
}

void kill() {
  dfs_sub(0, n);

  int l = 0, r = 1e6;
  while (l < r) {

    int m = (l + r) / 2;

    if (pos(m + 1))
      l = m + 1;
    else
      r = m;
  }

  cout << l << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}