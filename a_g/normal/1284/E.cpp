#include <bits/stdc++.h>
using namespace std;

struct pt {
  int x, y;
};

int quadrant(pt a) {
  if (a.y >= 0 && a.x > 0) return 0;
  else if (a.x <= 0 && a.y > 0) return 1;
  else if (a.y <= 0 && a.x < 0) return 2;
  else return 3;
}

bool operator < (pt& a, pt& b) {
  // for the purposes we need it for, a and b are nonzero and at different angles
  int qa = quadrant(a);
  int qb = quadrant(b);
  if (qa != qb) return qa < qb;
  return 1LL*a.x*b.y > 1LL*b.x*a.y;
}

bool within_half_rotation(pt& a, pt& b) {
  return (1LL*a.x*b.y >= 1LL*b.x*a.y);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pt> pts(n);
  for (pt& p: pts) cin >> p.x >> p.y;

  // for each point, calculate how many triangles enclose it
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    vector<pt> rel;
    rel.reserve(n-1);
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      rel.emplace_back(pt{pts[j].x-pts[i].x, pts[j].y-pts[i].y});
    }
    sort(rel.begin(), rel.end());
    long long triangles = 1LL*(n-1)*(n-2)*(n-3)/6;
    int r = 0;
    for (int l = 0; l < n-1; l++) {
      while (within_half_rotation(rel[l], rel[r])) {
        r++;
        if (r == n-1) r = 0;
        if (r == l) break;
      }
      int k = r-l-1;
      if (k < 0) k += n-1;
      triangles -= k*(k-1)/2;
      if (r == l) r++;
      if (r == n-1) r = 0;
    }
    ans += triangles;
  }
  ans = (n-4)*ans/2;
  cout << ans << '\n';
}