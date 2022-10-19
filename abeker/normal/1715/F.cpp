#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> point;

const ld eps = 1e-10;

void output(point p) {
  printf("%.15Lf %.15Lf\n", p.first, p.second);
}

ld ask(const vector <point> &poly) {
  printf("? %d\n", poly.size());
  for (auto it : poly)
    output(it);
  fflush(stdout);
  ld ans;
  scanf("%Lf", &ans);
  return ans;
}

ld my_round(ld val) {
  ld res = floor(val);
  if (val > res + eps)
    res = ceil(val);
  return res;
}

ld get_coord(const vector <point> &poly) {
  ld area = ask(poly);
  return area + my_round(100 * area) - 1;
}

ld calc(ld val) {
  return val + (val + 1) / 100;
}

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  vector <point> comb;
  for (int i = 0; i < N; i++) {
    comb.emplace_back(i, 0);
    comb.emplace_back(i, M);
    comb.emplace_back(calc(i), M);
    comb.emplace_back(calc(i), 0);
  }
  comb.emplace_back(calc(N - 1), -1);
  comb.emplace_back(0, -1);
  ld tmp = get_coord(comb);
  ld x = tmp - ask({{0, 0}, {0, M}, {tmp, M}, {tmp, 0}});
  comb.clear();
  for (int i = 0; i < M; i++) {
    comb.emplace_back(0, i);
    comb.emplace_back(N, i);
    comb.emplace_back(N, calc(i));
    comb.emplace_back(0, calc(i));
  }
  comb.emplace_back(-1, calc(M - 1));
  comb.emplace_back(-1, 0);
  tmp = get_coord(comb);
  ld y = tmp - ask({{0, 0}, {N, 0}, {N, tmp}, {0, tmp}});
  printf("! ");
  output({x, y});
  return 0;
}