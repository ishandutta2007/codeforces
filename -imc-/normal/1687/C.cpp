#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

struct segtree {
  int n;
  vector<pair<int, bool>> assigned;

  segtree(int n): n(n), assigned(4 * n + 1) {}

  void push(int t) {
    if (assigned[t].second) {
      assigned[t * 2 + 1] = assigned[t];
      assigned[t * 2 + 2] = assigned[t];
      assigned[t].second = false;
    }
  }

  int query(int t, int l, int r, int index) {
    if (l == r) {
      return assigned[t].first;
    }

    push(t);
    int m = (l + r) / 2;
    if (index <= m) {
      return query(t * 2 + 1, l, m, index);
    } else {
      return query(t * 2 + 2, m + 1, r, index);
    }
  }

  void assign(int t, int l, int r, int x, int y, int v) {
    if (x > r || y < l) return;

    if (l >= x && r <= y) {
      assigned[t].second = true;
      assigned[t].first = v;
      return;
    }

    push(t);

    int m = (l + r) / 2;
    assign(t * 2 + 1, l, m, x, y, v);
    assign(t * 2 + 2, m + 1, r, x, y, v);
  }

  int query(int index) {
    return query(0, 0, n - 1, index);
  }

  void assign(int l, int r, int v) {
    assign(0, 0, n - 1, l, r, v);
  }
};

void solve(bool read) {
  int n, m;
  if (read) {
    cin >> n >> m;
  } else {
    n = 2e5;
    m = 2e5;
  }

  vector<li> a(n), b(n);
  if (read) {
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
  } else {
    for (int i = 0; i < n; ++i) {
      //a[i] = i % 2 == 0 ? -1 : 1;
      a[i] = (rand() % 3) - 1;
    }
    int s = accumulate(a.begin(), a.begin() + n - 1, 0);
    a[n - 1] = -s;
  }

  vector<li> p;
  li sum = 0;
  p.push_back(0);
  for (int i = 0; i < n; ++i) {
    sum += (a[i] - b[i]);
    p.push_back(sum);
  }

  map<pair<int, int>, int> by_l;
  map<pair<int, int>, int> by_r;

  deque<int> q;

  vector<bool> used(m);
  vector<pair<int, int>> s(m);

  segtree st(n + 1);
  for (int i = 0; i <= n; ++i) {
    st.assign(i, i, p[i]);
  }

  for (int i = 0; i < m; ++i) {
    int l, r;
    if (read) {
      cin >> l >> r;
    } else {
      l = rand() % n + 1;
      r = rand() % n + 1;

      if (r < l) swap(l, r);
    }
    --l;
    s[i] = {l, r};

    by_l[make_pair(l, i)] = r;
    by_r[make_pair(r, i)] = l;

    if (p[l] == 0 && p[r] == 0) {
      //cout << "start: " << i << "\n";
      q.push_back(i);
      used[i] = true;
    }
  }

  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    //cout << "pull " << v << "\n";

    st.assign(s[v].first, s[v].second, 0);

    auto iter_map = [&](int l, int r, auto& m) {
      auto i1 = m.lower_bound(make_pair(l, 0));
      auto i2 = m.lower_bound(make_pair(r + 1, 0));

      for (auto it = i1; it != i2;) {
        int index = it->first.second;
        //cout << "process " << index << "\n";

        if (!used[index]) {
          if (st.query(it->second) == 0) {
            used[index] = true;
            q.push_back(index);
          }
        }

        it = m.erase(it);
      }
    };

    iter_map(s[v].first, s[v].second, by_l);
    iter_map(s[v].first, s[v].second, by_r);
  }

  bool fail = false;
  for (int i = 0; i <= n; ++i) {
    if (st.query(i) != 0) {
      fail = true;
      break;
    }
  }

  cout << (fail ? "NO" : "YES") << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

#if 0
  solve(false);

  while (true) {
    int t0 = clock();
    solve(false);
    int t1 = clock();
    cout << (t1 - t0) / (double)CLOCKS_PER_SEC << endl;
  }
#endif

  return 0;
}