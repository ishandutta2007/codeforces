#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m = 1; 
  cin >> n;
  while (m * m <= n) ++m;
  --m;
  long long k = n - m * m;
  if (k == 0) {
    cout << 4LL * m << endl;
    return 0;
  }
  if (k <= m) {
    cout << 4LL * m + 2LL << endl;
    return 0;
  }
  cout << 4LL * m + 4LL << endl;
  return 0;
}