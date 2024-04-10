#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    if ((x+y)&1) {
      cout << -1 << " " << -1 << endl;
    }
    else {
      if (x >= y) {
        cout << (x+y)/2 << " " << 0 << endl;
      }
      else {
        cout << 0 << " " << (x+y)/2 << endl;
      }
    }
  }
}