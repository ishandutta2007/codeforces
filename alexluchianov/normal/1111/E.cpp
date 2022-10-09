#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100000;
int const lgmax = 20;
int const kmax = 300;
int const modulo = 1000000007;

int start[5 + nmax], level[5 + nmax], far[1 + lgmax][1 + nmax];
int comb[5 + kmax][5 + kmax], fact[5 + kmax], ptr = 0;

void precompute(int n) {
  for(int h = 1; h < lgmax; h++)
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
  
  fact[0] = 1;
  for(int i = 1;i <= kmax; i++)
    fact[i] = 1LL * fact[i - 1] * i % modulo;

  for(int i = 0; i <= kmax; i++) {
    comb[i][0] = 1;
    for(int j = 1; j <= i; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % modulo;
  }
}

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int getlca(int x, int y) {
  if(level[x] < level[y])
    std::swap(x, y);
  for(int h = lgmax - 1; 0 <= h; h--)
    if(level[y] + (1 << h) <= level[x])
      x = far[h][x];
  if(x == y)
    return x;
  for(int h = lgmax - 1; 0 <= h; h--)
    if(far[h][x] != far[h][y]) {
      x = far[h][x] ;
      y = far[h][y];
    }
  return far[0][x];
}

std::vector<int> ginit[5 + nmax];

void dfs(int node, int parent) {
  start[node] = ++ptr;
  for(int h = 0; h < ginit[node].size(); h++) {
    int to = ginit[node][h];
    if(to != parent) {
      far[0][to] = node;
      

      level[to] = level[node] + 1;
      dfs(to, node);
    }
  }
}

bool compare(int x, int y) {
  return start[x] < start[y];
}

std::vector<int> g[5 + nmax];
int dp[5 + nmax][5 + kmax], sz[5 + nmax];
int spec[5 + nmax];

void computedp(int node, int parent, int m) {
  int leaf = 1;

  if(spec[node] == 1) {
    for(int i = 1; i <= m; i++)
      dp[node][i] = i;
    dp[node][0] = 0;
  } else
    for(int i = 0;i <= m; i++)
      dp[node][i] = 1;

  sz[node] = 1;
  
  for(int h = 0;h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent) {
      leaf = 0;
      computedp(to, node, m);
      sz[node] += sz[to];

      if(spec[node] == 1) {
        for(int i = 1;i <= m; i++)
          dp[node][i] = 1LL * dp[node][i] * dp[to][i - 1] % modulo;
      } else 
        for(int i = 0;i <= m; i++)
          dp[node][i] = 1LL * dp[node][i] * dp[to][i] % modulo;

    }
  }
}

int solve() {
  int k, m, root;
  std::cin >> k >> m >> root;
  std::vector<int> temp;
  temp.push_back(root);

  for(int i = 1;i <= k; i++) {
    int val;
    std::cin >> val;
    temp.push_back(val);
    spec[val] = 1;
  }

  std::sort(temp.begin(), temp.end(), compare);
  std::vector<int> nodes;
  for(int i = 0; i < temp.size(); i++) {
    nodes.push_back(temp[i]);
    if(0 < i)
      nodes.push_back(getlca(temp[i - 1], temp[i]));
  }

  std::sort(nodes.begin(), nodes.end());
  nodes.erase(std::unique(nodes.begin(), nodes.end()), nodes.end());
  std::sort(nodes.begin(), nodes.end(), compare);
  std::vector<int> st;
  
  for(int i = 0; i < nodes.size(); i++) {
    int node = nodes[i];
    while(0 < st.size() && getlca(st.back(), node) != st.back())
      st.pop_back();
    if(0 < st.size()) {
      g[node].push_back(st.back());
      g[st.back()].push_back(node);
    }
    st.push_back(node);
  }

  computedp(root, 0, m);
  int result = 0;

  for(int i = 1; i <= std::min(m, sz[root]); i++) {
    for(int j = 1;j < i; j++) {
      dp[root][i] = (dp[root][i] - 1LL * dp[root][j] * comb[i][j]) % modulo;
      if(dp[root][i] < 0)
        dp[root][i] += modulo;
    }
    result += 1LL * dp[root][i] * lgpow(fact[i], modulo - 2) % modulo;
    if(modulo <= result)
      result -= modulo;
  }

  for(int i = 0; i < nodes.size(); i++) {
    int node = nodes[i];
    g[node].clear();
    spec[node] = sz[node] = 0;
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    ginit[x].push_back(y);
    ginit[y].push_back(x);
  }
  level[1] = 1;
  dfs(1, 0);
  precompute(n);
  
  for(int i = 1;i <= q; i++) {
    std::cout << solve() << '\n';
  }
  return 0;
}