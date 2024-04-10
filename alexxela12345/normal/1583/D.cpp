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

mt19937 rd;
random_device  rddev;

int randint(int l, int r) {
  int a = (int) (rd() % ((unsigned long long) (r - l + 1)));
  return a + l;
}

int n;
#ifdef LOCAL

vector<int> p;

void gen() {
  auto seed = rddev();
  cout << seed << endl;
  rd = mt19937(seed);
  n = randint(2, 10);
  p.clear();
  p.resize(n);
  iota(all(p), 1);
  shuffle(all(p), rd);
  cout << n << endl;
  for (int el : p) {
    cout << el << " ";
  }
  cout << endl;
}

int query(vector<int> arr) {
  for (int i = 0; i < n; i++) {
    arr[i] += p[i];
  }
  int ans = -1;
  set<int> was;
  for (int i = n - 1; i >= 0; i--) {
    if (was.count(arr[i])) {
      ans = i;
    }
    was.insert(arr[i]);
  }
  return ans;
}
      
#else
int query(vector<int> arr) {
  cout << "?";
  for (int el : arr) {
    cout << " " << el;
  }
  cout << endl;
  int x;
  cin >> x;
  return x - 1;
}
#endif

void solve() {
#ifdef LOCAL
  gen();
#else
  cin >> n;
#endif
  vector<int> lt(n, -1), gt(n, -1);
  for (int i = 0; i < n; i++) {
    vector<int> arr(n, 2);
    arr[i] = 1;
    int ind = query(arr);
    if (ind != -1 && ind != i) {
      lt[i] = ind;
      gt[ind] = i;
    }
    arr[i] = 3;
    for (int &el : arr)
      el--;
    ind = query(arr);
    if (ind != -1 && ind != i) {
      lt[ind] = i;
      gt[i] = ind;
    }
  }
  int start = 0;
  while (lt[start] != -1)
    start++;
  vector<int> ans(n, -1);
  cout << "!";
  int cur = 1;
  while (start != -1) {
    ans[start] = cur++;
    start = gt[start];
  }
  for (int el : ans)
    cout << " " << el;
  cout << endl;
#ifdef LOCAL
  assert(ans == p);
#endif
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