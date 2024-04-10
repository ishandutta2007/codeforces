#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 100100;

ld sq(ld x) {
  return x * x;
}

struct Point {
  ll x, y;

  void read() {
    cin >> x >> y;
  }

  Point operator - (Point &to) { 
    return Point {x - to.x, y - to.y};
  }

  ld abs() {
    return sqrt(max<ld>(0, sq(x) + sq(y)));
  }
} A, B, U, p[M];

int n;
ld d[M], da[M], db[M];

ld find(ld *da, ld *db) {
  int mna = 0;
  for (int i = 0; i < n; ++i)
    if (da[mna] > da[i])
      mna = i;
  
  int mnb = 0;
  if (mnb == mna)
    ++mnb;

  for (int i = 0; i < n; ++i)
    if (i != mna && db[mnb] > db[i]) {
      mnb = i;
    }

  ld ans = 0;
  for (int i = 0; i < n; ++i)
    ans += 2 * d[i];

  ans += da[mna];
  if (mnb < n && db[mnb] < 0)
    ans += db[mnb];

  return ans;
}

void read() {
  A.read();
  B.read();
  U.read();
  cin >> n;
  for (int i = 0; i < n; ++i)
    p[i].read();
}

void kill() {
  for (int i = 0; i < n; ++i) {
    d[i] = (U - p[i]).abs();
    da[i] = (A - p[i]).abs();
    db[i] = (B - p[i]).abs();
    da[i] -= d[i];
    db[i] -= d[i];
  }

  ld ans = min(find(da, db), find(db, da));

  cout << ans << endl;
}


int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}