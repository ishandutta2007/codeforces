#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int m = 1e9;
    int evens = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a%2 == 0) evens++;
      m = min(m, __builtin_ctz(a));
    }
    cout << m+evens+(m ? -1 : 0) << '\n';
  }
}