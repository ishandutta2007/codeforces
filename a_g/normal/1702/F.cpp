#include <bits/stdc++.h>
using namespace std;

const int N = 31;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      x >>= __builtin_ctz(x);
      a[x]++;
    }
    bool good = 1;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      x >>= __builtin_ctz(x);
      if (!good) continue;
      while (x) {
        if (a[x]) {
          a[x]--;
          break;
        }
        else {
          x /= 2;
          if (x) x >>= __builtin_ctz(x);
        }
      }
      if (!x) good = 0;
    }

    cout << (good ? "YES" : "NO") << '\n';
  }
}