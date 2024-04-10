#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

using ll = long long;

int const nmax = 100000;
int const sigma = 10;
int modulo;
std::vector<std::pair<int,int>> g[1 + nmax];
int seen[1 + nmax], sz[1 + nmax], invpow[1 + nmax], realpow[1 + nmax];

void gcd(int a, int b, int &x, int &y) {
  if(b == 0) {
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, x, y);
    int aux = x;
    x = y;
    y = aux - a / b * y;
  }
}

int inverse(int number) {
  int x, y;
  gcd(number, modulo, x, y);
  x %= modulo;
  if(x < 0)
    x += modulo;
  return x;
}

void precompute() {
  invpow[0] = 1;
  invpow[1] = inverse(10);
  for(int i = 2;i <= nmax; i++)
    invpow[i] = 1LL * invpow[i - 1] * invpow[1] % modulo; 
  realpow[0] = 1;
  realpow[1] = 10 % modulo;
  for(int i = 2; i <= nmax; i++)
    realpow[i] = 1LL * realpow[i - 1] * realpow[1] % modulo;
}

void computeSize(int node, int parent) {
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent && seen[to] == 0) {
      computeSize(to, node);
      sz[node] += sz[to];
    }
  }
}

int findCentroid(int node, int parent, int target) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(to != parent && seen[to] == 0 && target <= sz[to])
      return findCentroid(to, node, target);
  }
  return node;
}

std::map<int, int> mp;

void dfstail(int node, int parent, int len, int curr) {
  mp[1LL * (modulo - curr) * invpow[len] % modulo]++;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first, cost = g[node][h].second;
    if(to != parent && seen[to] == 0) {
      dfstail(to, node, len + 1, (1LL * curr * 10 + cost) % modulo);
    }
  }
}
ll dfshead(int node, int parent, int len, int curr) {
  ll result = 0;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first, cost = g[node][h].second;
    if(to != parent && seen[to] == 0) {
      result += dfshead(to, node, len + 1, (1LL * cost * realpow[len] + curr) % modulo);
    }
  }
  return result + mp[curr];
}

ll solve(int node) {
  computeSize(node, 0);
  int centroid = findCentroid(node, 0, sz[node] / 2);
  mp.clear();
  ll result = 0;
  mp[0] = 1;
  for(int h = 0; h < g[centroid].size(); h++) {
    int to = g[centroid][h].first, cost = g[centroid][h].second;
    if(seen[to] == 0) {
      result += dfshead(to, centroid, 1, cost % modulo);
      dfstail(to, centroid, 1, cost % modulo);
    }
  }
  mp.clear();
  for(int h = g[centroid].size() - 1; 0 <= h; h--) {
    int to = g[centroid][h].first, cost = g[centroid][h].second;
    if(seen[to] == 0) {
      result += dfshead(to, centroid, 1, cost % modulo);
      dfstail(to, centroid, 1, cost % modulo);
    }
  }
  result += mp[0];

  seen[centroid] = 1;
  for(int h = 0; h < g[centroid].size(); h++) {
    int to = g[centroid][h].first;
    if(seen[to] == 0) {
      result += solve(to);
    }
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n >> modulo;
  precompute();

  for(int i = 1; i < n; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    ++x;
    ++y;
    g[x].push_back({y, cost});
    g[y].push_back({x, cost});
  }
  std::cout << solve(1) << '\n';
  return 0;
}