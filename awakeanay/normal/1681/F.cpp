#include <iostream>
#include <stack>
#include <vector>

#define int long long

const int MAXN = 500005;

std::vector<int> Adj[MAXN];
std::vector<std::pair<int, int> > Adj2[MAXN];

int bit[MAXN];
int st[MAXN], et[MAXN];
int sub[MAXN];
int n;

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&-x;
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&-x;
  }
  return ret;
}

int sum(int l, int r) {
  return sum(r) - sum(l-1);
}

int val[MAXN];
std::vector<int> pos[MAXN];
int par[MAXN];

/*
int get(int u) {
  int ans = 0;
  int sum = 0;
  for(int j : imp[u]) {
    sum += j;
    ans -= j*j;
  }
  ans += sum*(sum + 1);
}
*/

int ct = -1;
void dfs(int u, int p) {
  par[u] = p;
  pos[val[u]].push_back(u);
  st[u] = ++ct;
  sub[u] = 1;
  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u);
    sub[u] += sub[j];
  }
  et[u] = ct;
}

void init(int u, int p, int v) {
  val[u] = v;
  for(auto j: Adj2[u]) {
    if(j.first == p)
      continue;
    init(j.first, u, j.second);
  }
}

int dp1[MAXN];
int dp2[MAXN];
int ans = 0;
void solve1(int x) {
  int sz = pos[x].size();
  for(int i = sz-1; i >= 0; i--) {
    int u = pos[x][i];
    dp1[u] = sub[u] - sum(st[u], et[u]);
    add(st[u], dp1[u]);
  }

  std::stack<int> stk;
  for(int i = 0; i < sz; i++) {
    int u = pos[x][i];
    while(!stk.empty() && et[stk.top()] < st[u]) {
      add(st[stk.top()], dp1[stk.top()] - dp2[stk.top()]);
      stk.pop();
    }

    dp2[u] = n-sub[u]-sum(0, n-1)+sum(st[u], et[u]);
    /*
    std::cout << "DEB" << std::endl;
    for(int ch = 0; ch < n; ch++)
      std::cout << sum(ch, ch) << " ";
    std::cout << std::endl;
    std::cout << st[u] << " " << et[u] << std::endl;
    std::cout << u << " " << sum(0, n-1) << " " << sum(st[u], et[u]) << std::endl;
    */
    ans += dp1[u]*dp2[u];
    add(st[u], dp2[u] - dp1[u]);
    stk.push(u);
  }

  while(!stk.empty()) {
    add(st[stk.top()], dp1[stk.top()] - dp2[stk.top()]);
    stk.pop();
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;

  for(int i = 1; i < n; i++) {
    int u, v, x;
    std::cin >> u >> v >> x;
    u--; v--; x--;
    Adj[u].push_back(v);
    Adj[v].push_back(u);
    Adj2[u].push_back({v, x});
    Adj2[v].push_back({u, x});
  }

  init(0, -1, MAXN-1);
  dfs(0, -1);

  for(int i = 0; i < n; i++) {
    solve1(i);
    for(int j : pos[i]) {
      add(st[j], -dp1[j]);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}