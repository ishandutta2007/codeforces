#include <iostream>
#include <algorithm>
#include <vector>

const int MAXN = 1000006;

std::vector<int> vis;
std::vector<int> rev;
std::vector<int> Adj[MAXN];
std::vector<int> comp;

int bip;
int a, b;
int n;
int k;
int call;
int x[3];
std::vector<int> vec;

void dfs(int u, int c, int ch, int cp) {
  vis[u] = c;
  comp[u] = cp;

  for(int j : Adj[u]) {
    if(ch && rev[u] != -1 && (j == vec[(rev[u]+1)%k] || j == vec[(rev[u]+k-1)%k]))
      continue;
    if((a == u && b == j) || (a == j && b == u))
      continue;
    if(vis[j] == -1)
      dfs(j, c^1, ch, cp);
    else if(vis[j] == c) {
      call = j;
      bip = false;
      //std::cout << j+1 << " start " << std::endl;
    }
    if(!bip) {
      //std::cout << u+1 << " add " << std::endl;
      if(call != -1)
        vec.push_back(u);
      if(u == call)
        call = -1;
      return;
    }
  }
}

void test(int u, int v, int ch) {
  a = u;
  b = v;
  bip = 1;

  vis = std::vector<int>(n, -1);
  comp = std::vector<int>(n, -1);
  call = -1;
  for(int i = 0; i < n; i++) {
    if(vis[i] == -1)
      dfs(i, 0, ch, i);
    if(!bip)
      break;
  }
}

void out(int x) {
  if(x >= 0) {
    std::cout << "YES" << std::endl;
    for(int i = 0; i < n; i++)
      std::cout << (vis[i]^x);
    std::cout << std::endl;
  }
  else
    std::cout << "NO" << std::endl;
}

signed main() {
  //int inp;
  //std::cin >> inp;
  int t;
  std::cin >> t;

  while(t--) {
    int m;
    std::cin >> n >> m;

    for(int i = 0; i < n; i++)
      Adj[i].clear();

    for(int i = 0; i < m; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    vec.clear();
    test(-1, -1, 0);
    if(bip) {
      out(0);
    }
    else {
      rev = std::vector<int>(n, -1);
      k = vec.size();
      for(int i = 0; i < k; i++) {
        rev[vec[i]] = i;
        //std::cout << vec[i]+1 << " ";
      }
      //std::cout << std::endl;

      test(-1, -1, 1);
      if(!bip) {
        out(-1);
      }
      else {
        int f = 0;
        std::vector<int> pr(2*k, 0);
        std::vector<int> mark(n, 0);
        std::vector<int> store[n];
        for(int i = 0; i < k; i++) {
          int u = vec[i];
          store[comp[u]].push_back(i);
        }

        for(int j = 0; j < n; j++) {
          if(!store[j].size())
            continue;

          store[j].push_back(store[j][0]+k);

          for(int i = 0; i+1 < store[j].size(); i++) {
            int u = store[j][i];
            int v = store[j][i+1];
            if(((u^v)&1)^vis[vec[u%k]]^vis[vec[v%k]]) {
              //std::cout << "CHECK" << std::endl;
              //std::cout << u << " " << v << std::endl;
              pr[u]++;
              pr[v]--;
              break;
            }
          }
        }

        for(int i = 0; i < 2*k; i++) {
          if(i)
            pr[i] += pr[i-1];
          if(i >= k)
            pr[i-k] += pr[i];
        }

        std::pair<int, int> best = {-1, -1};
        //std::cout << "HERE" << std::endl;
        for(int i = 0; i < k; i++) {
          //std::cout << pr[i] << " ";
          best = std::max(best, {pr[i], i});
        }
        //std::cout << std::endl;
        f = best.second;
        //std::cout << "SPEC" << std::endl;
        //std::cout << f << std::endl;

        //f = inp;
        int u = vec[f];
        int v = vec[(f+1)%k];
        test(u, v, 0);
        if(bip) {
          out(vis[u]^1);
        }
        else {
          out(-1);
        }
      }
    }
  }
}