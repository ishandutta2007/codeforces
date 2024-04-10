#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    x--;
    vector<int> deg(n);
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      deg[u]++, deg[v]++;
    }
    if (deg[x] <= 1) {
      cout << "Ayush\n";
      continue;
    }
    cout << (n&1 ? "Ashish" : "Ayush") << '\n';
  }
}