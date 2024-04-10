#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;
using ld = long double;

int const nmax = 2000;
ll const inf = 1000000000000000000;
int const modulo = 1000000007;

ld const eps = 0.000000001;
struct Edge{
  int x, y, cost;
};
ll dp[5 + nmax], dp2[5 + nmax];
int suff[5 + nmax];

struct Line{
  int a;
  ll b;
  ll eval(int x) {
    return 1LL * x * a + b;
  }
  bool operator < (Line const oth) {
    if(a != oth.a)
      return a < oth.a;
    else
      return b < oth.b;
  }
};

ld intersect(Line f1, Line f2) {
  assert(f1.a != f2.a);
  return (((ld)(f2.b)) - f1.b) / (f1.a - f2.a);
}

int gauss(int l, int r) {
  return 1LL * (l + r) * (r - l + 1) / 2 % modulo;
}

ll evalrange(Line f, int l, int r) {
  if(r < l)
    return 0;
  return (1LL * gauss(l, r) * f.a + 1LL * f.b % modulo * (r - l + 1)) % modulo;
}

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<Edge> edges;

  for(int i = 1; i <= m; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    edges.push_back({x, y, cost});
    suff[x] = std::max(suff[x], cost);
    suff[y] = std::max(suff[y], cost);
  }

  for(int i = 1;i <= n; i++)
    dp2[i] = dp[i] = -inf;
  dp[1] = 0;
  
  int result = 0;
  
  for(int i = 1; i <= nmax * 3; i++) {
    for(int j = 0; j < edges.size(); j++) {
      int x = edges[j].x, y = edges[j].y, cost = edges[j].cost;
      dp2[x] = std::max(dp2[x], dp[y] + cost);
      dp2[y] = std::max(dp2[y], dp[x] + cost);
    }
    for(int j = 1; j <= n; j++) {
      dp[j] = dp2[j];
      dp2[j] = -inf;
    }
    ll smax = 0;
    for(int j = 1; j <= n; j++)
      smax = std::max(smax, dp[j]);
    if(i <= q) {
      result = (result + smax) % modulo;
    }
  }

  q = std::max(0, q - nmax * 3);
  if(q == 0)
    std::cout << result << '\n';
  else {
    std::vector<Line> temp;
    std::vector<Line> st;
    std::vector<ld> pointst;
    for(int i = 1; i <= n; i++)
      if(dp[i] != -inf)
        temp.push_back({suff[i], dp[i]});
    std::sort(temp.begin(), temp.end());

    for(int i = 0; i < temp.size(); i++) {
      while(0 < st.size() && st.back().a == temp[i].a) {
        st.pop_back();
        if(0 < pointst.size())
          pointst.pop_back();
      }

      while(0 < pointst.size() && intersect(st.back(), temp[i]) <= pointst.back()) {
        st.pop_back();
        pointst.pop_back();
      }
      if(0 == st.size()) {
        st.push_back(temp[i]);
      } else if(1 == st.size()) {
        pointst.push_back(intersect(st.back(), temp[i]));
        st.push_back(temp[i]);
      } else {
        pointst.push_back(intersect(st.back(), temp[i]));
        st.push_back(temp[i]);
      }
    }

    int last = 1;
    
    for(int i = 0; i < st.size(); i++) {
      int lim = q;
      if(i + 1 != st.size()) {
        lim = std::min((ll)q, ll(pointst[i] + eps));
      }

      result = (result + evalrange(st[i], last, lim)) % modulo;
      last = std::max(last, lim + 1);

    }
    std::cout << result << '\n';
  }
  return 0;
}