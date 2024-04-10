#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

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

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int r, c;
  cin >> r >> c;
  vector<string> grid(r);
  vector<int> rs(r), cs(c);
  vector<int> rq(r), cq(c);
  for (string& row: grid) cin >> row;

  int totalfree = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == '1') {
        rs[i] ^= 1;
        cs[j] ^= 1;
      }
      else if (grid[i][j] == '?') {
        rq[i]++;
        cq[j]++;
        totalfree++;
      }
    }
  }

  if (r % 2 == 0 && c % 2 == 0) {
    cout << expmod(2, totalfree, MOD) << '\n';
    return 0;
  }

  if (r % 2 == 0 && c % 2 == 1) {
    vector<string> transpose(c, string(r, ' '));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        transpose[j][i] = grid[i][j];
      }
    }
    grid = transpose;
    swap(r, c);
    swap(rq, cq);
    swap(rs, cs);
  }

  if (c % 2 == 0 && r % 2 == 1) {
    int ans = 0;
    for (int target = 0; target < 2; target++) {
      int subans = 1;
      for (int j = 0; j < c; j++) {
        int ways = (cq[j] ? expmod(2, cq[j]-1, MOD) : (cs[j] == target));
        subans = (1LL * ways * subans) % MOD;
      }
      ans = (ans+subans) % MOD;
    }
    cout << ans << '\n';
    return 0;
  }

  assert(r % 2 == 1 && c % 2 == 1);
  
  dsu D(r+c);
  // rows: 0, 1, ..., r-1
  // cols: r, r+1, ..., r+c-1
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == '?') {
        D.join(i, r+j);
      }
    }
  }

  vector<int> edges(r+c), sums(r+c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == '?') {
        edges[D.root(i)]++;
      }
      else if (grid[i][j] == '1') {
        sums[D.root(i)] ^= 1;
        sums[D.root(r+j)] ^= 1;
      }
    }
  }

  int ans = 0;
  for (int target = 0; target < 2; target++) {
    int subans = 1;
    for (int i = 0; i < r+c; i++) {
      if (D.root(i) == i) {
        int ways = (sums[i] != (target&D.sizes[i]&1) ?  0 : expmod(2, edges[i]+1-D.sizes[i], MOD));
        subans = (1LL * ways * subans) % MOD;
      }
    }
    ans = (ans+subans) % MOD;
  }
  cout << ans << '\n';
}