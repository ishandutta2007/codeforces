#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

using ll = long long;

int const nmax = 100000;
int const base = 2000003;
int const modulo = 1000000007;
int const modulo2 = 1000000009;

std::vector<int> g[5 + nmax];
int dp[5 + nmax], dp2[5 + nmax];

int encode(int number) {
  return (number ^ 618253818) % modulo;
}

int encode2(int number) {
  return (number ^ 787591414) % modulo2;
}

void dfs(int node, int parent) {
  for(int h = 0;h < g[node].size(); h++)
    if(g[node][h] == parent)
      g[node].erase(g[node].begin() + h);
  for(int h = 0;h < g[node].size(); h++) {
    int to = g[node][h];
    dfs(to, node);

    dp[node] = dp[node] + dp[to];
    if(modulo <= dp[node])
      dp[node] -= modulo;
    dp2[node] = dp2[node] + dp2[to];
    if(modulo2 <= dp2[node])
      dp2[node] -= modulo2;
  }
  dp[node] = (1LL * encode(dp[node]) * base + g[node].size()) % modulo;
  dp2[node] = (1LL * encode2(dp2[node]) * base + g[node].size()) % modulo2;
}

std::map<std::pair<int,int>,int> mp;
int sol[5 + nmax];

void maperase(std::pair<int,int> number) {
  if(mp[number] == 1)
    mp.erase(number);
  else
    mp[number]--;
}

void mapinsert(std::pair<int,int> number) {
  mp[number]++;
}

void printmap() {
  for(std::map<std::pair<int,int>, int>::iterator it = mp.begin(); it != mp.end(); it++)
    std::cout << it->first.first << " " << it->first.second << " " << it->second << '\n';
}

void dfs2(int node, int parent, int acc, int acc2) {
  if(parent != 0) {
    mapinsert({acc, acc2});
    maperase({dp[node], dp2[node]});
  }
  sol[node] = mp.size() + 1;

  std::vector<int> pref(g[node].size()), suff(g[node].size());
  std::vector<int> pref2(g[node].size()), suff2(g[node].size());
  
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    pref[h] = suff[h] = dp[to];
    pref2[h] = suff2[h] = dp2[to];
  }
  
  for(int h = 1; h < g[node].size(); h++) {
    pref[h] = (pref[h - 1] + pref[h]) % modulo;
    pref2[h] = (pref2[h - 1] + pref2[h]) % modulo2;
  }

  for(int h = g[node].size() - 2; 0 <= h; h--) {
    suff[h] = (suff[h + 1] + suff[h]) % modulo;
    suff2[h] = (suff2[h + 1] + suff2[h]) % modulo2;
  }

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    int newval = 0, newval2 = 0;
    newval = acc;
    newval2 = acc2;
    if(0 < h) {
      newval = (newval + pref[h - 1]) % modulo;
      newval2 = (newval2 + pref2[h - 1]) % modulo2;
    }
    if(h + 1 < g[node].size()) {
      newval = (newval + suff[h + 1]) % modulo;
      newval2 = (newval2 + suff2[h + 1]) % modulo2;
    }
    newval = (1LL * encode(newval) * base + (g[node].size() - (parent == 0))) % modulo;
    newval2 = (1LL * encode2(newval2) * base + (g[node].size() - (parent == 0))) % modulo2;
    dfs2(to, node, newval, newval2);
  }
  
  if(parent != 0) {
    mapinsert({dp[node], dp2[node]});
    maperase({acc, acc2});
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int root = 1;
  dfs(root, 0);
  for(int i = 1;i <= n; i++)
    if(root != i)
      mp[{dp[i], dp2[i]}]++;
  dfs2(root, 0, 0, 0);
  int smax = 0;
  for(int i = 1; i <= n; i++)
    if(sol[smax] < sol[i])
      smax = i;

  std::cout << smax << '\n';
  std::cerr << sol[smax] << '\n';
  return 0;
}