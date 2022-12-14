#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

int N, X1, Y1, X2, Y2;

struct frac {
  ll j, m;
  frac(ll j = 0, ll m = 1): j(j), m(m) { }
  void norm() {
    if(m < 0) j = -j, m = -m;
  }
  bool operator< (const frac &f) const {
    frac a = *this, b = f;
    a.norm(); b.norm();
    return a.j * b.m < b.j * a.m;
  }
};

int main() {
  scanf("%d%d%d%d%d", &N, &X1, &Y1, &X2, &Y2);

  frac ansb = frac(0, 1);
  frac anst = frac(1e9, 1);

  for(int i = 1; i <= N; i++) {
    int rx, ry, vx, vy; scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
    // strictly inside
    if(vx == 0) {
      if(!(X1 < rx && rx < X2)) return 0 & puts("-1");
    }else {
      frac f[] = {frac(X1 - rx, vx), frac(X2 - rx, vx)};
      sort(f, f+2);
      ansb = max(ansb, f[0]);
      anst = min(anst, f[1]);
    }

    if(vy == 0) {
      if(!(Y1 < ry && ry < Y2)) return 0 & puts("-1");
    }else {
      frac f[] = { frac(Y1 - ry, vy), frac(Y2 - ry, vy) };
      sort(f, f+2);
      ansb = max(ansb, f[0]);
      anst = min(anst, f[1]);
    }

  }

  if(ansb < anst) {
    printf("%.20lf\n", (lf)ansb.j / ansb.m);
  }else {
    puts("-1");
  }

  return 0;
}