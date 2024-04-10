#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e3 + 5;

int N;
int perm[MAXN];
int pref[MAXN][MAXN];
int suff[MAXN][MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", perm + i);
}

ll solve() {
  for (int j = 1; j <= N; j++)
    suff[N + 1][j] = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      pref[i][j] = pref[i - 1][j] + (perm[i] <= j);
  for (int i = N; i; i--)
    for (int j = 1; j <= N; j++)
      suff[i][j] = suff[i + 1][j] + (perm[i] <= j);
  ll sol = 0;
  for (int i = 1; i < N; i++)
    for (int j = i + 1; j <= N; j++)
      sol += (ll)pref[i - 1][perm[j] - 1] * suff[j + 1][perm[i] - 1];
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