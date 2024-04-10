#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    ll K;
    int N;
    scanf("%d%lld", &N, &K);
    vector <ll> a(N);
    for (auto &it : a)  
      scanf("%lld", &it);
    ll g = 0;
    for (int i = 1; i < N; i++)
      g = __gcd(g, a[i] - a[0]);
    puts((K - a[0]) % g ? "NO" : "YES");
  }
  return 0;
}