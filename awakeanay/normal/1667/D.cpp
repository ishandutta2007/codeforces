#include <iostream>
#include <stack>
#include <cassert>
#include <vector>

const int MAXN = 200005;

std::vector<int> Adj[MAXN];
int done[MAXN];
int dp[2][MAXN];
int a[MAXN];

void solve(int u, int x, int p) {
  if(done[u]&(1+x))
    return;
  int sz = Adj[u].size();
  int c[2] = {sz-sz/2, sz/2};
  if(p != -1) {
    c[x]--;
  }
  int can = true;

  for(int j : Adj[u]) {
    if(j == p)
      continue;
    solve(j, 0, u);
    solve(j, 1, u);
    if(dp[0][j] && dp[1][j])
      continue;
    can &= dp[0][j] | dp[1][j];
    int nx = a[j]^a[u]^dp[1][j];
    c[nx]--;
  }

  dp[x][u] = c[0] >= 0 && c[1] >= 0 && can;
  done[u] |= (x+1);
}

void print(int u, int x, int p) {
  int sz = Adj[u].size();
  int c[2] = {sz-sz/2, sz/2};

  std::vector<int> sol[2];

  if(p != -1) {
    c[x]--;
    sol[x].push_back(p);
  }

  std::stack<int> st;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    if(dp[0][j] && dp[1][j]) {
      st.push(j);
      continue;
    }
    int nx = a[j]^a[u]^dp[1][j];
    sol[nx].push_back(j);
    c[nx]--;
  }

  while(!st.empty()) {
    int j = st.top();
    st.pop();
    int nx = c[1] > 0;
    sol[nx].push_back(j);
    c[nx]--;
  }

  assert(c[0] == 0 && c[1] == 0);

  for(int j = 0; j < sz; j++) {
    int nx = sol[j%2][c[j%2]++];
    if(nx == p)
      std::cout << u+1 << " " << p+1 << "\n";
    else {
      assert(dp[a[u]^a[nx]^(j%2)][nx]);
      print(nx, a[u]^a[nx]^(j%2), u);
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      Adj[i].clear();
      done[i] = 0;
      dp[0][i] = dp[1][i] = 0;
    }

    for(int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      Adj[u].push_back(v);
      Adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
      a[i] = Adj[i].size()%2;

    solve(0, 0, -1);

    if(dp[0][0]) {
      std::cout << "YES" << "\n";
      print(0, 0, -1);
    }
    else {
      std::cout << "NO" << "\n";
    }
  }

  return 0;
}