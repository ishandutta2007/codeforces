#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef pair<double, double> pt;
#define x first
#define y second

pt operator+ (pt p, pt q) {
  return {p.x + q.x, p.y + q.y};
}

pt operator- (pt p) {
  return {-p.x, -p.y};
}

pt operator- (pt p, pt q) {
  return p + (-q);
}

double dot (pt p, pt q) {
  return p.x * q.x + p.y * q.y;
}

double cross (pt p, pt q) {
  return p.x * q.y - p.y * q.x;
}

double norm (pt p) {
  return sqrt(dot(p, p));
}

ostream &operator<< (ostream &out, pt p) {
  out << "(" << p.x << " " << p.y << ")";
  return out;
}

double proc (pt a, pt b, pt c) {
  // b is the middle vertex
  double ans = abs(cross(b - a, c - a)) / (2 * norm(c - a));
  return ans;
}

const int MAX_N = 1e3 + 5;

pt arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
  }

  double ans = 1e18;
  for (int i = 0; i < n; i++) {
    ans = min(ans, proc(arr[i], arr[(i + 1) % n], arr[(i + 2) % n]));
  }
  cout << fixed << setprecision(12) << ans << endl;
}