#include <bits/stdc++.h>
using namespace std;

const int N = 15;
long long fact[N];
long long val[1<<N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[3] = 6;
  for (int i = 4; i < N; i++) {
    fact[i] = i*fact[i-1];
  }
  for (int i = 0; i < (1<<N); i += 8) {
    for (int j = 3; j < N; j++) {
      if (i&(1<<j)) {
        val[i] += fact[j];
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    int ans = 1e9;
    for (int i = 0; i < (1<<N); i += 8) {
      if (val[i] <= n) {
        ans = min(ans, __builtin_popcountll(i) + __builtin_popcountll(n-val[i]));
      }
    }
    cout << ans << '\n';
  }
}