#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair

const int A = 20;
const int M = 400400;

struct Max {
  int x, ax, y, ay;

  Max() {
    x = ax = y = ay = -1;
  }

  void upd(int X, int AX) {
    if (AX > ax) {
      y = x;
      ay = ax;
      x = X;
      ax = AX;
    } else if (AX > ay) {
      y = X;
      ay = AX;
    }
  }

  int get(int ex) {
    if (x != ex)
      return ax;
    else
      return ay;
  }
} val[M];

pair<int, int> p[A][M];
pair<int, int> f[M];
int w[M];
int n;
int s[M];
vector<int> g[M];
bool ans[M];

bool big(int x) {
  return 2 * x > n;
}

void read() {
  cin >> n;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
}

void dfss(int v, int from) {
  s[v] = 1;
  for (int to : g[v])
    if (to != from) {
      dfss(to, v);
      s[v] += s[to];
    }
}

void dfsf(int v, int from) {
  f[v] = mp(v, v);

  int wup = n - s[v];
  if (big(wup)) {
    f[v] = mp(v, from); 
    w[v] = wup;
  }

  if (from != -1)
    val[v].upd(from, wup);

  for (int to : g[v])
    if (to != from) {
      
      if (big(s[to])) {
        f[v] = mp(v, to);
        w[v] = s[to];
      }

      dfsf(to, v);
      val[v].upd(to, s[to]);
    }
}

pair<int, int> merge(int u, int v, int tu, int tv) {
  if (v != tu) {
    assert(tu != tv);
    return mp(tu, tv);
  } else {
    if (tu != tv) {
      return mp(tu, tv);
    } else {
      return mp(u, v);
    }
  }
}

void calc() {
  for (int i = 0; i < n; ++i)
    p[0][i] = f[i];

  for (int j = 0; j + 1 < A; ++j)
    for (int i = 0; i < n; ++i) {
      int u = p[j][i].first;
      int v = p[j][i].second;
      int tu = p[j][v].first;
      int tv = p[j][v].second;
      p[j + 1][i] = merge(u, v, tu, tv);
    }

  for (int i = 0; i < n; ++i)
    f[i] = p[A - 1][i];
}

void dfs(int v, int from) {
  if (w[v] == 0) {
    ans[v] = true;
  } else {
    int y = f[v].first;
    int x = f[v].second;

    int mx = val[x].get(y);
    assert(!big(mx));
    ans[v] = !big(w[v] - mx);
  }

  for (int to : g[v])
    if (to != from) 
      dfs(to, v);
}

void kill() {
  dfss(0, -1);
  dfsf(0, -1);
  calc();
  dfs(0, -1);

  for (int i = 0; i < n; ++i)
    cout << (ans[i] ? 1 : 0) << " ";
  cout << endl;
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}