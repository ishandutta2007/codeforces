#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int D = (int)to_string(n).size();
  vector<vector<int>> edges(D, vector<int>(D));
  for (int i = 1; i < n; i++) {
    string _u, _v;
    cin >> _u >> _v;
    int u = (int)_u.size()-1;
    int v = (int)_v.size()-1;
    if (u > v) swap(u, v);
    edges[u][v]++;
  }
  vector<int> vert(D), leaf(D);
  leaf[0] = 1;
  for (int i = 1; i < D; i++) {
    leaf[i] = 10*leaf[i-1];
    vert[i-1] = leaf[i]-leaf[i-1];
  }
  vert[D-1] = n-leaf[D-1]+1;

  auto check = [&] () {
    for (int mask = 1; mask < (1<<D); mask++) {
      int v = 0;
      int e = 0;
      for (int i = 0; i < D; i++) {
        if ((mask>>i)&1) {
          v += vert[i];
          for (int j = i; j < D; j++) {
            if ((mask>>j)&1) {
              e += edges[i][j];
            }
          }
        }
      }
      if (e >= max(v, 1)) return false;
    }
    return true;
  };

  if (!check()) {
    cout << "-1\n";
    return 0;
  }

  // step 1: get rid of leaves until we have one vertex in each group
  for (int i = 0; i < D; i++) {
    for (int j = 0; j < D; j++) {
      while (vert[i] > 1 && edges[min(i, j)][max(i, j)]) {
        edges[min(i, j)][max(i, j)]--;
        vert[i]--;
        if (!check()) {
          edges[min(i, j)][max(i, j)]++;
          vert[i]++;
          break;
        }
        cout << leaf[i] << ' ';
        leaf[i]++;
        cout << leaf[j] << '\n';
      }
    }
  }

  // step 2: brute force to find where the next leaf is
  int remaining = D-1;
  while (remaining--) {
    for (int i = 0; i < D; i++) {
      if (!vert[i]) continue;
      for (int j = 0; j < D; j++) {
        if (!vert[j] || j==i) continue;
        edges[min(i, j)][max(i, j)]--;
        vert[i]--;
        if (!check()) {
          edges[min(i, j)][max(i, j)]++;
          vert[i]++;
        }
        else {
          cout << leaf[i] << ' ' << leaf[j] << '\n';
          break;
        }
      }
    }
  }
}