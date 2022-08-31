#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 300005;

std::vector<int> Adj[MAXN];
std::vector<int> ends;
int rev[MAXN];
int cval[MAXN];
int orig[MAXN];
int check_count;
int lim;
int save;
int len;
bool poss;
int orig_count;
int par[MAXN];

void check(int u) {
  check_count++;
  if(check_count != cval[u]) {
    poss = false;
    return;
  }

  for(int j : Adj[u]) {
    if(cval[j] > lim)
      check(j);
  }
}

void dfs(int u, int h) {
  orig[u] = ++orig_count;
  if(cval[u] < cval[0]) {
    len += h;
  }
  if(cval[u] == lim)
    save = h;

  std::sort(Adj[u].begin(), Adj[u].end(), [](int a, int b) -> bool { return cval[a] < cval[b]; });
  for(int j : Adj[u])
    dfs(j, h+1);

  ends.push_back(u);
}

signed main() {
  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    std::cin >> cval[i];
    rev[cval[i]] = i;
    lim = cval[0]-1;
  }

  for(int i = 1; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    a--; b--;
    Adj[a].push_back(b);
    par[b] = a;
  }

  dfs(0, 0);

  poss = true;
  for(int i = 1; i < lim; i++) {
    if(rev[i] != ends[i-1])
      poss = false;
  }

  if(lim != 0) {
    int sb = lim+save;
    int cur = rev[lim];
    while(cur != 0) {
      poss &= cval[par[cur]] == sb;
      sb--;
      cval[cur] ^= cval[par[cur]] ^= cval[cur] ^= cval[par[cur]];
      cur = par[cur];
    }
  }

  check_count = lim-1;
  check(0);

  if(poss) {
    std::cout << "YES" << std::endl;
    std::cout << len << std::endl;
    for(int j = 0; j < n; j++)
      std::cout << orig[j] << " ";
    std::cout << std::endl;
  }
  else
    std::cout << "NO" << std::endl;

  return 0;
}