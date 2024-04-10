#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int freq[N], dp[N][3][3];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (n--) {
    int x;
    cin >> x;
    freq[x]++;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j+k) dp[i][j][k] = -1e9;
      }
    }
  }

  for (int a = 3; a < N; a++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          // i triples of a, a-1, a-2
          // j triples of a-1, a-2, a-3
          // k triples of a-2, a-3, a-4
          if (freq[a-2] >= i+j+k && freq[a-1] >= i+j && freq[a] >= i) {
            dp[a][i][j] = max(dp[a][i][j], dp[a-1][j][k]+i+(freq[a-2]-i-j-k)/3);
          }
        }
      }
    }
  }
  cout << dp[N-1][0][0] << '\n';
}