#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> c(n, vector<int>(m));
    vector<long long> z(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> c[i][j];
        z[i] += 1LL*j*c[i][j];
      }
    }
    cout << max_element(z.begin(), z.end())-z.begin()+1 << ' ';
    cout << *max_element(z.begin(), z.end())-*min_element(z.begin(), z.end()) << '\n';
  }
}