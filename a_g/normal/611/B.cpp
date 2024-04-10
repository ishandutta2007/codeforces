#include <bits/stdc++.h>
using namespace std;

int f(long long x) {
  int ans = 0;
  for (int i = 2; i <= 62; i++) {
    for (int j = 0; j < i-1; j++) {
      long long z = (1LL<<i)-1-(1LL<<j);
      if (z <= x) ans++;
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long a, b;
  cin >> a >> b;
  cout << f(b)-f(a-1) << '\n';
}