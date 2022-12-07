#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

ll u, v;
int main() {
  scanf("%lld%lld", &u, &v);
  if (v < u) {
    puts("-1");
    return 0;
  }
  if (u == v) {
    if (!v) puts("0");
    else printf("1\n%lld\n", u);
    return 0;
  }
  ll d = v - u;
  if (d & 1) {
    puts("-1");
    return 0;
  }
  d >>= 1;
  if (d & u) {
    printf("3\n%lld %lld %lld\n", u, d, d);
  } else {
    printf("2\n%lld %lld\n", u | d, d);
  }
  return 0;
}