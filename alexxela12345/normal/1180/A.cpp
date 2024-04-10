#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;
  n++;
  cout << 4 * n * (n - 1) / 2 - 4 * n + 5 << endl;
}