#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (__builtin_popcountll(n) == 1) {
      cout << "-1\n";
      continue;
    }
    int k = __builtin_ctzll(n);
    long long v = 1LL<<(k+1);
    long long m = n>>k;
    cout << min(m, v) << '\n';
  }
}