#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", a + i);
    a[i] %= 2;
  }
}

ll solve() {
  ll sol = INF;
  for (int k = 0; k < 2; k++) {
    vector <vector <int>> pos(2);
    for (int i = N - 1; i >= 0; i--)
      pos[(i + k) % 2].push_back(i);
    bool bad = false;
    vector <int> perm(N);
    for (int i = 0; i < N; i++)
      if (pos[a[i]].empty()) {
        bad = true;
        break;
      }
      else {
        perm[i] = pos[a[i]].back();
        pos[a[i]].pop_back();
      }
    if (bad)
      continue;
    vector <int> fen(N + 1);
    auto update = [&](int x) {
      for (x++; x <= N; x += x & -x)
        fen[x]++;
    };
    auto get = [&](int x) -> int {
      int res = 0;
      for (x++; x; x -= x & -x)
        res += fen[x];
      return res;
    };
    ll inv = 0;
    for (int i = 0; i < N; i++) {
      inv += i - get(perm[i]);
      update(perm[i]);
    }
    sol = min(sol, inv);
  }
  return sol == INF ? -1 : sol;
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