#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

struct pt {
  int x, y;
};

pt operator - (pt& a, pt& b) {
  return pt{a.x-b.x, a.y-b.y};
}

pt operator + (pt& a, pt& b) {
  return pt{a.x+b.x, a.y+b.y};
}

long long cross(pt a, pt b) {
  return 1LL*a.x*b.y-1LL*a.y*b.x;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pt> poly(n);
  for (int i = 0; i < n; i++) {
    cin >> poly[i].x >> poly[i].y;
  }
  vector<pt> psum(n+1); // psum[i] = poly[0]+...+poly[i-1]
  for (int i = 0; i < n; i++) {
    psum[i+1] = psum[i] + poly[i];
    psum[i+1].x %= MOD;
    psum[i+1].y %= MOD;
  }
  vector<int> crosssum(n+1), weighted_crosssum(n+1);
  for (int i = 0; i < n; i++) {
    int z = cross(poly[(i+1)%n], poly[i])%MOD;
    crosssum[i+1] = (crosssum[i]+z)%MOD;
    weighted_crosssum[i+1] = (weighted_crosssum[i]+1LL*i*z)%MOD;
  }

  long long tot = 0;
  for (int i = 1; i+1 < n; i++) {
    tot += cross(poly[i+1]-poly[0], poly[i]-poly[0]);
  }

  int ans = 0; // sum of smaller areas across all splits
  int r = 0;
  long long cur = 0;
  int halfsplits = 0;
  for (int i = 0; i < n; i++) {
    while (cur+cross(poly[(r+1)%n]-poly[i], poly[r]-poly[i]) <= tot/2) {
      cur += cross(poly[(r+1)%n]-poly[i], poly[r]-poly[i]);
      r = (r+1)%n;
    }
    if (cur == tot-cur) halfsplits++;
    assert(r != i);

    long long areasum = 0;
    if (r > i) {
      areasum = cross(poly[i], psum[r+1]-psum[i]) +
        1LL*r*(crosssum[r]-crosssum[i])
        -(weighted_crosssum[r]-weighted_crosssum[i]);
    }
    else {
      areasum = cross(poly[i], psum[n]-psum[i])+cross(poly[i], psum[r+1]) +
        1LL*(r+n)*(crosssum[n]-crosssum[i])+1LL*r*crosssum[r]
        -(0LL+weighted_crosssum[n]-weighted_crosssum[i]+weighted_crosssum[r]);
    }

    ans = (ans+areasum)%MOD;
    cur -= cross(poly[(i+1)%n]-poly[r], poly[i]-poly[r]);
  }
  halfsplits /= 2;
  tot %= MOD;
  ans = (ans-halfsplits*tot/2)%MOD;
  ans = ((1LL*n*(n-3)/2 % MOD) * tot - 2*ans) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
}