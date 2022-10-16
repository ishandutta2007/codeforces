// Author: wlzhouzhuan
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;
const double eps = 1e-9;
const double PI = acos(-1.);

double x[N], y[N], ang[N], dis[N];
int n, m;

bool check(double r) {
  vector<pair<double, int>> zyk; int cnt = 0;
  rep(i, 1, n) {
    if (dis[i] >= 2 * r - eps) continue;
    double fuck = acos((dis[i] / 2.) / r);
    double L = ang[i] - fuck, R = ang[i] + fuck;
    while (L < 0) L += 2 * PI; while (L >= 2 * PI) L -= 2 * PI;
    while (R < 0) R += 2 * PI; while (R >= 2 * PI) R -= 2 * PI;
    if (L > R) cnt++;
    zyk.pb({L, 1}), zyk.pb({R, -1});
  }
  sort(zyk.begin(), zyk.end());
  int ans = cnt;
  for (auto it: zyk) {
    cnt += it.sec;
    ckmax(ans, cnt);
  }
  return ans >= m;
}

int main() {
  n = read(), m = read();
  rep(i, 1, n) {
    x[i] = read(), y[i] = read();
    if (fabs(x[i] - 0.) < eps && fabs(y[i] - 0.) < eps) {
      i--, n--, m--;
      continue;
    }
    ang[i] = atan2(y[i], x[i]);
    dis[i] = sqrt(x[i] * x[i] + y[i] * y[i]);
  }
  if (m <= 0) {
    puts("0.0000000");
    return 0;
  }
  double l = 0, r = 2e5;
  rep(times, 0, 50) {
    double mid = (l + r) / 2.;
    if (check(mid)) r = mid;
    else l = mid;
  }
  printf("%.10f\n", l);
  return 0;
}