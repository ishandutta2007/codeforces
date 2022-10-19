#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 2e5+5;
int fib[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < N; i++) {
    fib[i] = (fib[i-1]+fib[i-2]) % MOD;
  }

  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  set<int> S;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  auto is_child = [&] (int x) {
    while (x) {
      if (x%4 == 2) return 0;
      if (x&1) x >>= 1;
      else x >>= 2;
      if (S.count(x)) return 1;
    }
    return 0;
  };

  for (int i = 0; i < n; i++) {
    if (!is_child(a[i])) {
      S.insert(a[i]);
    }
  }

  int ans = 0;
  for (int x: S) {
    int k = 31-__builtin_clz(x);
    if (k >= p) break;
    ans = (ans + fib[p-k+2]-1) % MOD;
  }
  cout << ans << '\n';
}