#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> a;

void load() {
  scanf("%d", &N);
  a.resize(N + 2);
  for (int i = 1; i <= N; i++)
    scanf("%d", &a[i]);
}

int solve() {
  a[N + 1] = N + 1;
  vector <int> loc(N + 2, N);
  loc[0] = 0;
  int sum = 0, dp = 0;
  multiset <int> mini(loc.begin(), loc.end());
  for (int i = 1; i <= N; i++) {
    mini.erase(mini.find(loc[a[i + 1]]));
    dp = min(*mini.begin(), loc[a[i + 1]] + 1) + sum;
    mini.insert(loc[a[i + 1]]);
    sum += a[i] == a[i + 1];
    dp -= sum;
    mini.erase(mini.find(loc[a[i]]));
    loc[a[i]] = min(loc[a[i]], dp);
    mini.insert(loc[a[i]]);
  }
  return N - dp - sum;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}