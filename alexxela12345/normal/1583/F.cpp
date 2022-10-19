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

void solve() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  g.resize(n, vector<int> (n, -1));
  vector<vector<int>> gr;
  for (int i = 0; i < n; i++) {
    gr.push_back({i});
  }
  int cur_color = 1;
  while (sz(gr) > 1) {
    vector<vector<int>> gr2;
    for (int i = 0; i < sz(gr); i += k) {
      gr2.push_back({});
      for (int j = i; j < i + k && j < sz(gr); j++) {
        for (int el : gr[j]) {
          gr2.back().push_back(el);
        }
        for (int k = i; k < j; k++) {
          for (int el1 : gr[j]) {
            for (int el2 : gr[k]) {
              g[el2][el1] = cur_color;
            }
          }
        }
      }
    }
    gr = gr2;
    cur_color++;
  }
  cout << cur_color - 1 << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << g[i][j] << " ";
    }
  }
  cout << endl;
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