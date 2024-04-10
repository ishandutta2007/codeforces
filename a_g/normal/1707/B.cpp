#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a, int z) {
  sort(a.begin(), a.end());
  int n = a.size();
  if (!n) return 0;
  if (n == 1) return a[0];
  if (n == 2) {
    while (z--) {
      a[1] -= a[0];
      if (a[1] < a[0]) swap(a[1], a[0]);
    }
    return a[1]-a[0];
  }
  vector<int> b;
  int nz = max(z-1, 0);
  if (z) b.push_back(a[0]);
  for (int i = 0; i < n-1; i++) {
    int d = (a[i+1]-a[i]);
    if (d) {
      b.push_back(d);
    }
    else {
      nz++;
    }
  }
  return solve(b, nz);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a;
    int z = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 0) z++;
      else a.push_back(x);
    }
    cout << solve(a, z) << '\n';
  }
}