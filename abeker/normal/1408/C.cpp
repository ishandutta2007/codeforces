#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const double eps = 1e-9;

int N, L;
double a[MAXN];

void load() {
  scanf("%d%d", &N, &L);
  for (int i = 1; i <= N; i++)
    scanf("%lf", a + i);
}

double solve() {
  a[0] = 0;
  a[N + 1] = L;
  double sol = 0;
  double pos_left = 0, pos_right = L;
  int speed_left = 1, speed_right = 1;
  while (1) {
    int nxt_left = upper_bound(a, a + N + 1, pos_left) - a;
    int nxt_right = lower_bound(a, a + N + 1, pos_right) - a - 1;
    if (nxt_left > nxt_right) {
      sol += (pos_right - pos_left) / (speed_left + speed_right);
      break;
    }
    double time_left = (a[nxt_left] - pos_left) / speed_left;
    double time_right = (pos_right - a[nxt_right]) / speed_right;
    double step = min(time_left, time_right);
    pos_left += step * speed_left;
    pos_right -= step * speed_right;
    if (pos_left >= a[nxt_left] - eps)
      speed_left++;
    if (pos_right <= a[nxt_right] + eps)
      speed_right++;
    sol += step;
  }
  return sol;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%.10lf\n", solve());
  }
  return 0;
}