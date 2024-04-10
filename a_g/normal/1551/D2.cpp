#include <bits/stdc++.h>
using namespace std;

char conv(int n) {
  return 'a' + (n+26)%26;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int total = (m*n)/2;
    bool transpose = 0;
    if (n&1) {
      swap(m, n);
      k = total-k;
      transpose = 1;
    }
    bool possible = 1;
    if (k&1) possible = 0;
    if (m&1 && k > (m/2)*n) possible = 0;
    cout << (possible ? "YES" : "NO") << endl;
    if (possible) {
      const int p = 2;
      const int q = 2;
      char ans[n][m];
      int vert = 0;
      for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < m/2; j++) {
          char c = conv(p*i+q*j);
          char d = conv(p*i+q*j+1);
          if (vert < k/2) {
            ans[2*i][2*j] = c;
            ans[2*i][2*j+1] = c;
            ans[2*i+1][2*j] = d;
            ans[2*i+1][2*j+1] = d;
            vert++;
          }
          else {
            ans[2*i][2*j] = c;
            ans[2*i][2*j+1] = d;
            ans[2*i+1][2*j] = c;
            ans[2*i+1][2*j+1] = d;
          }
        }
        if (m&1) {
          char c = conv(p*i+q*m/2-1);
          ans[2*i][m-1] = c;
          ans[2*i+1][m-1] = c;
        }
      }

      if (!transpose) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            cout << ans[i][j];
          }
          cout << endl;
        }
      }
      else {
        for (int j = 0; j < m; j++) {
          for (int i = 0; i < n; i++) {
            cout << ans[i][j];
          }
          cout << endl;
        }
      }
    }
  }
}