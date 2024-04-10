#include <bits/stdc++.h>
using namespace std;

long long f(long long n) {
  // x^2, x^2+x, x^2+2x
  long long m = floor(sqrt(n));
  if (1LL*m*m > n) m--;
  if (1LL*(m+1)*(m+1) <= n) m++;
  long long ans = 3LL*m-2;
  if (1LL*m*m+m <= n) ans++;
  if (1LL*m*m+2LL*m <= n) ans++;
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long l, r;
    cin >> l >> r;
    cout << f(r)-f(l-1) << '\n';
  }
}