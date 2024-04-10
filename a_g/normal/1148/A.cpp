#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  a = min(a, b+1);
  b = min(b, a+1);
  cout << 0LL+a+b+2*c << '\n';
}