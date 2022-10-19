#include <bits/stdc++.h>
using namespace std;

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    vector<int> least_enemy;
    vector<int> leftpts;
    vector<int> rightpts;
    dsu (int n) {
      parents.resize(n);
      leftpts.resize(n);
      rightpts.resize(n);
      iota(parents.begin(), parents.end(), 0);
      iota(leftpts.begin(), leftpts.end(), 0);
      iota(rightpts.begin(), rightpts.end(), 0);
      sizes.resize(n, 1);
      least_enemy.resize(n, n-1);
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
      leftpts[b] = min(leftpts[b], leftpts[a]);
      rightpts[b] = max(rightpts[b], rightpts[a]);
      least_enemy[b] = min(least_enemy[b], least_enemy[a]);
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  dsu D(n+4);
  while (q--) {
    int t;
    cin >> t;
    if (t) {
      int j;
      cin >> j;
      if (D.root(j-1) == D.root(j)) {
        cout << "NO\n";
      }
      else if (D.leftpts[D.root(D.least_enemy[D.root(j-1)])] == j) {
        cout << "YES\n";
      }
      else {
        cout << "N/A\n";
      }
    }
    else {
      int l, r, x;
      cin >> l >> r >> x;
      if (x) {
        D.least_enemy[D.root(l-1)] = min(D.least_enemy[D.root(l-1)], r);
      }
      else {
        int u = D.rightpts[D.root(l-1)];
        int v = D.leftpts[D.root(r)];
        for (int i = u; i < v; i = D.rightpts[D.root(i)]) {
          D.join(i, i+1);
          i++;
        }
      }
    }
  }
}