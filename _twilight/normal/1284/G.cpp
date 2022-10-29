#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
  return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
  return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
  return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
  return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
  return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
  return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
  os << "(" << z.first << ", " << z.second << ')';
  return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
  boolean isfirst = true;
  os << "{";
  for (auto z : a) {
    if (!isfirst) {
      os << ", ";
    }
    os << z;
    isfirst = false;
  }
  os << '}';
  return os;
}

#define pii pair<int, int>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define ll long long
#define ull unsigned long long

const int inf = (signed) (~0u >> 2);
const ll llf = (signed ll) (~0ull >> 2);

#define pb push_back
#define eb emplace_back
#define fi first
#define sc second

typedef class Edge {
  public:
    int u, v;
    int rx, ry;

    Edge(int u, int v, int rx, int ry) : u(u), v(v), rx(rx), ry(ry) { }
} Edge;

typedef class UnionFound {
  public:
    int n;
    vector<int> f;

    void init(int n) {
      this->n = n;
      f.resize(n + 1, 0);
      for (int i = 1; i <= n; i++) {
        f[i] = i;
      }
    }
    int find(int x) {
      return f[x] == x ? x : (f[x] = find(f[x]));
    }
    void clear() {
      f.clear();
    }
    int operator [] (int x) {
      return find(x);
    }
    void unit(int x, int y) {
      x = find(x), y = find(y);
      (x ^ y) && (f[x] = y, 1);
    }
} UnionFound;

int R, C;
vector<bool> spe;
int id[22][22];
char Gi[22][22];
char Ga[44][44];
vector<Edge> E;

vector<int> pre;
vector<bool> vis, in;
vector<vector<int>> G;

void prepare(int n) {
  G.resize(n + 2, vector<int>());
  for (int i = 0; i <= n + 1; i++) {
    G[i].clear();
  }
  pre.resize(n + 2);
  in.resize(n + 2);
  vis.resize(n + 2);
  fill(in.begin(), in.end(), false);
}

bool bfs(int s, int t) {
  static queue<int> Q;
  fill(vis.begin(), vis.end(), false);
  vis[s] = true;
  Q.push(s);
  while (!Q.empty()) {
    int p = Q.front();
    Q.pop();
    for (auto e : G[p]) {
      if (!vis[e]) {
        pre[e] = p;
        vis[e] = true;
        Q.push(e);
      }
    }
  }
  return vis[t];
}

bool augment() {
  static vector<int> deg;
  static UnionFound uf;
  int n = E.size();
  for (int i = 0; i <= n + 1; i++) {
    G[i].clear();
  }
  vector<int> I, rI;
  for (int i = 0; i < n; i++) {
    if (in[i]) {
      I.push_back(i);
    } else {
      rI.push_back(i);
    }
  }
  for (auto x : I) {
    uf.init(R * C);
    for (auto y : I) {
      if (x ^ y) {
        uf.unit(E[y].u, E[y].v);
      }
    }
    for (auto y : rI) {
      int u = E[y].u;
      int v = E[y].v;
      if (uf[u] != uf[v]) {
        G[x + 1].push_back(y + 1);
      }
    }
  }
  deg.assign(R * C, 0);
  for (int i = 0; i < R * C; i++) {
    if (!spe[i]) {
      deg[i] = -142857;
    }
  }
  for (auto x : I) {
    deg[E[x].u]++;
    deg[E[x].v]++;
  }
  for (auto x : I) {
    deg[E[x].u]--;
    deg[E[x].v]--;
    for (auto y : rI) {
      int u = E[y].u;
      int v = E[y].v;
      if (deg[u] < 2 && deg[v] < 2) {
        G[y + 1].push_back(x + 1);
      }
    }
    deg[E[x].u]++;
    deg[E[x].v]++;
  }
  uf.init(R * C);
  for (auto x : I) {
    uf.unit(E[x].u, E[x].v);
  }
  for (auto x : rI) {
    if (uf[E[x].u] != uf[E[x].v]) {
      G[0].push_back(x + 1);
    }
    if (deg[E[x].u] < 2 && deg[E[x].v] < 2) {
      G[x + 1].push_back(n + 1);
    }
  }
  if (!bfs(0, n + 1)) {
    return false;
  }
  for (int i = pre[n + 1]; i; i = pre[i]) {
    in[i - 1] = !in[i - 1];
  }
  return true;
}

void solve() {
  memset(Gi, 0, sizeof(Gi));
  memset(Ga, 0, sizeof(Ga));
  cin >> R >> C;
  for (int i = 1; i <= 2 * R - 1; i++) {
    for (int j = 1; j <= 2 * C - 1; j++) {
      Ga[i][j] = ' ';
    }
  }
  for (int i = 1; i <= R; i++) {
    cin >> (Gi[i] + 1);
    for (int j = 1; j <= C; j++) {
      Ga[2 * i - 1][2 * j - 1] = Gi[i][j];
    }
  }
  spe.assign(R * C, false);
  int cnt = 0, S = 0;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (Gi[i][j] == 'O') {
        id[i][j] = cnt++;
        if (!((i + j) & 1) && i + j > 2) {
          spe[cnt - 1] = true;
          S += 2;
        }
      } else {
        id[i][j] = -1;
      }
    }
  }
  vector<Edge> Eall;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (Gi[i][j] == 'O') {
        if (Gi[i + 1][j] == 'O') {
          Eall.emplace_back(id[i][j], id[i + 1][j], 2 * i, 2 * j - 1);
        }
        if (Gi[i][j + 1] == 'O') {
          Eall.emplace_back(id[i][j], id[i][j + 1], 2 * i - 1, 2 * j);
        }
      }
    }
  }
  E.clear();
  for (auto x : Eall) {
    if (spe[x.u] || spe[x.v]) {
      E.push_back(x);
    } 
  }
  prepare(E.size());
  while (augment()) {
    S--;
  }
  if (S) {
    cout << "NO\n";
    return;
  }
  UnionFound uf;
  uf.init(cnt);
  for (int i = 0; i < (signed) E.size(); i++) {
    if (in[i]) {
      uf.unit(E[i].u, E[i].v);
      Ga[E[i].rx][E[i].ry] = 'O';
    }
  }
  for (auto e : Eall) {
    int u = e.u, v = e.v;
    if (uf[u] ^ uf[v]) {
      uf.unit(u, v);
      Ga[e.rx][e.ry] = 'O';
    }
  }
  for (int i = 0; i < cnt; i++) {
    if (uf[i] ^ uf[0]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= 2 * R - 1; i++) {
    cout << (Ga[i] + 1) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}