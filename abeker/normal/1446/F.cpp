#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pdd;

const int MAXN = 1e5 + 5;
const ld eps = 1e-5;

class Tournament {
  int offset;
  vector <int> cnt;
public:
  Tournament(int n) {
    for (offset = 1; offset < n; offset *= 2);
    cnt.resize(2 * offset);
  }
  void update(int x) {
    for (x += offset; x; x /= 2) 
      cnt[x]++;
  }
  ll query(int x, int lo, int hi, int from, int to) const {
    if (lo >= to || hi <= from)
      return 0;
    if (lo >= from && hi <= to) 
      return cnt[x];
    int mid = (lo + hi) / 2;  
    return query(2 * x, lo, mid, from, to) + query(2 * x + 1, mid, hi, from, to);
  }
  int query(int from, int to) const {
    return query(1, 0, offset, from, to);
  }
};

ll K;
int N;
vector <pdd> pts;
pdd line[MAXN];

void load() {
  scanf("%d%lld", &N, &K);
  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x || y)
      pts.push_back({x, y});
    else
      K -= N - 1;
  }
}

ll calc(ld r) {
  vector <ld> all;
  vector <pdd> events;
  auto intersect = [&](ld a, ld b) {
    ld A = a * a + 1;
    ld B = 2 * a * b;
    ld C = b * b - r * r;
    ld D = B * B - 4 * A * C;
    if (D < 0)
      return;
    ld x1 = (-B + sqrt(D)) / (2 * A);
    ld x2 = (-B - sqrt(D)) / (2 * A);
    ld alpha1 = atan2(a * x1 + b, x1);
    ld alpha2 = atan2(a * x2 + b, x2);
    if (alpha1 > alpha2)
      swap(alpha1, alpha2);
    events.push_back({alpha1, alpha2});
    all.push_back(alpha1);
    all.push_back(alpha2);
  };
  for (int i = 0; i < N; i++)
    intersect(line[i].first, line[i].second);
  sort(all.begin(), all.end());
  auto compress = [&](ld &ref) {
    ref = lower_bound(all.begin(), all.end(), ref) - all.begin();
  };
  for (auto &it : events) {
    compress(it.first);
    compress(it.second);
    it.second *= -1;
  }
  ll res = 0;
  sort(events.begin(), events.end());
  Tournament T(all.size());
  for (auto it : events) {
    res += T.query(it.first, -it.second + 1);
    T.update(-it.second);
  }
  return res;
}

ld solve() {
  if (K <= 0)
    return 0;
  N = pts.size();
  K = (ll)N * (N - 1) / 2 - K + 1;
  for (auto &it : pts) {
    complex <ld> tmp(it.first, it.second);
    tmp *= polar((ld)1, eps);
    it = {tmp.real(), tmp.imag()};
  }
  for (int i = 0; i < N; i++) 
    line[i] = {-pts[i].first / pts[i].second, 1 / pts[i].second};
  ld lo = 0, hi = 1e6;
  for (int it = 0; it < 60; it++) {
    ld mid = (lo + hi) / 2;
    if (calc(mid) < K)
      lo = mid;
    else
      hi = mid;
  }
  return 1 / lo;
}

int main() {
  load();
  printf("%.10Lf\n", solve());
  return 0;
}