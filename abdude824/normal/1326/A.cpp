/**
 *    author:  tourist
 *    created: 19.03.2020 17:33:15       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << -1 << '\n';
      continue;
    }
    string s(n, '2');
    s[n - 1] = '3';
    int sum = (n - 1) * 2 + 3;
    if (sum % 3 == 0) {
     s[0] += 2;
   }
   cout << s << '\n';
  }
  return 0;
}