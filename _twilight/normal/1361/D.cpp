#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int N = 5e5 + 5;

typedef class Point {
  public:
    int x, y;

    void read() {
      scanf("%d%d", &x, &y);
    }
    int where() const {
      return y < 0 || (x < 0 && y == 0);
    }
    ld length();
} Point;

ll cross(Point a, Point b) {
  return 1ll * a.x * b.y - 1ll * a.y * b.x;
}
ll dot(Point a, Point b) {
  return 1ll * a.x * b.x + 1ll * a.y * b.y;
}

ld Point::length() {
  return sqrt((ld) dot(*this, *this));
}

int n, m;
Point P[N];

vector<ld> vdif;

void solve(int L, int R) {
  vector<ld> dis;
  for (int i = L; i <= R; i++) {
    dis.push_back(P[i].length());
  } 
  sort(dis.begin(), dis.end(), greater<ld>());
//  cerr << "working for [" << L << ", " << R << "]: "; 
//  for (auto x : dis) {
//    cerr << x << " ";
//  }
//  cerr << '\n';
  int len = R - L + 1;
  int l = 0, r = len - 1;
  ld sdis = 0;
  for (int i = 0; i < len; i++) {
    if (m - 2 * i - 1 >= 0) {
      vdif.push_back((m - 2 * i - 1) * dis[l++]);  
    } else {
      vdif.push_back(-l * dis[r] - 2 * sdis + (m - l - 1) * dis[r]);
      sdis += dis[r];
      r--;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    P[i].read();
    if (!P[i].x && !P[i].y) {
      i--, n--;
      continue;
    }
  }
  sort(P + 1, P + n + 1, [&] (Point a, Point b) -> bool {
        return (a.where() ^ b.where()) ? (a.where() < b.where()) : cross(a, b) < 0;
      });
  for (int i = 0, j = 0; i <= n; i = j) {
    for (j = i + 1; j <= n && cross(P[j], P[j - 1]) == 0 && dot(P[j], P[j - 1]) >= 0; j++);
    solve(i, j - 1);
  }
  sort(vdif.begin(), vdif.end(), greater<ld>());
  ld ans = accumulate(vdif.begin(), vdif.begin() + m, 0.0);
  printf("%.5lf\n", (double) ans);
  return 0;
}