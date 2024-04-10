#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 3e5+5;
int freqs[N], nxt[N], dp[N];

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    vector<int> starts;
    vector<int> ends;
    vector<bool> valid;
    dsu (int n) {
      parents.resize(n);
      starts.resize(n);
      ends.resize(n);
      valid.resize(n, 1);
      sizes.resize(n, 1);
      iota(parents.begin(), parents.end(), 0);
      iota(starts.begin(), starts.end(), 0);
      iota(ends.begin(), ends.end(), 0);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) {
        valid[a] = 0;
        return 0;
      }
      int start = starts[a];
      int end = ends[b];
      bool good = valid[a] && valid[b] && ends[a] == u && starts[b] == v;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      starts[b] = start;
      ends[b] = end;
      sizes[b] += sizes[a];
      valid[b] = good;
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  dsu D(k+1);

  for (int i = 0; i < n; i++) {
    int c, a;
    cin >> c >> a;
    int prv = a;
    for (int j = 1; j < c; j++) {
      cin >> a;
      if (nxt[prv] != a) {
        D.join(prv, a);
        if (nxt[prv]) {
          D.valid[a] = 0;
        }
        nxt[prv] = a;
      }
      prv = a;
    }
  }

  for (int i = 1; i <= k; i++) {
    if (D.root(i) == i && D.valid[i]) {
      freqs[D.sizes[i]]++;
    }
  }
  vector<pair<int, int>> terms;
  for (int i = 1; i <= k; i++) {
    if (freqs[i]) {
      terms.push_back(make_pair(i, freqs[i]));
    }
  }

  dp[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (pair<int, int>& p: terms) {
      if (p.first > i) break;
      dp[i] = (dp[i] + 1LL * dp[i-p.first] * p.second) % MOD;
    }
  }
  cout << dp[m] << '\n';
}