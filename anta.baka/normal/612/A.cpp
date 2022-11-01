#include <bits/stdc++.h>

using namespace std;

int main() {
  //freopen("in.txt", "r", stdin);
  int n, p, q;
  cin >> n >> p >> q;
  string s;
  cin >> s;
  for(int i = 0; i * p <= n; i++) {
    if((n - i * p) % q == 0) {
      int ii = (n - i * p) / q;
      cout << i + ii << '\n';
      int pt = 0;
      for(int j = 0; j < i; j++) {
        cout << s.substr(pt, p) << '\n';
        pt += p;
      }
      for(int j = 0; j < ii; j++) {
        cout << s.substr(pt, q) << '\n';
        pt += q;
      }
      return 0;
    }
  }
  cout << -1;
}