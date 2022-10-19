#include <bits/stdc++.h>
using namespace std;

const int N = 32768;
int ans[N+1];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fill(ans, ans+N, 999);
  ans[0] = 0;
  for (int k = 0; k < 16; k++) {
    int m = 1<<k;
    for (int j = m; j <= N; j += m) {
      for (int l = j-m+1; l <= j; l++) {
        ans[l] = min(ans[l], j-l+15-k);
      }
    }
  }
  int n;
  cin >> n;

  while (n--) {
    int a;
    cin >> a;
    cout << ans[a] << ' ';
  }
  cout << '\n';
}