#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 2e5 + 5;

int N;
ll a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%lld", a + i);
}

int solve() {
  int sol = 0;
  vector <pii> curr;
  for (int i = 1; i < N; i++) {
    ll diff = abs(a[i] - a[i - 1]);
    for (auto &it : curr)
      it.first = __gcd(it.first, diff);
    curr.push_back({diff, 1});
    vector <pii> nxt;
    for (auto it : curr)
      if (nxt.empty() || nxt.back().first != it.first)
        nxt.push_back(it);
      else
        nxt.back().second += it.second;
    curr = nxt;
    sol = max(sol, i - (curr[0].first == 1 ? curr[0].second : 0));
  }
  return sol + 1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}