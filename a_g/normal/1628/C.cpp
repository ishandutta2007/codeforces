#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i+j)&1) continue;
        if (i+j < n) {
          if (i&1) continue;
          if (j&1) continue;
          if ((i+j)&3) continue;
        }
        else {
          if (!(i&1)) continue;
          if (!(j&1)) continue;
          if ((i+j)&3) continue;
        }
        ans ^= a[i][j];
        ans ^= a[n-1-i][j];
      }
    }

    cout << ans << '\n';
  }
}