#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int d = 1;
  while (n--) {
    int x;
    cin >> x;
    if (x%2 == 0) {
      cout << x/2 << '\n';
    }
    else {
      cout << (x+d)/2 << '\n';
      d = -d;
    }
  }
}