#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int freq[N], dp[N], a[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fill(dp+1, dp+n+2, -N);
    for (int i = 1; i <= n+1; i++) {
      int m = 0;
      for (int j = i; j >= 1; j--) {
        if (j != i) m = max(m, ++freq[a[j]]);
        //cout << i << " " << j << " " << m << endl;
        if ((i-j)%2 == 0 && m <= (i-j)/2 && (j == 1 || i == n+1 || a[j-1] == a[i])) {
          dp[i] = max(dp[i], dp[j-1]+1);
        }
      }
      for (int j = i-1; j >= 1; j--) {
        freq[a[j]]--;
      }
    }
    cout << dp[n+1]-1 << '\n';
  }
}