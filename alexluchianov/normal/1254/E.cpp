#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 500000;
int const modulo = 1000000007;
int far[5 + nmax], level[5 + nmax];
std::vector<int> g[5 + nmax];

void dfs(int node, int parent) {
  far[node] = parent;
  level[node] = level[parent] + 1;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}

std::vector<std::pair<int,int>> rel[5 + nmax];

int firstEdge[5 + nmax], lastEdge[5 + nmax];

void markPath(int x, int y, int &steps, bool &valid) {
  if(valid == false) return ;

  std::vector<int> firstHalf;
  std::vector<int> secondHalf;
  firstHalf.push_back(x);
  

  while(x != y) {

    if(level[x] < level[y]) {
      secondHalf.push_back(y);
      y = far[y];
    } else {
      x = far[x];
      firstHalf.push_back(x);
    }
  }
  std::reverse(secondHalf.begin(), secondHalf.end());
  for(int i = 0; i < secondHalf.size(); i++)
    firstHalf.push_back(secondHalf[i]);

  if(firstEdge[firstHalf[0]] == 0)
    firstEdge[firstHalf[0]] = firstHalf[1];
  else {
    valid = false;
    return ;
  }

  if(lastEdge[firstHalf[firstHalf.size() - 1]] == 0)
    lastEdge[firstHalf[firstHalf.size() - 1]] = firstHalf[firstHalf.size() - 2];
  else {
    valid = false;
    return ;
  }
  steps += firstHalf.size() - 1;
  for(int i = 1; i + 1 < firstHalf.size(); i++) {
    rel[firstHalf[i]].push_back({firstHalf[i - 1], firstHalf[i + 1]});
  }
}

int seen[5 + nmax], seen2[5 + nmax];

int fact(int n) {
  if(n < 1)
    return 1;
  return 1LL * fact(n - 1) * n % modulo;
}

int lgpow(int a, int b) {
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b/ 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int inverse(int number) {
  return lgpow(number, modulo - 2);
}

int nxt[5 + nmax];
int state[5 + nmax];

int solve(int node) {
  for(int h = 0;h < g[node].size(); h++) {
    int to = g[node][h];
    seen[to] = 0;
    seen2[to] = 0;
    nxt[to] = to;
    state[to] = 0;
  }
  
  for(int h = 0; h < rel[node].size(); h++) {
    std::pair<int,int> ev = rel[node][h];
    seen[ev.first] ++;
    seen2[ev.second]++;
    
    if(ev.first != nxt[ev.first])
      return 0;
    nxt[ev.first] = ev.second;
  }
  

  if(0 < firstEdge[node] && firstEdge[node] == lastEdge[node] && 1 < g[node].size()) 
    return 0;
  if(0 < firstEdge[node] && 0 < seen2[firstEdge[node]])
    return 0;
  if(0 < lastEdge[node] && 0 < seen[lastEdge[node]])
    return 0;
  
  int result = 1, groups = 0;

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    int acc = 0;

    if(state[to] == 0 && seen2[to] == 0) {
      int target = to;
      bool hasFirst = false, hasLast = false;
      groups++;
      while(state[to] == 0) {
        hasFirst |= (to == firstEdge[node]);
        hasLast |= (to == lastEdge[node]);
        acc++;
        state[to] = 1;
        to = nxt[to];
      }
      if(hasFirst == 1 && hasLast == 1 && acc < g[node].size())
        return 0;
      if(target == to && 1 < acc)
        return 0;
    }
  }

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(state[to] == 0)
      return 0;
  }
  
  return 1LL * result * fact(groups - (0 < firstEdge[node]) - (0 < lastEdge[node])) % modulo;;
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
  dfs(1, 0);
  int steps = 0;
  bool valid = true;

  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    if(0 < val && steps < 2 * n) {
      if(i != val) 
        markPath(i, val, steps, valid);
      else
        valid = false;
    }
  }
 
  if(valid == false || 2 * n <= steps) {
    std::cout << 0 << '\n';
    return 0;
  } else {

    int result = 1;
    for(int i = 1;i <= n; i++) {
      result = 1LL * result * solve(i) % modulo;
    }
    std::cout << result << '\n';
  }
  return 0;
}