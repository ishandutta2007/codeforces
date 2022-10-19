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

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> indices(n);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      a--;
      indices[a].push_back(i);
    }

    int oddval = -1;
    bool fail = 0;
    for (int i = 0; i < n; i++) {
      if (indices[i].size() % 2 == 1) {
        if (oddval != -1) fail = 1;
        if (indices[i].size() == 1 && indices[i][0] == (n-1)/2) fail = 1;
        oddval = i;
      }
    }

    if (fail) {
      cout << "NO\n";
      continue;
    }
    
    cout << "YES\n";
    vector<int> p(n);
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (i == oddval) {
        for (int j = 0; j < (int)indices[i].size()-1; j++) {
          if (indices[i][j] == (n-1)/2) {
            swap(indices[i][j], indices[i].back());
            break;
          }
        }
        p[(n-1)/2] = indices[i][0];
        for (int j = 1; j < (int)indices[i].size(); j += 2) {
          p[cur] = indices[i][j];
          p[n-1-cur] = indices[i][j+1];
          cur++;
        }
      }
      else {
        for (int j = 0; j < (int)indices[i].size(); j += 2) {
          p[cur] = indices[i][j];
          p[n-1-cur] = indices[i][j+1];
          cur++;
        }
      }
    }

    int num_cycles = 0;
    vector<int> cycid(n, -1);
    for (int i = 0; i < n; i++) {
      if (cycid[i] != -1) continue;
      int v = i;
      while (cycid[v] == -1) {
        cycid[v] = num_cycles;
        v = p[v];
      }
      num_cycles++;
    }
    
    dsu D(num_cycles);

    // first step: put i and n-1-i in the same cycle
    for (int i = 0; i < n/2; i++) {
      if (D.root(cycid[i]) != D.root(cycid[n-1-i])) {
        swap(p[i], p[n-1-i]);
        D.join(cycid[i], cycid[n-1-i]);
      }
    }

    // second step: put i and i+1 in the same cycle
    for (int i = 0; i < n/2-1; i++) {
      if (D.root(cycid[i]) != D.root(cycid[i+1])) {
        swap(p[i], p[n-2-i]);
        swap(p[i+1], p[n-1-i]);
        swap(p[i], p[n-1-i]);
        D.join(cycid[i], cycid[i+1]);
      }
    }

    for (int i = 0; i < n; i++) {
      cout << p[i]+1 << " \n"[i+1==n];
    }
  }
}