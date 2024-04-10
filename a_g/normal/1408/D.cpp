#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+5;
int h[M];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c[i] >> d[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int dx = c[j]-a[i]+1;
      int dy = d[j]-b[i]+1;
      if (dx <= 0 || dy <= 0) continue;
      h[dx-1] = max(h[dx-1], dy);
    }
  }

  for (int i = M-2; i >= 0; i--) {
    h[i] = max(h[i], h[i+1]);
  }
  int ans = M;
  for (int i = 0; i < M; i++) {
    ans = min(ans, i+h[i]);
  }
  cout << ans << '\n';
}