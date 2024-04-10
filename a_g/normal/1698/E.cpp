#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), p(n, -1);
    vector<bool> take(n);
    for (int& x: a) {
      cin >> x;
      x--;
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x != -1) {
        p[a[i]] = x-1;
        take[x-1] = 1;
      }
    }

    int ans = 1;
    int c = 0;
    for (int i = n-1; i >= max(0, n-s-1); i--) {
      if (!take[i]) c++;
    }
    for (int i = n-1; i > 0; i--) {
      if (p[i] == -1) {
        ans = 1LL * ans * c % MOD;
        c--;
      }
      else if (p[i] < i-s) {
        ans = 0;
      }
      if (i-s-1 >= 0 && !take[i-s-1]) c++;
    }
    
    cout << ans << '\n';
  }
}