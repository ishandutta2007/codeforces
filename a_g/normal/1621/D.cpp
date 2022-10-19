#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 512;
int c[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
      for (int j = 0; j < 2*n; j++) {
        cin >> c[i][j];
      }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans += c[i+n][j+n];
      }
    }
    ans += min({c[0][n], c[0][2*n-1], c[n-1][n], c[n-1][2*n-1], c[n][0], c[2*n-1][0], c[n][n-1], c[2*n-1][n-1]});
    cout << ans << '\n';
  }
}