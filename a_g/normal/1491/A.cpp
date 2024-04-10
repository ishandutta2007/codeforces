#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int c = accumulate(a.begin(), a.end(), 0);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      c += 1-2*a[x-1];
      a[x-1] = 1-a[x-1];
    }
    else {
      int k;
      cin >> k;
      cout << (k <= c ? 1 : 0) << '\n';
    }
  }
}