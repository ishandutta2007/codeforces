#include <bits/stdc++.h>
using namespace std;

const int K = 18;
const int N = 1<<K;
int a[N];

vector<int> best[N];

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


bool compare_by_a(int x, int y) {
  return a[x] > a[y];
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dsu D(n+1);
  long long ans = -accumulate(a+1, a+n+1, 0LL);

  auto process = [&] (vector<int>& b, bool s) {
    if (s) sort(b.begin(), b.end(), compare_by_a);
    for (int i = 0; i < (int)b.size(); i++) {
      if (i >= 2) {
        b.resize(2);
        return;
      }
      for (int j = 0; j < i; j++) {
        if (D.root(b[i]) == D.root(b[j])) {
          b.erase(b.begin()+i);
          i--;
          break;
        }
      }
    }
    b.resize(min<int>(2, b.size()));
  };

  auto merge_in = [&] (int x, int y) {
    best[y].insert(best[y].end(), best[x].begin(), best[x].end());
    process(best[y], 1);
  };

  int components = n+1;
  while (components > 1) {
    for (int i = 0; i <= n; i++) {
      best[a[i]].push_back(i);
    }
    for (int i = 0; i < N; i++) {
      process(best[i], 0);
    }
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < N; j++) {
        if (!((j>>i)&1)) {
          merge_in(j, j+(1<<i));
        }
      }
    }

    for (int i = 0; i < N; i++) {
      assert(best[i].size() <= 2);
      if (best[i].size() == 2) {
        assert(D.root(best[i][0]) != D.root(best[i][1]));
      }
    }

    vector<pair<int, int>> best_by_root(n+1, {-1, -1});
    for (int i = 0; i <= n; i++) {
      int r = D.root(i);
      int u = -1;
      for (int k: best[(N-1)^a[i]]) {
        if (D.root(k) != r) {
          u = k;
          break;
        }
      }
      if (u == -1) continue;
      if (best_by_root[r].first == -1 || a[best_by_root[r].first]+a[best_by_root[r].second] < a[i]+a[u]) {
        best_by_root[r] = {i, u};
      }
    }

    for (int i = 0; i <= n; i++) {
      if (D.root(i) == i) {
        assert(best_by_root[i].first != -1);
        if (D.join(best_by_root[i].first, best_by_root[i].second)) {
          ans += a[best_by_root[i].first]+a[best_by_root[i].second];
          components--;
        }
      }
    }

    for (int i = 0; i < N; i++) {
      best[i].clear();
    }
  }

  cout << ans << '\n';
}