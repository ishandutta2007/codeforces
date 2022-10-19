#include <bits/stdc++.h>
using namespace std;

// Angle-Restricted tours in the plane, Fekete and Woeginger
struct pt {
  int x, y, ind;
};

long long sq(int x) {
  return 1LL*x*x;
}

long long dist(pt& a, pt&b) {
  return sq(a.x-b.x)+sq(a.y-b.y);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pt> a(n);
  for (pt& p: a) cin >> p.x >> p.y;
  vector<bool> taken(n);
  int cur = 0;
  int remaining = n-1;
  while (remaining--) {
    cout << cur+1 << ' ';
    taken[cur] = 1;
    int best = -1;
    long long d = -1;
    for (int i = 0; i < n; i++) {
      if (!taken[i]) {
        if (dist(a[i], a[cur]) > d) {
          d = dist(a[i], a[cur]);
          best = i;
        }
      }
    }
    cur = best;
  }
  cout << cur+1 << '\n';
}