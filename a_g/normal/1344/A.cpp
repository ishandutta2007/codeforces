#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<bool> b(n);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      int x = (a+i)%n;
      if (x < 0) x += n;
      b[x] = 1;
    }
    cout << (accumulate(b.begin(), b.end(), 0) == n ? "YES" : "NO") << '\n';
  }
}