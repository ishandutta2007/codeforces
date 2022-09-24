#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

struct st1 {
  int Q;
  vector<set<pii>> tree;

  st1(int n) {
    Q = 1;
    while (Q < n) {
      Q *= 2;
    }
    tree.resize(2 * Q);
  }

  void update(int i, pii x) {
    for (i += Q; i; i /= 2) {
      tree[i].insert(x);
    }
  }

  void acc(set<pii> &s, set<pii> &t, int f) {
    while (!t.empty() && t.rbegin()->first >= f) {
      s.insert(*t.rbegin());
      t.erase(--t.end());
    }
  }

  set<pii> query(int l, int r, int f) {
    set<pii> res;
    for (l += Q, r += Q + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        acc(res, tree[l++], f);
      }
      if (r & 1) {
        acc(res, tree[--r], f);
      }
    }
    return res;
  }

  void erase(int i, pii x) {
    for (i += Q; i; i /= 2) {
      tree[i].erase(x);
    }
  }
};

struct st2 {
  int Q;
  vector<set<pii>> tree;

  st2(int n) {
    Q = 1;
    while (Q < n) {
      Q *= 2;
    }
    tree.resize(2 * Q);
  }

  void update(int l, int r, pii x) {
    for (l += Q, r += Q + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        tree[l++].insert(x);
      }
      if (r & 1) {
        tree[--r].insert(x);
      }
    }
  }

  void acc(set<pii> &s, set<pii> &t, int f) {
    while (!t.empty() && t.begin()->first <= f) {
      s.insert(*t.begin());
      t.erase(t.begin());
    }
  }

  set<pii> query(int i, int f) {
    set<pii> res;
    for (i += Q; i; i /= 2) {
      acc(res, tree[i], f);
    }
    return res;
  }

  void erase(int l, int r, pii x) {
    for (l += Q, r += Q + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) {
        tree[l++].erase(x);
      }
      if (r & 1) {
        tree[--r].erase(x);
      }
    }
  }
};

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  --a;
  --b;
  st1 s1(n);
  st2 s2(n);
  for (int i = 0; i < n; i++) {
    s1.update(i, pii(p[i], i));
    s2.update(max(0, i - p[i]), min(n - 1, i + p[i]), pii(p[i], i));
  }

  queue<int> q;
  q.push(a);
  vector<int> d(n);
  auto rem = [&](int i) {
    s1.erase(i, pii(p[i], i));
    s2.erase(max(0, i - p[i]), min(n - 1, i + p[i]), pii(p[i], i));
  };
  rem(a);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    auto goDown = s1.query(max(0, i - p[i]), min(n - 1, i + p[i]), p[i]);
    for (auto[pj, j]: goDown) {
      rem(j);
      d[j] = d[i] + 1;
      q.push(j);
    }
    auto goUp = s2.query(i, p[i]);
    for (auto[pj, j]: goUp) {
      rem(j);
      d[j] = d[i] + 1;
      q.push(j);
    }
  }

  cout << d[b] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int test;
  cin >> test;
  while (test--) {
    solve();
  }

  return 0;
}