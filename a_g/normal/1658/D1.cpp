#include <bits/stdc++.h>
using namespace std;

const int M = 17;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    vector<int> a(r-l+1);
    for (int i = 0; i < r-l+1; i++) {
      cin >> a[i];
    }
    int x = 0;
    for (int i = M-1; i >= 0; i--) {
      int c = 0;
      for (int val: a) {
        if (val&(1<<i)) c++;
        else c--;
      }
      if (c > 0) x ^= (1<<i);
    }
    cout << x << '\n';
  }
}