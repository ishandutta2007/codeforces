#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    string s(m, 'B');
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      c[min(x, m-1-x)]++;
    }
    for (int i = 0; i < m; i++) {
      if (c[i] >= 2) {
        s[i] = 'A';
        s[m-1-i] = 'A';
      }
      else if (c[i] == 1) {
        s[i] = 'A';
      }
    }
    cout << s << '\n';
  }
}