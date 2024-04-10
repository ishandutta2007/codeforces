#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const modulo = 1000000007;

std::vector<std::pair<int,int>> g[1 + nmax];
int level[1 + nmax], dist[1 + nmax];
std::vector<int> events[1 + nmax];

void dfs(int node, int root) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    if(level[to] == 0) {
      level[to] = level[node] + 1;
      dist[to] = dist[node] ^ g[node][h].second;
      dfs(to, root);
    } else if(level[node] + 1 < level[to]) {
      events[root].push_back(dist[node] ^ dist[to] ^ g[node][h].second);
    }
  }
}

int const sigma = 5;

ll _add(ll mask, int val) {
  std::vector<std::pair<int, int>> aux;
  std::vector<int> values;
  
  while(0 < mask) {
    int base = mask & ((1 << sigma) - 1);
    for(int j = sigma - 1; 0 <= j; j--)
      if((1 << j) & base) {
        aux.push_back({j, base});
        break;
      }
    mask >>= sigma;
  }
  
  for(int i = 0; i < aux.size(); i++)
    if((1 << aux[i].first) & val)
      val ^= aux[i].second;
  
  if(0 < val) {
    for(int j = sigma - 1; 0 <= j; j--)
      if((1 << j) & val) {
        aux.push_back({j, val});
        break;
      }
    for(int j = 0; j < aux.size() - 1; j++)
      if((1 << aux.back().first) & aux[j].second)
        aux[j].second ^= aux.back().second;
    std::sort(aux.begin(), aux.end());
  }
  
  for(int i = aux.size() - 1; 0 <= i; i--)
    mask = (mask<<sigma) + aux[i].second;
  return mask;
}

std::map<ll,int> quick;
std::map<int, ll> rev;

int const statemax = 374;
int _trans[1 + statemax][1 << sigma];

void print(ll mask) {
  std::vector<std::pair<int, int>> aux;
  
  while(0 < mask) {
    int base = mask & ((1 << sigma) - 1);
    for(int j = sigma - 1; 0 <= j; j--)
      if((1 << j) & base) {
        aux.push_back({j, base});
        break;
      }
    mask >>= sigma;
  }
  for(int i = 0; i < aux.size(); i++)
    std::cout << aux[i].second << " ";
  std::cout << '\n';
}

void backt(ll mask, int &ptr) {
  ++ptr;
  quick[mask] = ptr;
  rev[ptr] = mask;

  for(int force = (1 << sigma) - 1; 0 < force; force--) {
    ll newmask = _add(mask, force);
    if(((newmask>>sigma) == mask) && (newmask & ((1 << sigma) - 1)) == force)
      backt(newmask, ptr);
  }
}

int dp[1 + statemax], dp2[1 + statemax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int ptr = 0;
  backt(0, ptr);
  for(int i = 0; i <= ptr; i++)
    for(int j = 0; j < (1 << sigma); j++) {
      ll newmask = _add(rev[i], j);
      if(newmask != rev[i])
        _trans[i][j] = quick[newmask];
      else
        _trans[i][j] = -1;
    }

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  level[1] = 1;
  for(int h = 0; h < g[1].size(); h++) {
    level[g[1][h].first] = 2;
    dist[g[1][h].first] = g[1][h].second;
  }
  
  for(int i = 1;i <= n; i++)
    if(level[i] == 2)
      dfs(i, i);
  
  dp[0] = 1;

  for(int i = 1; i <= n; i++) 
    if(level[i] == 2) {
      for(int j = 0; j <= statemax; j++)
        dp2[j] = 0;

      int neigh = 0, stair = 0;
      for(int h = 0; h < g[i].size(); h++)
        if(level[g[i][h].first] == 2) {
          neigh = g[i][h].first;
          stair = g[i][h].second;
        }

      if(neigh == 0) {
        for(int j = 0; j <= statemax; j++)
          if(0 < dp[j]) {
            int val = j;
            for(int h = 0; h < events[i].size() && 0 <= val; h++)
              val = _trans[val][events[i][h]];
            if(0 <= val) {
              dp2[val] += dp[j];
              if(modulo <= dp2[val])
                dp2[val] -= modulo;
            }
          }
      } else if(i < neigh) {
        for(int j = 0; j <= statemax; j++)
          if(0 < dp[j]) {
            int val = j;
            for(int h = 0; h < events[i].size() && 0 <= val; h++)
              val = _trans[val][events[i][h]];
            for(int h = 0; h < events[neigh].size() && 0 <= val; h++)
              val = _trans[val][events[neigh][h]];
            
            if(0 <= val) {
              dp2[val] += dp[j];
              if(modulo <= dp2[val])
                dp2[val] -= modulo;
              dp2[val] += dp[j];
              if(modulo <= dp2[val])
                dp2[val] -= modulo;

              val = _trans[val][stair ^ dist[i] ^ dist[neigh]];
              if(0 <= val) {
                dp2[val] += dp[j];
                if(modulo <= dp2[val])
                  dp2[val] -= modulo;
              }
            }
          }
      }

      for(int j = 0; j <= statemax; j++) {
        dp[j] += dp2[j];
        if(modulo <= dp[j])
          dp[j] -= modulo;
      }
    }
  
  int result = 0;
  for(int i = 0; i <= statemax; i++){
    result += dp[i];
    if(modulo <= result)
      result -= modulo;
  }
  
  std::cout << result;
  return 0;
}