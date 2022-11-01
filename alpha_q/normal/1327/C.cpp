#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main() {
  cin >> n >> m;
  string yo = "";
  for (int i = 1; i < n; ++i) yo += 'U';
  for (int i = 1; i < m; ++i) yo += 'L';
  int it = (n - 1) / 2;
  for (int i = 0; i < it; ++i) {
    for (int i = 1; i < m; ++i) yo += 'R';
    yo += 'D';
    for (int i = 1; i < m; ++i) yo += 'L';
    yo += 'D';
  }
  if (n & 1) {
    for (int i = 1; i < m; ++i) yo += 'R';
  } else {
    for (int i = 1; i < m; ++i) yo += 'R';
    yo += 'D';
    for (int i = 1; i < m; ++i) yo += 'L';  
  }
  assert(yo.size() <= 2 * n * m);
  cout << yo.size() << '\n' << yo << '\n';
  return 0;
}