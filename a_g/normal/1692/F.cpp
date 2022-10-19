#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> f(10);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      f[a%10]++;
    }
    bool win = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
          if ((i+j+k)%10 == 3) {
            f[i]--;
            f[j]--;
            f[k]--;
            if (f[i] >= 0 && f[j] >= 0 && f[k] >= 0) win = 1;
            f[i]++;
            f[j]++;
            f[k]++;
          }
        }
      }
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}