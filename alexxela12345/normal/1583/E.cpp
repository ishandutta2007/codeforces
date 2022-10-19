#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *s) { cerr << '"' << s << '"'; }
void __print(const string &s) { cerr << '"' << s << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T1, typename T2> void __print(const pair<T1, T2> &pp) {
  cerr << '(';
  __print(pp.first);
  cerr << ", ";
  __print(pp.second);
  cerr << ')';
}
template <typename T> void __print(const T &x) {
  cerr << '{';
  bool b = false;
  for (auto &el : x) {
    if (b) {
      cerr << ", ";
    }
    __print(el);
    b = true;
  }
  cerr << '}';
}
void _print() { cerr << " ]\n"; }
template <typename T, typename... Ts> void _print(T t, Ts... ts) {
  __print(t);
  if (sizeof...(ts)) {
    cerr << ", ";
  }
  _print(ts...);
}
#ifdef LOCAL
#define debug(x...)                \
  cerr << "[ " << #x << " ] = [ "; \
  _print(x)
#else
#define debug(x...)
#endif

template<typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  return in >> p.first >> p.second;
}

template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &el : v) {
    in >> el;
  }
  return in;
}

// #define int long long
#define endl '\n'

vector<vector<int>> g;
vector<int> pa;
vector<int> used;
vector<int> d;

void dfs(int v) {
  used[v] = 1;
  for (int u : g[v]) {
    if (!used[u]) {
      pa[u] = v;
      d[u] = d[v] + 1;
      dfs(u);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  pa.resize(n, -1);
  used.resize(n);
  d.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  int q;
  cin >> q;
  vector<pair<int, int>> qq(q);
  cin >> qq;
  vector<int> even(n);
  for (auto &pp : qq) {
    pp.first--;
    pp.second--;
    even[pp.first] ^= 1;
    even[pp.second] ^= 1;
  }
  if (*max_element(all(even))) {
    cout << "NO" << endl;
    int sum = 0;
    for (int el : even)
      sum += el;
    cout << sum / 2 << endl;
  } else {
    cout << "YES" << endl;
    for (auto pp : qq) {
      int a = pp.first;
      int b = pp.second;
      vector<int> p1, p2;
      while (d[a] > d[b]) {
        p1.push_back(a);
        a = pa[a];
      }
      while (d[a] < d[b]) {
        p2.push_back(b);
        b = pa[b];
      }
      while (a != b) {
        p1.push_back(a);
        a = pa[a];
        p2.push_back(b);
        b = pa[b];
      }
      p1.push_back(a);
      reverse(all(p2));
      for (int el : p2)
        p1.push_back(el);
      cout << sz(p1) << endl;
      for (int el : p1)
        cout << el + 1 << " ";
      cout << endl;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}