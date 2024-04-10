#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array <int, 3> point;

point vertex[8];

void load() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      scanf("%d", &vertex[i][j]);
    sort(vertex[i].begin(), vertex[i].end());
  }
}

point operator -(point p, point q) {
  for (int i = 0; i < 3; i++)
    p[i] -= q[i];
  return p;
}

ll operator *(point p, point q) {
  ll res = 0;
  for (int i = 0; i < 3; i++)
    res += (ll)p[i] * q[i];
  return res;
}

ll dist_sqr(point p, point q) {
  return (p - q) * (p - q);
}

bool bad(point a, point b, point c) {
  ll d = a * a;
  return !d || a * b || b * c || c * a || b * b != d || c * c != d;
}

bool is_cube() {
  vector <point> other(vertex + 1, vertex + 8);
  sort(other.begin(), other.end(), [&](point p, point q) { return dist_sqr(p, vertex[0]) < dist_sqr(q, vertex[0]); });
  for (int i = 0; i < 6; i++) {
    auto check = [&]() {
      vector <point> tmp(8);
      tmp[0] = vertex[0];
      tmp[7] = other.back();
      for (int j = 0; j < 3; j++) {
        tmp[1 << j] = other[j];
        tmp[1 << j ^ 7] = other[j + 3];
      }
      for (int j = 0; j < 8; j++) {
        vector <point> adj(3);
        for (int k = 0; k < 3; k++)
          adj[k] = tmp[j ^ 1 << k] - tmp[j];
        if (bad(adj[0], adj[1], adj[2]))
          return false;
      }
      return true;
    };
    if (check())
      return true;
    next_permutation(other.begin(), other.begin() + 3);
  }
  return false;
}

bool go(int pos) {
  if (pos == 8)
    return is_cube();
  for (int i = 0; i < 6; i++) {
    if (go(pos + 1))
      return true;
    next_permutation(vertex[pos].begin(), vertex[pos].end());
  }
  return false;
}

void solve() {
  if (!go(1)) {
    puts("NO");
    return;
  }
  puts("YES");
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 3; j++)
      printf("%d ", vertex[i][j]);
    puts("");
  }
}

int main() {
  load();
  solve();
  return 0;
}