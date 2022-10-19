#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

map <pii, int> dp, bio;

int grundy(ll mask, int rest) {
  int &ref = dp[pii(mask, rest)];
  if (bio[pii(mask, rest)]++)
    return ref;
  ll tmp = 0;
  for (int i = 1; i <= rest; i++)
    if (!(mask >> i & 1ll))
      tmp |= 1 << grundy(mask ^ 1ll << i, rest - i);
  for (int i = 0; i <= 60; i++)
    if (!(tmp >> i & 1ll))
      return ref = i;
  return ref = -1;
}

int main() {
  int N;
  scanf("%d", &N);
  int sol = 0;
  while (N--) {
    int x;
    scanf("%d", &x);
    sol ^= grundy(0, x);
  }
  puts(sol ? "NO" : "YES");
  return 0;
}