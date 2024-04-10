#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int y, b, r;
  cin >> y >> b >> r;
  int k = min({y, b-1, r-2});
  cout << 3*(k+1) << '\n';
}