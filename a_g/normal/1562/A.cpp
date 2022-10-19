#include <bits/stdc++.h>
using namespace std;

int main () {
  int t;
  cin >> t;
  for (int i=0; i < t; i++) {
    int l, r;
    cin >> l >> r;
    if (l > r/2) {
      cout << r-l << endl;
    }
    else {
      cout << (r-1)/2 << endl;
    }
  }
}