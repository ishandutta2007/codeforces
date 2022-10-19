#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> R(N, -1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      R[x] = i;
    }
    int ans = -1;
    for (int i = 1; i < N; i++) {
      for (int j = i; j < N; j++) {
        if (__gcd(i, j) == 1 && R[i] >= 0 && R[j] >= 0) {
          ans = max(ans, R[i]+R[j]+2);
        }
      }
    }
    cout << ans << '\n';
  }
}