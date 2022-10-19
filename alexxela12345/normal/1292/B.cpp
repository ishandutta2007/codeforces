#ifndef LOCAL
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define max(a, b) (a < b) ? b : a

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (auto &el : arr) {
    in >> el;
  }
  return in;
}

template<typename T1, typename T2> 
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
  for (auto &el : arr) {
    out << el;
  }
  return out;
}

template<typename T1, typename T2> 
ostream &operator>>(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

int dist(pair<int, int> a, pair<int, int> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax>> ay >> bx >> by;
  int xs, ys;
  cin >> xs >> ys;
  int t;
  cin >> t;
  vector<pair<int, int>> points;
  while (1) {
    points.push_back({x0, y0});
    if ((long double) x0 * ax + bx > 1e17) {
      break;
    }
    if ((long double) y0 * ay + by > 1e17) {
      break;
    }
    x0 = ax * x0 + bx;
    y0 = ay * y0 + by;
  }
  int max_ans = 0;
  int n = points.size();
  for (int i = 0; i < n; i++) {
    if (dist({xs, ys}, points[i]) <= t) {
      int cur_t = t - dist({xs, ys}, points[i]);
      int ind = i;
      int cur_ans = 1;
      if (1) {
        int cur_t2 = cur_t;
        int cur_ans2 = cur_ans;
        if (i + 1 != n && dist(points[ind], points[i + 1]) <= cur_t2) {
          cur_t2 -= dist(points[ind], points[i + 1]);
          cur_ans2++;
          int ind2 = i + 1;
          while (ind2 + 1 < n) {
            if (dist(points[ind2], points[ind2 + 1]) <= cur_t2) {
              cur_t2 -= dist(points[ind2], points[ind2 + 1]);
              cur_ans2++;
              ind2++;
            } else {
              break;
            }
          }
          max_ans = max(max_ans, cur_ans2);
        }
      }
      while (ind) {
        int cur_t2 = cur_t;
        int cur_ans2 = cur_ans;
        if (i + 1 != n && dist(points[ind], points[i + 1]) <= cur_t2) {
          cur_t2 -= dist(points[ind], points[i + 1]);
          cur_ans2++;
          int ind2 = i + 1;
          while (ind2 + 1 < n) {
            if (dist(points[ind2], points[ind2 + 1]) <= cur_t2) {
              cur_t2 -= dist(points[ind2], points[ind2 + 1]);
              cur_ans2++;
              ind2++;
            } else {
              break;
            }
          }
          max_ans = max(max_ans, cur_ans2);
        }
        if (dist(points[ind], points[ind - 1]) <= cur_t) {
          cur_t -= dist(points[ind], points[ind - 1]);
          cur_ans++;
          ind--;
        } else {
          break;
        }
      }
      max_ans = max(max_ans, cur_ans);
    }
  }
  cout << max_ans << endl;
}