#include <bits/stdc++.h>
using namespace std;

// source: flashmt (https://codeforces.com/problemset/submission/1190/58870568)

const int maxn = 1e5+5;
const int lvl = 18;
const double PI = acos(-1);
int n, m;
int x[maxn];
int y[maxn];
int up[2*maxn][lvl];
double dists[maxn];
double angles[maxn];

bool check(double dist) {
  vector<pair<double, double>> intervals;
  for (int i = 0; i < n; i++) {
    double theta = acos(dist/dists[i]);
    double l = angles[i] - theta;
    double r = angles[i] + theta;
    if (l < 0) {
      l += 2*PI;
      r += 2*PI;
    }
    intervals.push_back({l, r});
    intervals.push_back({l+2*PI, r+2*PI});
  }
  sort(intervals.begin(), intervals.end());

  for (int i = 2*n-2; i >= 0; i--) {
    intervals[i].second = min(intervals[i].second, intervals[i+1].second);
  }

  for (int i = 0; i < 2*n; i++) {
    up[i][0] = lower_bound(intervals.begin(), intervals.end(),
        make_pair(intervals[i].second, (double)(50))) - intervals.begin();
  }
  up[2*n][0] = 2*n;

  for (int j = 1; j < lvl; j++) {
    for (int i = 0; i <= 2*n; i++) {
      up[i][j] = up[up[i][j-1]][j-1];
    }
  }

  for (int i = 0; i < n; i++) {
    int cur = i;
    for (int j = lvl-1; j >= 0; j--) {
      if ((m>>j)&1) {
        cur = up[cur][j];
      }
      if (cur - i >= n) return 1;
    }
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    dists[i] = sqrt((double)x[i]*x[i]+(double)y[i]*y[i]);
    if (dists[i] != 0) angles[i] = atan2(y[i], x[i]);
  }

  double low = 0;
  double high = *min_element(dists, dists+n);
  while (high - low > 1e-9) {
    double mid = (low+high)/2;
    if (check(mid)) low = mid;
    else high = mid;
  }
  cout << (low+high)/2 << endl;
}