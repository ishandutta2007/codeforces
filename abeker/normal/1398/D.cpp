#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e2 + 5;

int sticks[3];
int len[3][MAXN];
ll dp[MAXN][MAXN][MAXN];

ll rec(array <int, 3> rgb) {
  ll &ref = dp[rgb[0]][rgb[1]][rgb[2]];
  if (ref != -1)
    return ref;
  ref = 0;
  for (int i = 1; i < 3; i++) 
    for (int j = 0; j < i; j++)
      if (rgb[i] && rgb[j]) {
        rgb[i]--;
        rgb[j]--;
        ref = max(ref, rec(rgb) + len[i][rgb[i]] * len[j][rgb[j]]);
        rgb[i]++;
        rgb[j]++;
      }
  return ref;
}

int main() {
  for (int i = 0; i < 3; i++)
    scanf("%d", sticks + i);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < sticks[i]; j++)
      scanf("%d", len[i] + j);
    sort(len[i], len[i] + sticks[i]);
  }
  
  memset(dp, -1, sizeof dp);
  printf("%lld\n", rec({sticks[0], sticks[1], sticks[2]}));
  
  return 0;
}