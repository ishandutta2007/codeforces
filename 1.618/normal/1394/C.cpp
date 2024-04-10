// just a time test

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define D(v) cerr << #v << "= " << (v) << ", ";
#define E cerr << endl;
#else
#define D(v)
#define E
#endif
#define F first
#define S second
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int x[n] {}, y[n] {};
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (char c : s) {
      if (c == 'B') x[i]++;
      else y[i]++;
    }
  }
  int mi_x = 1e9, ma_x = -1e9;
  int mi_y = 1e9, ma_y = -1e9;
  int mi_d = 1e9, ma_d = -1e9;
  for (int i = 0; i < n; ++i) {
    mi_x = min(mi_x, x[i]);
    ma_x = max(ma_x, x[i]);
    mi_y = min(mi_y, y[i]);
    ma_y = max(ma_y, y[i]);
    int d = x[i]-y[i];
    mi_d = min(mi_d, d);
    ma_d = max(ma_d, d);
  }
  int t = max({0,
    ma_x-mi_x,
    ma_y-mi_y,
    ma_d-mi_d
  });
  t = t/2+t%2;
  int Ax, Ay;
  if (mi_x-mi_y < ma_d-t) {
    int dt = max(0, (ma_d-t) - (mi_x+t - ma_y+t));
    dt = dt/3+!!(dt%3);
    t += dt;
    Ax = mi_x+t;
    Ay = min(mi_y+t, Ax-ma_d+t);
  } else if (mi_x-mi_y > mi_d+t) {
    int dt = max(0, (ma_x-t - mi_y-t) - (mi_d+t));
    dt = dt/3+!!(dt%3);
    t += dt;
    Ay = mi_y+t;
    Ax = min(mi_x+t, Ay+mi_d+t);
  } else {
    Ax = mi_x+t; Ay = mi_y+t;
  }
  cout << t << endl;
  for (int i = 0; i < Ax; ++i) cout << 'B';
  for (int i = 0; i < Ay; ++i) cout << 'N';
  cout << endl;
}