#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e5+2;
int inv[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int zeroes = 0;
    int groups = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        zeroes++;
        flag = 0;
      }
      else {
        if (flag) {
          flag = 0;
          groups++;
        }
        else {
          flag = 1;
        }
      }
    }
    int ans = 1;
    for (int i = zeroes+groups; i >= zeroes+1; i--) {
      ans = 1LL*ans*i % MOD;
    }
    for (int i = 1; i <= groups; i++) {
      ans = 1LL*ans*inv[i] % MOD;
    }
    cout << ans << '\n';
  }
}