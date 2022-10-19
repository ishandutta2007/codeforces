#include <bits/stdc++.h>
using namespace std;

// Reformulate problem as: find line l such that projection from P to l is close
// to origin as possible (answer is half of what it was before).
//
// Check if distance d is valid: for each point X, mark A, B on circle of radius
// d at origin such that PAX and PBX are right. Look for two intervals which
// intersect but neither contains the other.

const int maxn = 1e5+2;
const double PI = acos(-1);
int x[maxn];
int y[maxn];
// measured from midpoint of PX
double dist_origin[maxn];
double dist_p[maxn];
double angles[maxn];
int n, a;

double sqr(double x) {
  return x*x;
}

bool check (double d) {
  vector<pair<double, double>> intervals;
  vector<pair<double, int>> events;
  for (int i = 0; i < n; i++) {
    // LoC
    double r = (sqr(d)+sqr(dist_origin[i])-sqr(dist_p[i])) / (2*d*dist_origin[i]);
    if (r >= 1 || r <= -1) continue;
    double theta = acos(r);

    double L = angles[i] - theta;
    double R = angles[i] + theta;
    // it's okay to complement an interval
    if (L < 0) L += 2*PI;
    if (R < 0) R += 2*PI;
    if (L > R) swap(L, R);
    //assert(0 <= L && L < 2*PI && 0 <= R && R < 2*PI && L < R);
    events.push_back({L, i+1});
    events.push_back({R, -(i+1)});
  }
  sort(events.begin(), events.end());
  vector<int> cur;
  for (pair<double, int> event: events) {
    int j = event.second;
    if (j < 0) {
      assert(cur.size());
      if (cur.back()+j) return 1;
      cur.pop_back();
    }
    else {
      cur.push_back(j);
    }
  }

  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> a;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    double mx = (double)(x[i]-a)/2;
    double my = (double)y[i]/2;
    dist_origin[i] = sqrt(sqr(mx)+sqr(my));
    dist_p[i] = sqrt(sqr(mx+a)+sqr(my));
    angles[i] = atan2(my, mx);
  }
  double low = 0;
  double high = a;
  while (high - low > 1e-7) {
    double mid = (low+high)/2;
    if (check(mid)) high = mid;
    else low = mid;
  }
  cout << low+high << endl;
}