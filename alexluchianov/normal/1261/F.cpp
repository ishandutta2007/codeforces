#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100;
int const lgmax = 60;
int const modulo = 998244353;

struct Interval{
  ll start;
  int p;
  bool operator < (Interval const &oth) const {
    if(start != oth.start)
      return start < oth.start;
    else
      return oth.p < p;
  }
  bool operator == (Interval const &oth) const{
    return (start == oth.start && p == oth.p);
  }
};

std::vector<Interval> transform(std::pair<ll, ll> aux) {
  std::vector<Interval> sol;
  ll x = aux.first;
  ll y = aux.second;
  for(int h = 0; h <= lgmax; h++)
    if((0 < (x & (1LL << h))) && (x + (1LL << h) <= y)) {
      sol.push_back({x, h});
      x += (1LL << h);
    }

  for(int h = lgmax; 0 <= h; h--)
    if((x + (1LL << h) - 1) <= y) {
      sol.push_back({x, h});
      x += (1LL << h);
    }
  return sol;
}

Interval combine(Interval a, Interval b) {
  int pmax = std::max(a.p, b.p);
  ll result = ((a.start>>pmax) ^ (b.start>>pmax))<<pmax;
  return {result, pmax};
}

int main() {
  int n, m;
  std::cin >> n;
  std::vector<std::pair<ll, ll>> v1, v2;
  for(int i = 1; i <= n; i++) {
    ll x, y;
    std::cin >> x >> y;
    v1.push_back({x, y});
    std::vector<Interval> spart = transform({x, y});
  }
  std::cin >> m;
  for(int i = 1;i <= m; i++) {
    ll x, y;
    std::cin >> x >> y;
    v2.push_back({x, y});
    std::vector<Interval> spart = transform({x, y});
  }
  std::vector<Interval> sol;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      std::vector<Interval> s1, s2;
      s1 = transform(v1[i]);
      s2 = transform(v2[j]);
      std::vector<Interval> small;

      for(int h = 0; h < s1.size(); h++) {
        Interval base = s1[h];
        int p = base.p;

        ll bit = (1LL << p);
        ll x = (v2[j].first>>p)<<p;
        ll y = (v2[j].second>>p)<<p;

        sol.push_back(combine(base, {x, 0}));
        sol.push_back(combine(base, {y, 0}));

        if(x + bit <= y) {
          sol.push_back(combine(base, {x + bit, 0}));
          sol.push_back(combine(base, {y - bit, 0}));
        }
      }

      for(int h = 0; h < s2.size(); h++) {
        Interval base = s2[h];
        int p = base.p;
        ll bit = (1LL << p);
        ll x = (v1[i].first>>p)<<p;
        ll y = (v1[i].second>>p)<<p;

        sol.push_back(combine(base, {x, 0}));
        sol.push_back(combine(base, {y, 0}));

        if(x + bit <= y) {
          sol.push_back(combine(base, {x + bit, 0}));
          sol.push_back(combine(base, {y - bit, 0}));
        }
      }

      /*
         for(int h = 0; h < small.size(); h++)
         sol.push_back(small[h]);
       */

    }

  std::sort(sol.begin(), sol.end());

  ll last = 0;
  ll result = 0;
  for(int i = 0; i < sol.size(); i++) {
    if(last <= sol[i].start) {
      ll _count = (1LL << (sol[i].p));
      result = (result + 1LL * sol[i].start % modulo * (_count % modulo) % modulo + ((_count - 1) % modulo) * ((_count / 2) % modulo)) % modulo;
      last = sol[i].start + (1LL<<sol[i].p);
    }
  }
  std::cout << result;
  return 0;
}