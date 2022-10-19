#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;
const int inf = M;

int n, m;
vector<int> g[M];
vector<char> h[M];

bool u[4][M];
bool usedb[M], usedr[M];
int colr[M], colb[M];
int c[M];
bool noans;


int dfs(int v, bool* u, int *c, char z) {
  u[v] = true;

  int ans = c[v];
   
  for (int i = 0; i < (int) g[v].size(); ++i) {
    int col;
    if (h[v][i] == z)
      col = c[v];
    else
      col = 1 - c[v];

    int to = g[v][i];

    if (u[to] && c[to] != col)
      noans = true;

    if (!u[to]) {
      c[to] = col;
      ans += dfs(to, u, c, z);
    }
  }

  return ans;
}

int dfsw(int v, bool* u, int *c, char z) {
  noans = false;
  int ans = dfs(v, u, c, z);
  if (noans)
    return inf;
  return ans;
}

void read() {
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    g[x].push_back(y);
    g[y].push_back(x);

    h[x].push_back(c);
    h[y].push_back(c);
  }
}

void kill() {
  int bans = 0, rans = 0;
  for (int v = 1; v <= n; ++v)
    if (!usedb[v]) {
      c[v] = 0;
      int b0 = dfsw(v, u[0], c, 'B');
      int r0 = dfsw(v, u[1], c, 'R');

      c[v] = 1;
      int b1 = dfsw(v, u[2], c, 'B');
      int r1 = dfsw(v, u[3], c, 'R');

      //cerr << "v = " << v << endl;
      //cerr << "b = " << b0 << ", " << b1 << endl;
      //cerr << "r = " << r0 << ", " << r1 << endl;

      if (b0 <= b1) {
        colb[v] = 0;
      } else {
        colb[v] = 1;
      }
      dfsw(v, usedb, colb, 'B');

      if (r0 <= r1) {
        colr[v] = 0;
      } else {
        colr[v] = 1;
      }
      dfsw(v, usedr, colr, 'R');

      bans += min(b0, b1);
      rans += min(r0, r1);

      bans = min(bans, inf);
      rans = min(rans, inf);
    }

  int ans = min(bans, rans);

  if (ans >= inf)
    cout << "-1\n";
  else {
    cout << ans << "\n";
    vector<int> a;
    if (bans <= rans) {
      for (int i = 1; i <= n; ++i)
        if (colb[i])
          a.push_back(i);
    } else {
      for (int i = 1; i <= n; ++i)
        if (colr[i])
          a.push_back(i);
    }

    assert((int) a.size() == ans);
    
    for (int x : a)
      cout << x << " ";
    cout << "\n";
  } 
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}