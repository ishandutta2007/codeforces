#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> line;
typedef pair <ld, ld> point;
  
const int MAXN = 2e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ld eps = 1e-6;

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
}

int range_sum(line l, int lo, int hi) {
  return lo > hi ? 0 : mul(hi - lo + 1, add(mul(l.first, mul(add(lo, hi), (MOD + 1) / 2)), l.second));
}

class Envelope {
  vector <point> pts;
  vector <line> lines, env;
public:
  ld eval(line p, ld x) {
    return p.first * x + p.second;
  }
  point intersect(line p, line q) {
    ld x = (ld)(q.second - p.second) / (p.first - q.first);
    return {x, eval(p, x)};
  }
  void add_line(line l) {
    lines.push_back(l);
  }
  void build() {
    sort(lines.begin(), lines.end());
    for (auto it : lines) {
      while (env.size() > 1 && !pts.empty() && eval(it, pts.back().first) + eps > pts.back().second) {
        env.pop_back();
        pts.pop_back();
      }
      if (!env.empty()) {
        if (env.back().first == it.first)
          env.pop_back();
        else
          pts.push_back(intersect(env.back(), it));
      }
      env.push_back(it);
    }
  }
  int get_sum(int lo, int hi) {
    if (env.empty())
      return 0;
    pts.push_back({INF, INF});
    int res = range_sum(env[0], lo, min(hi, (int)floor(pts[0].first)));
    for (int i = 1; i < env.size(); i++)
      res = add(res, range_sum(env[i], max(lo, (int)floor(pts[i - 1].first) + 1), min(hi, (int)floor(pts[i].first))));
    return res;
  }
};

int N, M, Q;
int u[MAXN], v[MAXN], w[MAXN];
int dp[MAXN][MAXN];
ll byEdge[MAXN];
ll maks[MAXN];
Envelope E;

void load() {
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 0; i < M; i++)
    scanf("%d%d%d", u + i, v + i, w + i);  
}

template <typename T> 
void init(T *arr, int l, int r) {
  for (int i = l; i <= r; i++)
    arr[i] = -INF;
}

int solve() {
  for (int i = 0; i < N; i++)
    init(dp[i], !i + 1, N);
  init(maks, 0, N - 1);
  init(byEdge, 0, M - 1);
  
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) {
      byEdge[j] = max(byEdge[j], (ll)max(dp[i][u[j]], dp[i][v[j]]) - w[j] * i);
      maks[i] = max(maks[i], w[j] * i + byEdge[j]);
      dp[i + 1][u[j]] = max(dp[i + 1][u[j]], dp[i][v[j]] + w[j]);
      dp[i + 1][v[j]] = max(dp[i + 1][v[j]], dp[i][u[j]] + w[j]);
    }
  
  for (int i = 0; i < M; i++)
    E.add_line({w[i], byEdge[i]});
  
  E.build();
  
  int sol = E.get_sum(N, Q);
  for (int i = 1; i <= min(N - 1, Q); i++)
    sol = add(sol, maks[i] % MOD);
  
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}