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
  int n;
  cin >> n;
  vector<int> arr(n);
  cin >> arr;
  int sum = 0;
  for (int el : arr)
    sum += el;
  int cur = 2;
  bool bad = false;
  while (cur * cur <= sum) {
    if (sum % cur == 0) {
      bad = 1;
      break;
    }
    cur++;
  }
  if (bad) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << i + 1 << " ";
    }
    cout << endl;
  } else {
    cout << n - 1 << endl;
    bool was = false;
    for (int i = 0; i < n; i++) {
      if (arr[i] % 2 == 1 && !was) {
        was = 1;
      } else {
        cout << i + 1 << " ";
      }
    }
    cout << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t; // Comment this line if there is no multitest
  while (t--) {
    solve();
  }
}