#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  vector<int> sums(n+1);
  sums[0] = 0;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    sums[i+1] = sums[i] + val;
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (sums[r]-sums[l-1])/10 << '\n';
  }
}