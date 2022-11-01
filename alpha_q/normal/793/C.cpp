#include <bits/stdc++.h> 

using namespace std;

typedef long double ld;

const int N = 100010;
const ld EPS = 1e-14;
const ld INF = 1e19;

int n;
ld ux, uy, dx, dy;
ld rx[N], ry[N];
ld vx[N], vy[N];
int flag = 1;
ld l[N], r[N];

bool eq (ld a, ld b) {
  return fabs(a - b) < EPS;
}

bool within (ld x, ld y) {
  return x > ux and x < dx and y > uy and y < dy;
}

int main (int argc, char const *argv[]) {
  scanf("%d", &n);
  scanf("%Lf %Lf %Lf %Lf", &ux, &uy, &dx, &dy);
  if (ux > dx) swap(ux, dx);
  if (uy > dy) swap(uy, dy);
  // cout << ux << " " << uy << " " << dx << " " << dy << endl;
  ld ansl = -INF;
  for (int i = 1; i <= n; ++i) {
    scanf("%Lf %Lf %Lf %Lf", rx + i, ry + i, vx + i, vy + i);
    if (eq(vx[i], 0) and eq(vy[i], 0)) {
      if (within(rx[i], ry[i])) {
        l[i] = 0, r[i] = INF;
      } else {
        flag = 0;
  // cout << "yo1\n";
      }
    }
    else if (eq(vx[i], 0)) {
      ld lt = uy - ry[i], rt = dy - ry[i];
      if (vy[i] < 0) swap(lt, rt);
      lt /= vy[i], rt /= vy[i];
      if (ux < rx[i] and rx[i] < dx) {
        l[i] = lt, r[i] = rt;
      } else {
        flag = 0;
  // cout << "yo2\n";
      }
    } 
    else if (eq(vy[i], 0)) {
      ld lt = ux - rx[i], rt = dx - rx[i];
      if (vx[i] < 0) swap(lt, rt);
      lt /= vx[i], rt /= vx[i];
      if (uy < ry[i] and ry[i] < dy) {
        l[i] = lt, r[i] = rt;
      } else {
        flag = 0;
  // cout << "yo3\n";
      }
    } 
    else {
      ld lt = ux - rx[i], rt = dx - rx[i];
      if (vx[i] < 0) swap(lt, rt);
      lt /= vx[i], rt /= vx[i];
      l[i] = lt, r[i] = rt;
      lt = uy - ry[i], rt = dy - ry[i];
      if (vy[i] < 0) swap(lt, rt);
      lt /= vy[i], rt /= vy[i];
      l[i] = max(l[i], lt), r[i] = min(r[i], rt);
    }
    // cout << i << " " << l[i] << " " << r[i] << endl;
    l[i] = max((ld) 0, l[i]);
    if (l[i] > r[i]) {
      flag = 0;
  // cout << "yo4\n";
    }
    ansl = max(ansl, l[i]);
  }
  // cout << "yo\n";
  if (flag == 0) {
    puts("-1");
    return 0;
  }
  // cout << "yo\n";
  // cout << ansl << endl;
  for (int i = 1; i <= n; ++i) {
    if (ansl >= r[i]) {
      puts("-1");
      return 0;
    }
  }
  // ansl += EPS;
  printf("%0.16f\n", (double) ansl);
  return 0;
}