#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int& x: p) cin >> x;
  long long a = 0;
  long long b = 1;
  int cur = 0;
  bool start = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] >= n-k+1) {
      a += p[i];
      if (start) {
        b = 1LL * b * (cur+1) % MOD;
      }
      start = 1;
      cur = 0;
    }
    else {
      cur++;
    }
  }
  cout << a << " " << b << '\n';
}