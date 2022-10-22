#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct Solution {
  int x = -1, y = -1;
  vector<pair<int, int>> s;

  bool can() {
    return !s.empty();
  }
};

Solution solve(vector<int> a, int k, int delta) {
  auto sorted = a;
  sort(all(sorted));

  int max_can = 0;
  Solution s;

  int r = 0;
  for (int l = 0; l < sorted.size(); ++l) {
    while (r + 1 < sorted.size() && sorted[r + 1] - sorted[l] < delta) {
      ++r;
    }

    if (r - l + 1 > max_can) {
      max_can = r - l + 1;
      s.x = sorted[l];
      s.y = sorted[r];
    }
  }

  int sum = 0;

  int l = 0;
  for (int i = 0; i < a.size(); ++i) {
    int x = a[i];

    int sign = (x >= s.x && x <= s.y) ? 1 : -1;
    sum += sign;
    if (sum > 0) {
      s.s.emplace_back(l, i);
      sum = 0;
      l = i + 1;
    }
  }

  /*for (auto it : s.s) {
    cout << "preseg " << it.first + 1 << " " << it.second + 1 << endl;
  }
  cout << "final sum " << sum << endl;*/

  while (sum <= 0 && !s.s.empty()) {
    auto p = s.s.back();
    s.s.pop_back();
    l = p.first;
    ++sum;
  }

  //cout << "adjusted " << sum << " " << l + 1 << " segs " << s.s.size() << endl;

  if (sum > 0) {
    s.s.emplace_back(l, a.size() - 1);
  } else {
    return Solution{};
  }

  if (s.s.size() < k) {
    return Solution{};
  }

  while (s.s.size() > k) {
    s.s.pop_back();
  }
  s.s.back().second = a.size() - 1;
  assert(s.s.size() == k);

  for (auto& it : s.s) {
    int sum = 0;
    for (int i = it.first; i <= it.second; ++i) {
      int x = a[i];
      sum += (x >= s.x && x <= s.y) ? 1 : -1;
    }
    assert(sum > 0);
  }

  /*for (auto it : s.s) {
    cout << "preseg " << it.first + 1 << " " << it.second + 1 << endl;
  }*/

  return s;
}

const int INF = 1e9;

struct segtree {
  vector<int> tree;

  segtree() {}
  segtree(int n): tree(n * 4 + 100, INF) {}

  int query(int t, int l, int r, int x, int y) {
    if (x > r || y < l) {
      return INF;
    }

    if (l >= x && r <= y) {
      return tree[t];
    }

    int m = (l + r) / 2;
    return min(query(t * 2 + 1, l, m, x, y), query(t * 2 + 2, m + 1, r, x, y));
  }

  void change(int t, int l, int r, int index, int value) {
    if (l == r) {
      tree[t] = min(tree[t], value);
      return;
    }

    int m = (l + r) / 2;
    if (index <= m) {
      change(t * 2 + 1, l, m, index, value);
    } else {
      change(t * 2 + 2, m + 1, r, index, value);
    }
    tree[t] = min(tree[t * 2 + 1], tree[t * 2 + 2]);
  }
};

int N;
segtree S;

int subsolve(vector<pair<int, int>> sub) {
  int n = sub.size();
  vector<int> dp(n);

  int L = sub[0].first;
  int R = 0;
  for (auto& it : sub) {
    R = max(R, it.second);
  }

  int ans = INF;

  for (int i = 0; i < n; ++i) {
    int mdp = INF;

    if (sub[i].first == sub[0].first) {
      mdp = 1;
    } else {
      mdp = S.query(0, 0, N - 1, sub[i].first, R) + 1;
    //cout << "query " << sub[i].first << " " << mdp << endl;

#if 0
      for (int j = 0; j < i; ++j) {
        if (sub[j].second >= sub[i].first) {
          if (mdp > dp[j]) {
            mdp = dp[j] + 1;
          }
        }
      }
#endif
    }

    dp[i] = mdp;
    //cout << "change " << sub[i].second << " " << dp[i] << endl;
    S.change(0, 0, N - 1, sub[i].second, dp[i]);

    if (sub[i].second == R) {
      ans = min(ans, mdp);
    }
  }

  assert(ans != INF);

  int k = ans;
  return (R - L + 1) - (k + 1);
}

void solve(bool read = true) {
  int n, k;
  cin >> n;

  S = segtree(n);
  N = n;

  map<int, int> first, last;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (!first.count(a[i])) {
      first[a[i]] = i;
    }
    last[a[i]] = i;
  }

  auto s = a;
  sort(all(s));
  s.erase(unique(all(s)), s.end());

  vector<pair<int, int>> segs;

  for (auto it : s) {
    int l = first[it];
    int r = last[it];

    if (r > l) {
      segs.emplace_back(l, r);
    }
  }

  sort(all(segs));

  int ans = 0;
  for (int l = 0; l < segs.size();) {
    int maxr = segs[l].second;
    int r = l;

    while (r + 1 < segs.size() && segs[r + 1].first <= maxr) {
      ++r;
      maxr = max(maxr, segs[r].second);
    }

    vector<pair<int, int>> sub(segs.begin() + l, segs.begin() + r + 1);
    ans += subsolve(sub);

    l = r + 1;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}