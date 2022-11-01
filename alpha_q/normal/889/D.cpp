#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> point;

struct line {
  ld a, b, c;
};

#define x first
#define y second

const int N = 2005;
const ld EPS = 1e-9;

int n;
line l[N];
set <point> s;
point center;

bool num_eq (ld a, ld b) {
  return fabs(a - b) < EPS;
}

bool point_eq (point a, point b) {
  return num_eq(a.x, b.x) and num_eq(a.y, b.y);
}

void print (point p) {
  cout << p.x << " " << p.y << endl;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    ld x, y;
    scanf("%Lf %Lf", &x, &y);
    s.emplace(x, y);
    center.x += x;
    center.y += y;
  }
  center.x /= ld(n);
  center.y /= ld(n);
  s.erase(center);
  while (true) {
    int found = 0;
    for (point p : s) {
      point q = {center.x + center.x - p.x, center.y + center.y - p.y};
      if (s.find(q) != s.end()) {
        found = 1;
        s.erase(p);
        s.erase(q);
        break;
      }
    }
    if (not found) {
      break;
    }
  }
  int ans = 0;
  int sz = s.size();
  if (sz < 3) {
    puts("-1");
    return 0;
  }
  // cout << sz << endl;
  point pivot = *s.begin();
  // print(pivot);
  // print(center);
  for (point p : s) {
    // cout << "-------------------------\n";
    // print(p);
    point mid = {0.5 * (pivot.x + p.x), 0.5 * (pivot.y + p.y)};
    ld a = center.y - mid.y, b = mid.x - center.x, c = center.x * mid.y - center.y * mid.x;
    // cout << a << " " << b << " " << c << endl;
    ld sq = hypot(a, b);
    vector <ld> dist;
    for (point q : s) {
      dist.push_back((a * q.x + b * q.y + c) / sq);
    }
    sort(dist.begin(), dist.end());
    int works = 1;
    for (int i = 0; i + i < sz; ++i) {
      if (not num_eq(dist[i] + dist[sz - 1 - i], 0)) {
        works = 0;
        break;
      }
    }
    if (!works) continue;
    // cout << "yo\n";
    for (int i = 1; i <= ans; ++i) {
      ld constant;
      if (not num_eq(a, 0)) {
        constant = l[i].a / a;
      } else {
        constant = l[i].b / b;
      }
      if (num_eq(l[i].a, a * constant) and num_eq(l[i].b, b * constant) and num_eq(l[i].c, c * constant)) {
        works = 0;
        break;
      }
    }
    if (!works) continue;
    ++ans;
    l[ans].a = a, l[ans].b = b, l[ans].c = c;
  }
  printf("%d\n", ans);
  return 0;
}