#include <iostream>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b)  (a))

int const nmax = 3000;
int const lgmax = 20;

std::vector<std::vector<ll>> v;
std::vector<std::pair<int, ll>> aint[1 + nmax * 4];

void update(int node, int from, int to, int x, int y, std::pair<int, ll> e) {
  if(x == from && to == y)
    aint[node].push_back(e);
  else {
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x, std::min(y, mid), e);
    if(mid + 1 <= y)
      update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, e);
  }
}

ll dp[1 + lgmax][1 + nmax];

ll solve(int node, int from, int to, int target, int level) {
  for(int i = 0;i <= target; i++)
    dp[level][i] = dp[level - 1][i];

  for(int h = 0; h < aint[node].size(); h++) {
    std::pair<int, ll> el = aint[node][h];
    for(int i = target; el.first <= i; i--)
      dp[level][i] = std::max(dp[level][i], dp[level][i - el.first] + el.second);
  }
  if(from < to) {
    int mid = (from + to) / 2;
    return std::max(solve(node * 2, from, mid, target, level + 1), 
               solve(node * 2 + 1, mid + 1, to, target, level + 1));
  } else {
    ll result = dp[level][target];
    ll bonus = 0;
    for(int i = 1;i <= std::min(target, (int)v[from].size() - 1); i++) {
      bonus += v[from][i];
      result = std::max(result, dp[level][target - i] + bonus);
    }
    return result;
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  v.resize(1 + n);
  for(int i = 1;i <= n; i++) {
    int m;
    std::cin >> m;
    std::vector<ll> aux(m + 1);
    for(int i = 1;i <= m; i++) {
      std::cin >> aux[i];
      aux[0] += aux[i];
    }
    v[i] = aux; 
  }
  for(int i = 1;i <= n; i++) {
    if(1 < i)
      update(1, 1, n, 1, i - 1, {v[i].size() - 1, v[i][0]});
    if(i < n)
      update(1, 1, n, i + 1, n, {v[i].size() - 1, v[i][0]});
  }
  std::cout << solve(1, 1, n, k, 1);
  return 0;
}