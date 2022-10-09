#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using ll = long long;

int const nmax = 1000;
std::vector<int> g[1 + nmax];
int seen[1 + nmax], a[1 + nmax], b[1 + nmax], last[1 + nmax];
ll dp[1 + nmax];

bool makestep(int n, ll target) {
  std::queue<int> q;
  for(int i = 1;i <= n; i++)
    last[i] = dp[i] = 0;
  for(int i = 1;i <= n; i++)
    if(seen[i] == 1) {
      target += b[i];
      q.push(i);
    }
  for(int i = 1;i <= n; i++)
    if(seen[i] == 1)
      dp[i] = target;
  
  /*
  std::cout << "move: " << target << '\n';
  for(int i = 1;i <= n; i++)
    std::cout << seen[i] << " " ;
  std::cout << '\n';
  for(int i = 1;i <= n; i++)
    std::cout << a[i] << " ";
  std::cout << '\n';
  */

  while(0 < q.size()) {
    int node = q.front();
    q.pop();
    if(seen[node] == 1) {
      for(int h = 0; h < g[node].size(); h++) {
        int to = g[node][h];
        if(seen[to] == 0) {
          if(last[to] == 0 && a[to] < dp[node]) {
            dp[to] = dp[node] + b[to];
            last[to] = node;
            q.push(to);
          } else if(last[to] != node && a[to] < dp[node]) {
            while(to != 0) {
              seen[to] = 1;
              to = last[to];
            }
            while(node != 0) {
              seen[node] = 1;
              node = last[node];
            }
            return true;
          }
        }
      }
    } else {
      for(int h = 0; h < g[node].size(); h++) {
        int to = g[node][h];
        if(last[node] != to) {
          if(seen[to] == 1) {
            while(node != 0) {
              seen[node] = 1;
              node = last[node];
            }
            return true;
          } else {
            if(last[to] == 0 && a[to] < dp[node]) {
              dp[to] = dp[node] + b[to];
              last[to] = node;
              q.push(to);
            } else if(last[to] != node && a[to] < dp[node]) {
              while(to != 0) {
                seen[to] = 1;
                to = last[to];
              }
              while(node != 0) {
                seen[node] = 1;
                node = last[node];
              }
              return true;

            }
          }
        }
      }
    }
  }
  return false;
}

bool check(int n, int target) {
  for(int i = 1; i <= n; i++)
    seen[i] = 0;
  seen[1] = 1;
  while(makestep(n, target) == 1);
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      return false;
  return true;
}

int solve() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 2; i <= n; i++)
    std::cin >> a[i];
  for(int i = 2; i <= n; i++)
    std::cin >> b[i];

  for(int i = 1; i <= n; i++)
    g[i].clear();
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int x = 0;
  for(int jump = (1 << 29); 0 < jump; jump /= 2)
    if(check(n, x + jump) == 0)
      x += jump;
  return x + 1;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}