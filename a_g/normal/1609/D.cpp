#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxtreesize = 1;

vector<int> counts;

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    vector<int> sizes; //subtree size, maintained at root
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      ranks.resize(n, 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      int size = sizes[a] + sizes[b];
      if (ranks[a] > ranks[b]) swap(a, b);
      // b has higher rank
      parents[a] = b;
      counts[sizes[a]]--;
      counts[sizes[b]]--;
      sizes[b] = size;
      counts[sizes[b]]++;
      maxtreesize = max(maxtreesize, sizes[b]);
      if (ranks[a] == ranks[b]) ranks[b]++;
      return 1;
    }
};
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  dsu A(n);
  counts.resize(n+1);
  counts[1] = n;
  int components = n;
  for (int i = 1; i <= d; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (A.join(x, y)) components--;
    int groups = i+components-n+1;
    int ans = 0;
    for (int k = n; k >= 1; k--) {
      if (groups == 0) break;
      int take = min(groups, counts[k]);
      ans += take*k;
      groups -= take;
    }
    cout << ans - 1 << '\n';
  }
}