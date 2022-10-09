#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
int const modulo = 1000000007;

std::vector<std::pair<int,int>> g[1 + nmax];
int v[1 + nmax], sz[1 + nmax], seen[1 + nmax];

void computesz(int node, int parent) {
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(seen[to] == 0 && to != parent) {
      computesz(to, node);
      sz[node] += sz[to];
    }
  }
}

int find_centroid(int node, int target) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(seen[to] == 0 && sz[to] <= sz[node] && target <= sz[to])
      return find_centroid(to, target);
  }
  return node;
}

struct Event{
  int op;
  int l;
  int sum;
};

void dfs(int node, int parent, int firstcolor, int lastcolor, int acc, int sum, std::vector<Event> &aux) {
  aux.push_back({firstcolor, acc, (sum + v[node]) % modulo});
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    int cost = g[node][h].second;
    if(seen[to] == 0 && to != parent) {
      dfs(to, node, firstcolor, cost, acc + (lastcolor != cost), (sum + v[node]) % modulo, aux);
    }
  }
}

int dp[1 + nmax][2], dpsum[1 + nmax][2];

int extract(std::vector<Event> &aux, int k, int bonus) {
  int smax = 1;
  for(int i = 0; i < aux.size(); i++)  {
    smax = std::max(smax, aux[i].l + 1);
    dp[aux[i].l][aux[i].op]++;
    dpsum[aux[i].l][aux[i].op] += aux[i].sum;
    if(modulo <= dpsum[aux[i].l][aux[i].op])
      dpsum[aux[i].l][aux[i].op] -= modulo;
  }
  for(int h = 0; h < 2; h++)
    for(int i = 1;i <= smax; i++) {
      dp[i][h] += dp[i - 1][h];
      if(modulo <= dp[i][h])
        dp[i][h] -= modulo;
    }

  for(int h = 0; h < 2; h++)
    for(int i = 1;i <= smax; i++) {
      dpsum[i][h] += dpsum[i - 1][h];
      if(modulo <= dpsum[i][h])
        dpsum[i][h] -= modulo;
    }
  int result = 0;
  for(int i = 0; i < aux.size(); i++) {
    Event ev = aux[i];
    int pos = std::min(smax, k - ev.l);
    if(0 <= pos) 
      result = (result + 1LL * dp[pos][ev.op] * (bonus + ev.sum) + dpsum[pos][ev.op]) % modulo;
    pos = std::min(smax, k - ev.l - 1);
    if(0 <= pos) 
      result = (result + 1LL * dp[pos][!ev.op] * (bonus + ev.sum) + dpsum[pos][!ev.op]) % modulo;
    if(ev.l + ev.l <= k) {
      result = (((ll)result) - ev.sum - ev.sum - bonus) % modulo;
      if(result < 0)
        result += modulo;
    }
  }

  for(int i = 0; i <= smax; i++)
    for(int h = 0; h < 2; h++)
      dp[i][h] = dpsum[i][h] = 0;
  return result;
}

int solve(int node, int k) {
  computesz(node, 0);
  int centroid = find_centroid(node, sz[node] / 2);
  std::vector<Event> great;
  int bonus = v[centroid];
  int result = 0;
  

  for(int h = 0; h < g[centroid].size(); h++) {
    int to = g[centroid][h].first;
    int cost = g[centroid][h].second;
    if(seen[to] == 0) {
      std::vector<Event> aux;
      dfs(to, centroid, cost, cost, 0, 0, aux);    
      result -= extract(aux, k, bonus);
      if(result < 0)
        result += modulo;
      for(int j = 0; j < aux.size(); j++) 
        great.push_back(aux[j]);
    }
  }

  result += extract(great, k, bonus);
  if(modulo <= result)
    result -= modulo;
  
  result = 1LL * result * ((1 + modulo) / 2) % modulo;
  result += bonus;
  if(modulo <= result)
    result -= modulo;
  
  for(int i = 0; i < great.size(); i++) {
    if(great[i].l <= k) {
      result = (((ll)result) + great[i].sum + bonus) % modulo;
    }
  }

  seen[centroid] = 1;
  for(int h = 0; h < g[centroid].size(); h++) {
    int to = g[centroid][h].first;
    if(seen[to] == 0) {
      result += solve(to, k);
      if(modulo <= result)
        result -= modulo;
    }
  }

  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i < n; i++) {
    int x, y, color;
    std::cin >> x >> y >> color;
    g[x].push_back({y, color});
    g[y].push_back({x, color});
  }
  std::cout << solve(1, k) << '\n';
  return 0;
}