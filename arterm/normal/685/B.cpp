#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 300200;

int n, q;
int s[M], p[M], x[M];
vector<int> g[M];

void read() {
  cin >> n >> q;
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i + 1);
    p[i + 1] = x;
  }
  p[0] = 0;
}

void dfs(int v) {
  s[v] = 1;

  int mx = -1;

  for (int to : g[v]) {
    dfs(to);
    s[v] += s[to];
    if (mx == -1 || s[to] > s[mx])
      mx = to;
  }

  if (mx == -1 || s[mx] * 2 < s[v]) {
    x[v] = v;
    return;
  } else {
    x[v] = x[mx];
    while (x[v] != v && s[x[v]] * 2 < s[v])
      x[v] = p[x[v]];
    assert(s[x[v]] * 2 >= s[v]);
  }
}


void kill() {
  dfs(0);
  for (int i = 0; i < q; ++i) {
    int y;
    cin >> y;
    --y;
    cout << x[y] + 1 << "\n";
  }
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}