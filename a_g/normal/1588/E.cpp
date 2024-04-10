#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const double PI = acos(-1);
int x[N], y[N];
bool good[N][N];
double dists[N][N];
double angles[N][N];
int n, R;

pair<double, double> intersect(pair<double, double> i1, pair<double, double> i2) {
  if (i1 == make_pair(-PI, PI)) return i2;
  for (int i = -1; i < 2; i++) {
    if (i2.second + 2*i*PI < i1.first || i1.second < i2.first + 2*i*PI) continue;
    return make_pair(max(i1.first, i2.first + 2*i*PI), min(i1.second, i2.second + 2*i*PI));
  }
  return {-100, -100};
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> R;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      dists[i][j] = sqrt(1LL * (x[j]-x[i]) * (x[j]-x[i]) + 1LL * (y[j] - y[i]) * (y[j] - y[i]));
      angles[i][j] = atan2(y[j]-y[i], x[j]-x[i]);
    }
  }

  for (int i = 0; i < n; i++) {
    pair<double, double> good_interval = {-PI, PI};
    for (int j = 0; j < n; j++) {
      if (dists[i][j] <= R) continue;
      double theta = asin(R/dists[i][j]);
      good_interval = intersect(good_interval, make_pair(angles[i][j]-theta, angles[i][j]+theta));
    }
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      for (int k = -1; k < 2; k++) {
        double theta = angles[i][j] + 2 * k * PI;
        if (good_interval.first <= theta && theta <= good_interval.second) {
          good[i][j] = 1;
          break;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (good[i][j] && good[j][i]) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}