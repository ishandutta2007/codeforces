#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <set>

int const nmax = 300000;
std::vector<int> g[1 + nmax], g2[1 + nmax];
int start[1 + nmax], stop[1 + nmax];

std::set<std::pair<int,int>> myset;

void init(int node, int parent, int &ptr) {
  start[node] = ++ptr;
  for(int h = 0; h < g2[node].size(); h++) {
    int to = g2[node][h];
    if(to != parent)
      init(to, node, ptr);
  }
  stop[node] = ptr;
}

void dfs(int node, int parent, int &result) {
  std::pair<int,int> deleted = {-1, -1};
  std::pair<int,int> myinterval = {start[node], stop[node]};
  std::set<std::pair<int,int>>::iterator it = myset.lower_bound(myinterval);
  
  bool failure = false;

  if(it != myset.end())
    if(it->first <= myinterval.second)
      failure = true;
  if(it == myset.begin()) {
    myset.insert(myinterval);
  } else {
    it--;
    if(myinterval.second <= it->second) {
      deleted = *it;
      myset.erase(it);
    }
    myset.insert(myinterval);
  }
  result = std::max(result, (int)myset.size());

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent)
      dfs(to, node, result);
  }
  if(failure == false)
    myset.erase(myinterval);
  if(deleted.first != -1)
    myset.insert(deleted);
}

int solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    g[i].clear();
    g2[i].clear();
  }
  for(int i = 2; i <= n; i++) {
    int parent;
    std::cin >> parent;
    g[parent].push_back(i);
  }
  for(int i = 2;i <= n; i++) {
    int parent;
    std::cin >> parent;
    g2[parent].push_back(i);
  }
  myset.clear();
  int ptr = 0, result = 0;
  init(1, 0, ptr);
  dfs(1, 0, result);
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}