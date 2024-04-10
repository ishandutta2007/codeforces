#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int n, k;
long long a[N];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  sort(a + 1, a + n + 1);
  vector <pair <ll, ll>> vec;
  for (int i = 1; i <= n;) {
    int j = i;
    while (j <= n and a[j] == a[i]) ++j;
    vec.emplace_back(a[i], j - i), i = j;
  }
  for (auto it : vec) {
    if (it.second >= k) {
      puts("0");
      return 0;
    }
  }
  vector <ll> sfFreq(vec.size() + 1), sfProd(vec.size() + 1);
  sfFreq[vec.size()] = sfProd[vec.size()] = 0;
  for (int i = vec.size() - 1; i >= 0; --i) {
    sfFreq[i] = sfFreq[i + 1] + vec[i].second;
    sfProd[i] = sfProd[i + 1] + vec[i].second * vec[i].first;
  }
  ll pfFreq = 0, pfProd = 0, ans = LLONG_MAX;
  for (int i = 0; i < vec.size(); ++i) {
    ll pfCost = 0, sfCost = 0;
    if (i) pfCost = pfFreq * (vec[i].first - 1) - pfProd;
    if (i + 1 < vec.size()) sfCost = sfProd[i + 1] - sfFreq[i + 1] * (vec[i].first + 1);
    int need = k - vec[i].second;
    ll cur = pfCost + sfCost + need;
    if (pfFreq >= need) {
      ll justLeft = pfCost + need;
      cur = min(cur, justLeft);
    }
    if (sfFreq[i + 1] >= need) {
      ll justRight = sfCost + need;
      cur = min(cur, justRight);
    }
    pfFreq += vec[i].second;
    pfProd += vec[i].second * vec[i].first;
    ans = min(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}