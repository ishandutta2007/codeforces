#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1505;
int a[N][N];

vector<int> conv(vector<int>& a, vector<int>& b) {
  int n = a.size();
  int m = b.size();
  vector<int> c(n+m-1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i+j] = (c[i+j]+1LL*a[i]*b[j]) % MOD;
    }
  }
  return c;
}

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    vector<vector<int>> dp;
    vector<int> edges;
    int n;
    dsu (int _n): n(_n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
      edges.resize(n);
      dp.resize(n, vector<int>(2));
      for (int i = 0; i < n; i++) {
        dp[i][1] = 1;
      }
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) {
        edges[b]++;
        if (edges[b] == sizes[b]*(sizes[b]-1)/2) {
          dp[b][1]++;
        }
        return 0;
      }
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      edges[b] += edges[a]+1;
      dp[b] = conv(dp[b], dp[a]);
      if (edges[b] == sizes[b]*(sizes[b]-1)/2) {
        dp[b][1]++;
      }
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  vector<pair<int, int>> edges;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      edges.emplace_back(i, j);
    }
  }

  sort(edges.begin(), edges.end(), [&] (pair<int, int>& p, pair<int, int>& q) {
      return a[p.first][p.second] < a[q.first][q.second];
      });

  dsu D(n);
  for (pair<int, int>& p: edges) {
    D.join(p.first, p.second);
  }
  
  for (int i = 1; i <= n; i++) {
    cout << D.dp[D.root(0)][i] << ' ';
  }
  cout << '\n';
}