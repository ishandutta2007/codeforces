#include <bits/stdc++.h>
using namespace std;

const int K = 30;

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

bool complete(vector<int>& ans) {
  dsu D(K);
  for (int& x: ans) {
    for (int i = 0; i < K; i++) {
      if ((x>>i)&1) {
        for (int j = i+1; j < K; j++) {
          if ((x>>j)&1) {
            D.join(i, j);
          }
        }
      }
    }
  }

  int z = D.root(__builtin_ctz(ans[0]));
  for (int& x: ans) {
    for (int i = 0; i < K; i++) {
      if ((x>>i)&1) {
        if (D.root(i) != z) {
          return 0;
        }
      }
    }
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;

    vector<int> ans = a;
    int m = 0;
    for (int& x: ans) {
      if (!x) x = 1;
      m = max(m, __builtin_ctz(x));
    }

    vector<int> indices;
    for (int i = 0; i < n; i++) {
      if (__builtin_ctz(ans[i]) == m) {
        indices.push_back(i);
      }
    }

    bool done = 0;
    auto finish = [&] () {
      done = 1;
      int d = 0;
      for (int i = 0; i < n; i++) {
        d += abs(ans[i]-a[i]);
      }
      cout << d << '\n';
      for (int x: ans) {
        cout << x << ' ';
      }
      cout << '\n';
    };

    if (complete(ans)) {
      finish();
      continue;
    }

    for (int i = 0; i < n && !done; i++) {
      ans[i]++;
      if (complete(ans)) {
        finish();
        break;
      }
      ans[i]--;
      if (ans[i] > 1) {
        ans[i]--;
        if (complete(ans)) {
          finish();
          break;
        }
        ans[i]++;
      }
    }

    if (done) continue;
    assert(indices.size() >= 2);
    ans[indices[0]]++;
    ans[indices[1]]--;
    finish();
  }
}