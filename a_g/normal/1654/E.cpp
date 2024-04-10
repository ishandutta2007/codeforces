#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int B = 100;
const int K = N*(2*B+1);
int a[N], m[K];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int match = min(2, n);
  for (int s = -B; s <= B; s++) {
    for (int i = 0; i < n; i++) {
      long long c = a[i] - 1LL * i * s;
      match = max(match, ++m[c+N*B]);
    }
    for (int i = 0; i < n; i++) {
      long long c = a[i] - 1LL * i * s;
      --m[c+N*B];
    }
  }
  for (int i = 0; i < n; i++) {
    int z = min(n, i+N/B+2);
    for (int j = i+1; j < z; j++) {
      // y = mx+b
      int dy = a[j]-a[i];
      int dx = j-i;
      if (dy % dx == 0) {
        match = max(match, 1+(++m[dy/dx+N]));
      }
    }
    for (int j = i+1; j < z; j++) {
      // y = mx+b
      int dy = a[j]-a[i];
      int dx = j-i;
      if (dy % dx == 0) {
        --m[dy/dx+N];
      }
    }
  }

  cout << n-match << '\n';
}