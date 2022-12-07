#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long inf = 2e18;
long long size, time, t0, ans;
long long a1, t1, p1, a2, t2, p2;

inline long long Ceil(long long a, long long b) {
  return (a + b - 1) / b;
}

void Solve(void) {
  for (int cnt_a = 0; cnt_a <= size / a1; ++cnt_a) {
    long long time_rest = time - cnt_a * t1 * a1;
    if (time_rest < 0) {
      break;
    }
    long long size_rest = size - a1 * cnt_a;
 
    // All use B
    if (size_rest * t2 > time_rest) {
      continue;
    } else {
      ans = min(ans, cnt_a * p1 + Ceil(size_rest, a2) * p2);
    }

    // No use B
    if (size_rest * t0 <= time_rest) {
      ans = min(ans, cnt_a * p1);
      continue;
    }

    // Part use B
    long long cnt_b = Ceil(size_rest * t0 - time_rest,
                           a2 * t0 - a2 * t2);
    cnt_b = max(cnt_b, 0LL);
    ans = min(ans, cnt_a * p1 + cnt_b * p2);
  }

  // All use A
  if (size * t1 <= time) {
    ans = min(ans, Ceil(size, a1) * p1);
  }
}

int main(void) {
  scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld", &size, &time, &t0,
        &a1, &t1, &p1, &a2, &t2, &p2);
  t1 = min(t1, t0);
  t2 = min(t2, t0);

  ans = inf;
  Solve();
  swap(a1, a2);
  swap(t1, t2);
  swap(p1, p2);
  Solve();
  printf("%lld\n", ans == inf ? -1 : ans);
  return 0;
}