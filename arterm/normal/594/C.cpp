#include <bits/stdc++.h>

using namespace std;

#define long long long

const int M = 100100;

int n, k;
long x[M], y[M];
int p[4][M];

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    x[i] = xa + xb;
    y[i] = ya + yb;
  }
}

bool cmpxl(int i, int j) {
  return x[i] < x[j];
}

bool cmpxr(int i, int j) {
  return x[i] > x[j];
}

bool cmpyl(int i, int j) {
  return y[i] < y[j];
}

bool cmpyr(int i, int j) {
  return y[i] > y[j];
}

void add(set<int> &s, int *a, int *b) {
  while (a != b) {
    s.insert(*a);
    ++a;
  }
}

long round(long x) {
  return (max(x, 1ll) + 1) / 2;
}

long sz(int xl, int xr, int yl, int yr) {
  long xlen = x[p[0][n - xr - 1]] - x[p[0][xl]];
  long ylen = y[p[2][n - yr - 1]] - y[p[2][yl]];
  return round(xlen) *
         round(ylen);
}

void kill() {
  for (int j = 0; j < 4; ++j)
    for (int i = 0; i < n; ++i)
      p[j][i] = i;

  sort(p[0], p[0] + n, cmpxl);
  sort(p[1], p[1] + n, cmpxr);
  sort(p[2], p[2] + n, cmpyl);
  sort(p[3], p[3] + n, cmpyr);
  
  long ans = sz(0, 0, 0, 0);

  for (int xl = 0; xl <= k; ++xl)
    for (int xr = 0; xl < n - xr && xr <= k; ++xr)
      for (int yl = 0; yl <= k; ++yl)
        for (int yr = 0; yl < n - yr && yr <= k; ++yr) {
          set<int> s;
          add(s, p[0], p[0] + xl);
          add(s, p[0] + n - xr, p[0] + n);
          add(s, p[2], p[2] + yl);
          add(s, p[2] + n - yr, p[2] + n);
          if ((int) s.size() <= (int) k) {
            ans = min(ans, sz(xl, xr, yl, yr));
          }
        }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  read();
  kill(); 
  return 0;
}