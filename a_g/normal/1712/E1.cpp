#include <bits/stdc++.h>
using namespace std;

// lcm(i, j, k) < i+j+k
// lcm(i, j, k) = k
//
// lcm(i, j, k) = 2*k, i+j > k, i < k, j < k
// must be (i, j) = (2k/5, 2k/3) or (2k/4, 2k/3)

const int N = 2e5+5;
int divisors[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
      for (int j = 2*i; j < N; j += i) {
        divisors[j]++;
      }
    }

    int d = r-l+1;
    long long ans = 1LL*d*(d-1)*(d-2)/6;
    for (int k = r; k >= l; k--) {
      ans -= divisors[k]*(divisors[k]-1)/2;
      if (k%15 == 0 && 2*k >= 5*l) ans--;
      if (k%6 == 0 && k >= 2*l) ans--;
    }
    cout << ans << '\n';

    for (int i = l; i < N; i++) {
      divisors[i] = 0;
    }
  }
}