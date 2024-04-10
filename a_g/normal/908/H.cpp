#include <bits/stdc++.h>
using namespace std;

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

// https://codeforces.com/blog/entry/57496
int ChromaticNumber(const vector<int> &g) {
        int n = g.size();
        if (n == 0) return 0;
        //randomly choose a large prime
        const int modulo = 1077563119;
        int all = 1 << n;
        vector<int> ind(all), s(all);
        for (int i = 0; i < all; i ++) s[i] = ((n - __builtin_popcount(i)) & 1 ? -1 : 1);
        ind[0] = 1;
        for (int i = 1; i < all; i ++) {
                int ctz = __builtin_ctz(i);
                ind[i] = ind[i - (1 << ctz)] + ind[(i - (1 << ctz)) & ~g[ctz]];
                if (ind[i] >= modulo) ind[i] -= modulo;
        }
        //compute the chromatic number (= \sum (-1)^{n - |i|} * ind(i)^k)
        for (int k = 1; k < n; k ++) {
                long long sum = 0;
                for (int i = 0; i < all; i ++) {
                        long long cur = ((s[i] * (long long) ind[i]) % modulo);
                        s[i] = cur;
                        sum += cur;
                }
                if (sum % modulo != 0) return k;
        }
        return n;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (string& row: a) cin >> row;

  dsu D(n);
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (a[i][j] == 'A') {
        D.join(i, j);
      }
    }
  }

  vector<int> to_vtx(n, -1);
  int vtx = 0;
  for (int i = 0; i < n; i++) {
    if (D.root(i) == i && D.sizes[i] > 1) {
      to_vtx[i] = vtx++;
    }
  }
  vector<int> G(vtx);

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (a[i][j] == 'X') {
        int u = D.root(i);
        int v = D.root(j);
        if (u == v) {
          cout << "-1\n";
          return 0;
        }
        if (D.sizes[u] == 1 || D.sizes[v] == 1) continue;
        int tu = to_vtx[u];
        int tv = to_vtx[v];
        G[tu] |= 1<<tv;
        G[tv] |= 1<<tu;
      }
    }
  }
  cout << n-1+ChromaticNumber(G) << '\n';

}