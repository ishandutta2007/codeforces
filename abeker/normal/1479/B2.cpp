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
  vector <int> loc(N + 2, -N);
  loc[0] = 0;
  int sum = 0, dp = 0;
  multiset <int> maks(loc.begin(), loc.end());
  for (int i = 1; i <= N; i++) {
    maks.erase(maks.find(loc[a[i + 1]]));
    dp = max(*maks.rbegin(), loc[a[i + 1]] + 1) + sum;
    maks.insert(loc[a[i + 1]]);
    sum += a[i] == a[i + 1];
    dp -= sum;
    maks.erase(maks.find(loc[a[i]]));
    loc[a[i]] = max(loc[a[i]], dp);
    maks.insert(loc[a[i]]);
  }
  return N - dp - sum;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}