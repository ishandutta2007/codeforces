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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> bad(m);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j + 1 < m; j++) {
      if (arr[i][j] == arr[i - 1][j + 1] && arr[i][j] == 'X') {
        bad[j] = 1;
      }
    }
  }
  vector<int> pref(m + 1);
  for (int j = 0; j < m; j++) {
    pref[j + 1] = pref[j] + bad[j];
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    if (pref[r] - pref[l]) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
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