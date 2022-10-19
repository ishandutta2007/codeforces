#include <bits/stdc++.h>
using namespace std;

const int A = 1<<18;
const long long B = pow(5, 18);
const int SHIFT = pow(10, 7);
long long pow5[19];

long long expmod(long long a, long long b, long long m) {
  __int128 ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = ans*a % m;
    b >>= 1;
    a = __int128(a)*a % m;
  }
  return ans;
}

long long discrete_log(long long target) {
  // find k for which 2^k = target mod B
  long long ans = 0;
  if (target%5 == 1) ans = 0;
  else if (target%5 == 2) ans = 1;
  else if (target%5 == 4) ans = 2;
  else if (target%5 == 3) ans = 3;
  else assert(0);

  for (int i = 2; i <= 18; i++) {
    // in this iteration, make the numbers match modulo 5^i
    for (int j = 0; j < 5; j++) {
      if (expmod(2, ans+4*j*pow5[i-2], pow5[i]) == target%pow5[i]) {
        ans += 4*j*pow5[i-2];
        break;
      }
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  pow5[0] = 1;
  for (int i = 1; i < 19; i++) {
    pow5[i] = 5*pow5[i-1];
  }

  int T;
  cin >> T;
  while (T--) {
    long long a;
    cin >> a;
    a *= SHIFT;
    a += A-a%A;
    if (a%5 == 0) a += A;
    cout << 4*pow5[18]+discrete_log(a%B) << '\n';
  }
}