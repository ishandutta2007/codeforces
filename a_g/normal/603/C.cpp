#include <bits/stdc++.h>
using namespace std;

int val(int a, int k) {
  if (k&1) {
    if (a == 2) return 0;
    if (a > 4 && a&1) return 0;
    if (a == 1 || a == 3) return 1;
    int u = (a>>__builtin_ctz(a));
    bool x = (u == 3);
    bool y = __builtin_ctz(a) & 1;
    return (x == y ? 2 : 1);
  }
  else {
    if (a == 2) return 2;
    if (a == 1) return 1;
    return 1-a&1;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  int nimval = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    nimval ^= val(a, k);
  }
  cout << (nimval ? "Kevin" : "Nicky") << endl;
}