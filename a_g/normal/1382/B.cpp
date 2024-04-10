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
    int z = 0;
    while (z < n && a[z] == 1) z++;
    cout << ((z&1)^(z==n) ? "Second" : "First") << '\n';
  }
}