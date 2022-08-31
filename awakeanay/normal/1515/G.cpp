#include <iostream>
#include <stack>
#include <vector>

#define int long long

const int MAXN = 200005;

int vis[MAXN];
int comp[MAXN];
std::vector<std::pair<int, int> > Adj[MAXN];
int dist[MAXN];
std::stack<int> st;
int dfsc[MAXN], dfsl[MAXN];
int hi[MAXN];
int cyc[MAXN];
int cn = 1;

int gcd(int a, int b) {
  if(a == 0)
    return b;
  return gcd(b%a, a);
}

void dfs(int u, int h) {
  dfsl[u] = dfsc[u] = cn++;
  hi[dfsc[u]] = h;
  st.push(u);
  vis[u] = 1;

  for(std::pair<int, int> v : Adj[u]) {
    int j = v.first;
    if(dfsc[j] == 0) {
      dfs(j, h+v.second);
    }

    if(vis[j] == 1) {
      if(dfsl[j] < dfsl[u]) {
        dfsl[u] = dfsl[j];
        dist[u] = dist[j] + v.second;
      }
    }
  }

  if(dfsl[u] == dfsc[u]) {
    std::stack<int> nst;
    while(1) {
      int j = st.top();
      st.pop();
      nst.push(j);
      vis[j] = 0;
      comp[j] = u;
      if(u == j)
        break;
    }

    while(!nst.empty()) {
      int j = nst.top();
      nst.pop();
      if(j != u) cyc[dfsc[j]] = dist[j] + cyc[dfsl[j]];
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    u--; v--;
    Adj[u].push_back({v, w});
  }

  for(int i = 0; i < n; i++)
    if(dfsc[i] == 0)
      dfs(i, 0);

  for(int i = 0; i < n; i++) {
    int upd = dfsc[comp[i]];
    for(std::pair<int, int> v : Adj[i]) {
      int j = v.first;
      if(comp[j] == comp[i]) {
        cyc[upd] = gcd(cyc[upd], hi[dfsc[i]] - hi[dfsc[comp[i]]] + v.second + cyc[dfsc[j]]);
      }
    }
  }

  int q;
  std::cin >> q;

  while(q--) {
    int v, s, t;
    std::cin >> v >> s >> t;
    v--;

    int csl = cyc[dfsc[comp[v]]];
    int gd = gcd(csl, t);
    if(s == 0)
      std::cout << "YES" << std::endl;
    else if(csl != 0 && (t-s)%gd == 0)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }
  
  return 0;
}