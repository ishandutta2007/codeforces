#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int deg[2][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n);
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      edges[i] = {a, b};
      deg[0][a]++;
      deg[1][b]++;
    }
    long long ans = 1LL*n*(n-1)*(n-2)/6;
    for (auto& [a, b]: edges) {
      ans -= 1LL*(deg[0][a]-1)*(deg[1][b]-1);
    }

    for (int i = 1; i <= n; i++) {
      deg[0][i] = 0;
      deg[1][i] = 0;
    }
    cout << ans << '\n';
  }
}