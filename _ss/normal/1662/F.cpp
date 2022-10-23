#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct MinTree {
  typedef pair<int, int> T;
  static constexpr T unit = {INT_MAX, -1};
  T f(T a, T b) { return min(a, b); }  // (any associative fn)
  vector<T> s;
  int n;
  MinTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) {  // query [b, e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

struct MaxTree {
  typedef pair<int, int> T;
  static constexpr T unit = {INT_MIN, -1};
  T f(T a, T b) { return max(a, b); }  // (any associative fn)
  vector<T> s;
  int n;
  MaxTree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
  void update(int pos, T val) {
    for (s[pos += n] = val; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) {  // query [b, e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int n, a, b, p[N], d[N];

void solve() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }

  queue<int> q;
  MaxTree max_tree(n + 1);
  MinTree min_tree(n + 1);
  for (int i = 1; i <= n; ++i) {
    d[i] = -1;
    max_tree.update(i, {i + p[i], i});
    min_tree.update(i, {i - p[i], i});
  }

  d[a] = 0;
  q.emplace(a);
  max_tree.update(a, {INT_MIN, -1});
  min_tree.update(a, {INT_MAX, -1});

  while (!q.empty()) {
    int i = q.front();
    q.pop();
    if (i == b) {
      cout << d[i] << '\n';
      return;
    }

    // left: j >= i - p[i] and j + p[j] >= i
    if (i != 1) {
      int l = max(1, i - p[i]), r = i - 1;
      while (true) {
        auto cand = max_tree.query(l, r + 1);
        if (cand.first < i) break;
        int j = cand.second;
        d[j] = d[i] + 1;
        q.emplace(j);
        max_tree.update(j, {INT_MIN, -1});
        min_tree.update(j, {INT_MAX, -1});
      }
    }

    // right: j <= i + p[i] and j - p[j] <= i
    if (i != n) {
      int l = i + 1, r = min(n, i + p[i]);
      while (true) {
        auto cand = min_tree.query(l, r + 1);
        if (cand.first > i) break;
        int j = cand.second;
        d[j] = d[i] + 1;
        q.emplace(j);
        max_tree.update(j, {INT_MIN, -1});
        min_tree.update(j, {INT_MAX, -1});
      }
    }
  }
  assert(false);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}