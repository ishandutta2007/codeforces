#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    int tot = accumulate(a.begin(), a.end(), 0);
    bool win = 0;
    for (int x: a) {
      if (x*n == tot) win = 1;
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}