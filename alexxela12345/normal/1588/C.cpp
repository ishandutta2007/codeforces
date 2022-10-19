#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
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

#define int long long
#define endl '\n'

int n;
vector<int> arr;
vector<int> arr2;
vector<int> arr0, arr1;
vector<int> tree0, tree1;

const int INF = 1e18;

void build0(int v, int l, int r) {
  if (l == r)
    return;
  if (l + 1 == r) {
    tree0[v] = arr0[l];
  } else {
    int m = (l + r) / 2;
    build0(2 * v + 1, l, m);
    build0(2 * v + 2, m, r);
    tree0[v] = min(tree0[2 * v + 1], tree0[2 * v + 2]);
  }
}

void build1(int v, int l, int r) {
  if (l == r)
    return;
  if (l + 1 == r) {
    tree1[v] = arr1[l];
  } else {
    int m = (l + r) / 2;
    build1(2 * v + 1, l, m);
    build1(2 * v + 2, m, r);
    tree1[v] = min(tree1[2 * v + 1], tree1[2 * v + 2]);
  }
}

int get0(int v, int l, int r, int ql, int qr) {
  if (l == r)
    return INF;
  if (l >= qr || ql >= r) {
    return INF;
  }
  if (ql <= l && r <= qr) {
    return tree0[v];
  }
  int m = (l + r) / 2;
  return min(get0(2 * v + 1, l, m, ql, qr), get0(2 * v + 2, m, r, ql, qr));
}

int get1(int v, int l, int r, int ql, int qr) {
  if (l == r)
    return INF;
  if (l >= qr || ql >= r) {
    return INF;
  }
  if (ql <= l && r <= qr) {
    return tree1[v];
  }
  int m = (l + r) / 2;
  return min(get1(2 * v + 1, l, m, ql, qr), get1(2 * v + 2, m, r, ql, qr));
}

int get0(int l, int r) {
  return get0(0, 0, (int) arr0.size(), l, r);
  r = min(r, (int) arr0.size());
  int mx = INF;
  for (int i = l; i < r; i++) {
    mx = min(mx, arr0[i]);
  }
  return mx;
}

int get1(int l, int r) {
  return get1(0, 0, (int) arr1.size(), l, r);
  r = min(r, (int) arr1.size());
  int mx = INF;
  for (int i = l; i < r; i++) {
    mx = min(mx, arr1[i]);
  }
  return mx;
}

int down0(int v, int l, int r, int i, int val) {
  if (r <= i) {
    return r;
  }
  if (i <= l && tree0[v] >= val) {
    return r;
  }
  if (l + 1 == r && tree0[v] < val) {
    return l;
  }
  int m = (l + r) / 2;
  int a = down0(2 * v + 1, l, m, i, val);
  if (a == m) {
    int b = down0(2 * v + 2, m, r, i, val);
    return b;
  }
  return a;
}

int down1(int v, int l, int r, int i, int val) {
  if (r <= i) {
    return r;
  }
  if (i <= l && tree1[v] >= val) {
    return r;
  }
  if (l + 1 == r && tree1[v] < val) {
    return l;
  }
  int m = (l + r) / 2;
  int a = down1(2 * v + 1, l, m, i, val);
  if (a == m) {
    int b = down1(2 * v + 2, m, r, i, val);
    return b;
  }
  return a;
}

int goRight(int i, int x) {
  int fst1 = (i + i % 2) / 2;
  int fst2 = (i + (1 - i % 2)) / 2;
  int A = -x;
  if (i % 2 != 0) {
    A = x;
  }
  int r1 = down0(0, 0, (int) arr0.size(), fst1, -A);
  int r2 = down1(0, 0, (int) arr1.size(), fst2, A);
  return min(r1 * 2, 2 * r2 + 1);
  int l = 0;
  int r = n + 2;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int fst = i;
    int lst = i + m;
    bool good = 1;
    if (get0((fst + fst % 2) / 2, (lst + lst % 2) / 2) + A < 0) {
      good = 0;
    } else if (get1((fst + (1 - fst % 2)) / 2, (lst + (1 - lst % 2)) / 2) - A < 0) {
      good = 0;
    }
    if (good) {
      l = m;
    } else {
      r = m;
    }
  }
  return i + l;
}

map<int, vector<int>> inds;

int count(int l, int r, int x) {
  return upper_bound(all(inds[x]), r) - lower_bound(all(inds[x]), l);
}

void solve() {
  cin >> n;
  vector<int> a(n);
  cin >> a;
  arr.resize(n + 1);
  arr2.resize(n + 1);
  for (int i = 0; i < n; i++) {
    arr[i + 1] = a[i] - arr[i];
  }
  arr0.clear();
  arr1.clear();
  for (int i = 0; i <= n; i += 2) {
    arr0.push_back(arr[i]);
  }
  for (int i = 1; i <= n; i += 2) {
    arr1.push_back(arr[i]);
  }
  tree0.resize(4 * arr0.size());
  tree1.resize(4 * arr1.size());
  build0(0, 0, (int) arr0.size());
  build1(0, 0, (int) arr1.size());
  inds.clear();
  for (int i = 0; i <= n; i++) {
    if (i % 2 == 0) {
      arr2[i] = arr[i];
    } else {
      arr2[i] = -arr[i];
    }
    inds[arr2[i]].push_back(i);
  }
  ll ans = 0;
  for (int l = 0; l < n; l++) {
    int r = goRight(l, arr[l]);
    int cnt = count(l + 1, r, arr2[l]);
    ans += cnt;
  }
  cout << ans << endl;
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