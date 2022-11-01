#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;
const ll INF = 1e18 + 69;

int t, n; ll a[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    ll zero = 0;
    vector <ll> pos, neg;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i); 
      if (a[i] > 0) pos.emplace_back(a[i]);
      else if (a[i] < 0) neg.emplace_back(-a[i]);
      else ++zero;
    }
    ll ans = LLONG_MIN;
    if (zero) ans = 0;
    sort(pos.begin(), pos.end());
    reverse(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    vector <ll> revNeg = neg;
    reverse(revNeg.begin(), revNeg.end());
    for (int posC = 0; posC <= min(5, (int) pos.size()); ++posC) {
      int negC = 5 - posC;
      if (negC > neg.size()) continue;
      ll cur = 1;
      for (int i = 0; i < posC; ++i) cur *= pos[i];
      if (negC & 1) {
        for (int i = 0; i < negC; ++i) cur *= neg[i];
        cur = -cur;
      } else {
        for (int i = 0; i < negC; ++i) cur *= revNeg[i];
      }
      ans = max(ans, cur);
    }
    printf("%lld\n", ans);
  }
  return 0;
}