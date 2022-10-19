#include <bits/stdc++.h>
using namespace std;

// source: editorial

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int x = 1;
  while (x <= n) {
    if (x == n || x+1 == n) {
      cout << "1\n";
      return 0;
    }
    x = (x&1 ? 2*x+2 : 2*x+1);
  }
  cout << "0\n";
}