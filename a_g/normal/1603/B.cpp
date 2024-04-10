#include <bits/stdc++.h>
using namespace std;

long long f(long long x, long long y) {
  if (y >= 3*x) {
    long long a = y % x;
    if (a > 0) return y-a/2;
    return y;
  }
  else if (x <= y) return (x+y)/2;
  else return x+y;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long x, y;
    cin >> x >> y;
    cout << f(x, y) << '\n';
  }
}