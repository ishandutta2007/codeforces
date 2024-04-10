#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int x = (n+5)/3;
    int y = (n-x+1)/2;
    int z = (n-x)/2;
    if (y == z) {
      y++;
      z--;
    }
    cout << y << " " << x << " " << z << '\n';
  }
}