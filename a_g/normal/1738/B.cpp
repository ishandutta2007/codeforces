#include <bits/stdc++.h>
using namespace std;

long long ceil(long long x, int y) {
  if (x >= 0) return (x+y-1)/y;
  else return x/y;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = n-k; i <= n-1; i++) {
      cin >> a[i];
    }
    for (int i = n-1; i >= n-k+1; i--) {
      a[i] -= a[i-1];
    }
    long long v = a[n-k];
    for (int i = 0; i <= n-k; i++) {
      a[i] = ceil(v, n-k+1);
    }
    cout << (is_sorted(a.begin(), a.end()) ? "Yes" : "No") << '\n';
  }
}