#include <bits/stdc++.h>
using namespace std;

// source: https://codeforces.com/contest/1718/submission/168572736
const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> p(n), a(n);
    for (int& x: p) cin >> x;
    int k = 0;
    for (int& x: a) {
      cin >> x;
      if (!x) k++;
    }

    // children in the Cartesian tree
    vector<int> lc(n, -1), rc(n, -1);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      while (stk.size() && p[stk.top()] < p[i]) {
        rc[stk.top()] = lc[i];
        lc[i] = stk.top();
        stk.pop();
      }
      stk.push(i);
    }
    while (stk.size() > 1) {
      int x = stk.top();
      stk.pop();
      if (stk.size()) {
        rc[stk.top()] = x;
      }
    }

    // lower, upper bounds on a[i]
    vector<int> l(n, -1), r(n, 1e9);
    vector<pair<int, int>> ranges;
    function<void(int)> dfs = [&] (int v) {
      if (a[v]) l[v] = r[v] = a[v];
      for (int u: {lc[v], rc[v]}) {
        if (u == -1) continue;
        r[u] = min(r[u], r[v]);
        dfs(u);
        l[v] = max(l[v], l[u]);
      }
      if (!a[v]) ranges.emplace_back(l[v], r[v]);
    };
    dfs(stk.top());
    bool fail = 0;
    for (int i = 0; i < n; i++) {
      if (l[i] > r[i]) fail = 1;
    }

    // a set of numbers is good if we can match them with the intervals
    // greedy strategy

    set<int> _s;
    // lower, upper bounds on d
    int L = -1, R = INF;
    for (int i = 0; i < k-1; i++) {
      int x;
      cin >> x;
      _s.insert(x);
    }

    sort(ranges.begin(), ranges.end(), [&] (auto& x, auto& y) {return x.second < y.second;});
    {
      set<int> s = _s;
      for (pair<int, int>& p: ranges) {
        auto it = s.lower_bound(p.first);
        if (it == s.end() || *it > p.second) {
          if (R == INF) R = p.second;
          else fail = 1;
        }
        else {
          s.erase(it);
        }
      }
    }

    sort(ranges.begin(), ranges.end(), [&] (auto& x, auto& y) {return x.first > y.first;});
    {
      set<int, greater<int>> s;
      for (int x: _s) s.insert(x);
      for (pair<int, int>& p: ranges) {
        auto it = s.lower_bound(p.second);
        if (it == s.end() || *it < p.first) {
          if (L == -1) L = p.first;
          else fail = 1;
        }
        else {
          s.erase(it);
        }
      }
    }

    while (q--) {
      int d;
      cin >> d;
      cout << (!fail && L <= d && d <= R ? "YES" : "NO") << '\n';
    }
  }
}