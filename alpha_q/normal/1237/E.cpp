#include <bits/stdc++.h>

using namespace std;

set <int> v({1, 4, 9, 20, 41, 84, 169, 340, 681, 1364, 2729, 5460, 10921, 21844, 43689, 87380, 174761, 349524, 699049, 1398100, 2796201});

int main() {
  int n; cin >> n;
  if (v.count(n) or v.count(n - 1)) cout << "1\n";
  else cout << "0\n";
  return 0;
}