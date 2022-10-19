#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

ll P;
int Q;

void load() {
  scanf("%lld%d", &P, &Q);
}

ll solve() {
  vector <pii> fact;
  for (int i = 2; i * i <= Q; i++)
    if (!(Q % i)) {
      int ex = 0;
      for (; !(Q % i); Q /= i)
        ex++;
      fact.push_back({i, ex});
    }
  if (Q > 1)
    fact.push_back({Q, 1});
  ll mini = P;
  for (auto it : fact) {
    int ex = 0;
    for (ll x = P; !(x % it.first); x /= it.first)
      ex++;
    ll tmp = 1;
    ex = max(ex - it.second + 1, 0);
    while (ex--)
      tmp *= it.first;
    mini = min(mini, tmp);
  }
  return P / mini;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%lld\n", solve());    
  }
  return 0;
}