#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

typedef long long ll;

struct Vec {
  double x, y;

  Vec () {
    x = 0;
    y = 0;
  }

  Vec (double _x, double _y) {
    x = _x;
    y = _y;
  }
};

Vec operator+ (Vec p, Vec q) {
  p.x += q.x;
  p.y += q.y;
  return p;
}

Vec operator* (double k, Vec u) {
  u.x *= k;
  u.y *= k;
  return u;
}

Vec operator- (Vec u) {
  return (-1) * u;
}

Vec operator- (Vec u, Vec v) {
  return u + (-v);
}

double dot (Vec u, Vec v) {
  return u.x * v.x + u.y * v.y;
}

double cross (Vec u, Vec v) {
  return u.x * v.y - u.y * v.x;
}

double orient (Vec P, Vec Q, Vec R) {
  return cross(Q - P, R - P);
}

double e_dist (Vec P, Vec Q) {
  return sqrt(dot(Q - P, Q - P));
}

double m_dist (Vec P, Vec Q) {
  return fabs(P.x - Q.x) + fabs(P.y - Q.y);
}

ll a, b, c;
Vec horiz_proj (Vec P) {
  Vec ans = P;
  ans.y = ((double) a * P.x + c) / (-b);
  return ans;
}

Vec vert_proj (Vec P) {
  Vec ans = P;
  ans.x = ((double) b * P.y + c) / (-a);
  return ans;
}

int main () {
  cin >> a >> b >> c;
  Vec P, Q;
  cin >> P.x >> P.y >> Q.x >> Q.y;

  double ans = m_dist(P, Q);
  if (a != 0 && b != 0) {
    vector<Vec> Pv = {vert_proj(P), horiz_proj(P)};
    vector<Vec> Qv = {vert_proj(Q), horiz_proj(Q)};
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        ans = min(ans, m_dist(P, Pv[i]) + e_dist(Pv[i], Qv[j]) + m_dist(Qv[j], Q));
      }
    }
  }

  cout << setprecision(12) << ans << endl;
}