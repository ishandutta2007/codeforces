#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 300000;
std::vector<int> g[1 + nmax];

class FenwickTree{
private:
  std::vector<int> aib;
  int n;
public:
  FenwickTree(int n_) {
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val) {
    if(0 == pos)
      return ;
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))  {
      aib[x] += val;
    }
  }

  int query(int pos) {
    if(n < pos)
      pos = n;
    int result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
  int find_first(int target) {
    int x = 0;
    for(int jump = (1 << 20); 0 < jump; jump /= 2) {
      if(x + jump <= n && aib[x + jump] < target) {
        target -= aib[x + jump];
        x += jump;
      }
    }
    return x + 1;
  }
};

int v[1 + nmax], far[1 + nmax], sons[1 + nmax], level[1 + nmax];
int pos[1 + nmax], active[1 + nmax];

void dfs(int node) {
  sons[node] = 0;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(far[node] != to) {
      far[to] = node;
      sons[node]++;
      level[to] = level[node] + 1;
      dfs(to);
    }
  }
}

bool compare(int x, int y) {
  return v[x] < v[y];
}

bool check(int node, int &ptr) {
  ptr++;
  if(v[node] != ptr)
    return false;

  std::sort(g[node].begin(), g[node].end(), compare);
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(far[node] != to)
      if(check(to, ptr) == false)
        return false;
   }
   return true;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  FenwickTree aib(n);
  dfs(1);
  
  for(int i = 1;i <= n; i++)
    pos[v[i]] = i;

  for(int i = 1;i <= n; i++)
    aib.update(i, 1);
  for(int i = 1; i <= n; i++)
    active[i] = 1;


  ll result = 0;
  int steps = 0;
  for(int i = 1;i <= n; i++) {
    int node = pos[i];
    result += level[node];
    if(sons[node] == 0) {
      active[node] = 0;
      sons[far[node]]--;
      v[node] = aib.find_first(level[node] + 1);
      aib.update(v[node], -1);
    } else {
      while(node != 1) {
        int parent = far[node];
        for(int h = 0; h < g[parent].size(); h++) {
          int to = g[parent][h];
          if(active[to] == 1 && far[to] == parent && to != node) {
            if(v[to] < v[parent]) {
              std::cout << "NO";
              return 0;
            }
          }
        }
        std::swap(v[node], v[far[node]]);
        node = far[node];
      }
      break;
    }
  }
  
  std::vector<std::pair<int,int>> aux;
  for(int i = 1; i <= n; i++)
    if(active[i] == 1)
      aux.push_back({v[i], i});
  std::sort(aux.begin(), aux.end());

  for(int i = 0; i < aux.size(); i++)
    v[aux[i].second] = aib.find_first(i + 1);
  
  int ptr = 0;
  if(check(1, ptr) == true) {
    std::cout << "YES\n";
    std::cout << result << '\n';
    for(int i = 1;i <= n; i++)
      std::cout << v[i] << " ";
  } else
    std::cout << "NO\n";
  return 0;
}