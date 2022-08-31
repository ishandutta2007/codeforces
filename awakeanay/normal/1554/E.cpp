#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MOD = 998244353;
const int MAXN = 100005;

std::vector<int> Adj[MAXN];
std::vector<int> divi[MAXN];

int check(int u, int p, int k) {
  int cur = 0;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    int next = check(j, u, k);
    if(next == -1)
      return -1;
    cur += next;
  }
  if(cur%k == 0)
    return 1;
  if((cur+1)%k == 0)
    return 0;
  return -1;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 2; i < MAXN; i++)
    for(int j = i; j < MAXN; j+=i)
      divi[j].push_back(i);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
      Adj[i].clear();

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }
    std::vector<int> ans(n, 0);

    ans[0] = 1;
    for(int i = 1; i < n; i++)
      ans[0] = (ans[0]*2)%MOD;
    
    for(int j : divi[n-1]) {
      if(check(0, -1, j) == 1) {
        ans[j-1]++;
        ans[0] = (ans[0] + MOD - ans[j-1])%MOD;
      }

    }

    for(int j : divi[n-1]) {
      if(ans[j-1]) {
        for(int k = 2*j; k < n; k+=j) {
          if(ans[k-1] == 1)
            ans[j-1] = 0;
        }
        if(ans[j-1] == 0)
          ans[0] = (ans[0] + 1)%MOD;
      }
    }

    for(int j : ans)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}