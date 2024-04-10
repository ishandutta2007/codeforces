#include <bits/stdc++.h>
using namespace std;

const int N = 1<<20;
bool ans[N];

int g(int a, int b) {
  // parity of a choose b
  return ((a&b) == b ? 1 : 0);
}

int f(int a, int b) {
  // parity of (a choose 0) + ... + (a choose b)
  if (b >= a) {
    return (a ? 0 : 1);
  }
  int k = __builtin_ctz(a);
  a >>= k;
  b >>= k;
  return ((b&1) ? 0 : g(a, b));
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  k = n-1-k;
  vector<int> b(n);
  for (int& x: b) cin >> x;
  for (int w = 0; w <= min(k, 20); w++) {
    for (int i = 0; i+w < n; i++) {
      int free = n-1-w;
      if (i != 0) free--;
      if (i+w != n-1) free--;
      if (f(free, k-w)&1) {
        int tot = 0;
        for (int j = i+1; j <= i+w; j++) {
          tot += b[j];
        }
        if (tot > 20) continue;
        long long z = (long long)(b[i])<<tot;
        if (z >= N) continue;
        ans[z] ^= 1;
      }
    }
  }
  bool start = 0;
  for (int i = N-1; i >= 0; i--) {
    if (ans[i]) {
      cout << "1";
      start = 1;
    }
    else if (start) {
      cout << "0";
    }
  }
  if (!start) {
    cout << "0";
  }
  cout << '\n';
}