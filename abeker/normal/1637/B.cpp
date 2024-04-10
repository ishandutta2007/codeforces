#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int N;
int a[MAXN];
int dp[MAXN][MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

int rec(int l, int r) {
  int &ref = dp[l][r];
  if (ref != -1)
    return ref;
  ref = 0;
  int mex = 0;
  unordered_map <int, bool> bio;
  for (int i = r; i >= l; i--) {
    bio[a[i]] = true;
    while (bio[mex])
      mex++;
    ref = max(ref, rec(l, i - 1) + mex + 1);
  }
  return ref;
}

int solve() {
  memset(dp, -1, sizeof dp);
  int sol = 0;
  for (int i = 0; i < N; i++)
    for (int j = i; j < N; j++)
      sol += rec(i, j);
  return sol;
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