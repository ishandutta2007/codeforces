#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll a, b, c, prv;
P x[5];
bool work() {
  x[0] = mp(a, 1), x[1] = mp(b, 2), x[2] = mp(c, 3);
  sort(x, x + 3);
  ll d1 = x[1].first - x[0].first, d2 = x[2].first - x[1].first;
  if (d2 != d1 || x[2].second != prv) {
    printf("%lld\n", d2 + d2 + d1);
    fflush(stdout);
    scanf("%lld", &prv);
    if (!prv) return false;
    if (prv == 1) a += d2 + d2 + d1;
    else if (prv == 2) b += d2 + d2 + d1;
    else if (prv == 3) c += d2 + d2 + d1;
    return true;
  }
  printf("%lld\n", d1);
  fflush(stdout);
  scanf("%lld", &prv);
  return false;
}
int main() {
  scanf("%lld%lld%lld", &a, &b, &c);
  puts("First");
  fflush(stdout);
  while (work());
  return 0;
}