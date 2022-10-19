#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    int z = accumulate(a.begin(), a.end(), 0);
    cout << max(0, z-m) << '\n';
  }
}