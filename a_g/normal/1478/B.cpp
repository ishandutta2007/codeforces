#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
bool dp[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int q, d;
    cin >> q >> d;
    dp[0] = 1;
    for (int i = 0; i < 100; i++) {
      if (i%10 == d || i/10 == d) {
        for (int j = 0; j + i < N; j++) {
          if (dp[j]) dp[i+j] = 1;
        }
      }
    }
    while (q--) {
      int a;
      cin >> a;
      cout << (a >= N || dp[a] ? "YES" : "NO") << '\n';
    }
    fill(dp, dp+N, 0);
  }
}