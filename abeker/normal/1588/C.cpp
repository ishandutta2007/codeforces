#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 5;

int N;
ll pref[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    int x;
    scanf("%d", &x);
    pref[i] = pref[i - 1] + (i % 2 ? x : -x);
  }
}

template <typename T>
typename vector <T>::iterator lb(vector <T> &v, T val) {
  return lower_bound(v.begin(), v.end(), val);
}

ll solve() {
  vector <ll> comp(pref, pref + N + 1);
  sort(comp.begin(), comp.end());
  vector <vector <int>> occ(N + 1);
  for (int i = 0; i <= N; i++) {
    pref[i] = lb(comp, pref[i]) - comp.begin();
    occ[pref[i]].push_back(i);
  }
  set <int> odd = {N + 1};
  vector <int> limit(N + 1, N + 1);
  for (int i = 0; i <= N; i++) {
    for (auto it : occ[i])
      limit[it] = min(limit[it], *odd.lower_bound(it + 1));
    for (auto it : occ[i])
      if (it % 2)
        odd.insert(it);
  }
  set <int> even = {N + 1};
  for (int i = N; i >= 0; i--) {
    for (auto it : occ[i])
      limit[it] = min(limit[it], *even.lower_bound(it + 1));
    for (auto it : occ[i])
      if (!(it % 2))
        even.insert(it);
  }
  ll sol = 0;
  for (int i = 0; i < N; i++)
    sol += lb(occ[pref[i]], limit[i]) - lb(occ[pref[i]], i + 1);
  return sol;
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