#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  const int maxn = 100;

  vector<int> ans[maxn+1][(maxn*(maxn+1))/2+1];
  for (int n = 1; n <= maxn; n++) {
    int m = (n*(n+1))/2;
    ans[n][m].resize(n);
    iota(ans[n][m].begin(), ans[n][m].end(), 1);
    if (n > 3) {
      for (int i = 2; i <= n; i += 2) ans[n][n+1].push_back(i);
      ans[n][n+1].push_back(1);
      for (int i = n-1+(n&1); i > 1; i -= 2) ans[n][n+1].push_back(i);
    }
    for (int k = n+2; k < m; k++) {
      bool done = 0;
      for (int a = 2; a <= (n+1)/2; a++) {
        if (done) break;
        for (int b = a+1; b <= min((a*(a+1))/2, k+a-n-1); b++) {
          if (done) break;
          if (ans[a][b].size() > 0 && ans[n+1-a][k+1-b].size() > 0) {
            done = 1;
            // ensure that first element < last element always
            vector<int> p1 = ans[a][b];
            vector<int> p2 = ans[n+1-a][k+1-b];
            for (auto it = p2.rbegin(); it < p2.rend(); it++) {
              ans[n][k].push_back(*it+p1[0]-1);
            }
            for (auto it = p1.begin()+1; it < p1.end(); it++) {
              if (*it > p1[0]) ans[n][k].push_back(*it+n-a);
              else ans[n][k].push_back(*it);
            }
          }
        }
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    if (ans[n][k].size()) {
      cout << "YES\n";
      for (int i: ans[n][k]) cout << i << ' ';
      cout << '\n';
    }
    else cout << "NO\n";
  }
}