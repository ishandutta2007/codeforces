#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> point;

#define x first
#define y second

const int N = 200010;

int n, at; point p[N], hull[N];

inline ll area (point a, point b, point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", &p[i].x, &p[i].y);
    p[i].y -= p[i].x * p[i].x;
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; ++i) {
    while (at >= 2 and area(hull[at - 1], hull[at], p[i]) >= 0) --at;
    hull[++at] = p[i];
  }
  int ans = at;
  if (at >= 2 and hull[1].x == hull[2].x) --ans;
  if (at > 2 and hull[at - 1].x == hull[at].x) --ans;
  cout << ans - 1 << endl;
  return 0;
}