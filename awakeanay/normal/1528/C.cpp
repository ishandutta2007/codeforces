#include <iostream>
#include <vector>

#define int long long

const int MAXN = 300005;

int subt[MAXN];
int anc[MAXN];
int ctr = -1, ans = 1;
int stim[MAXN], etim[MAXN];
std::vector<int> Adj1[MAXN], Adj2[MAXN];

void add(int x, int v, int bit[]) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x, int bit[]) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

void insert(int x) {
  add(stim[x], 1, anc);
  add(stim[x], 1+x, subt);
  add(etim[x]+1, -1-x, subt);
}

void remove(int x) {
  add(stim[x], -1, anc);
  add(stim[x], -1-x, subt);
  add(etim[x]+1, 1+x, subt);
}

void dfs1(int u, int p) {
  stim[u] = ++ctr;
  for(int j : Adj1[u]) {
    if(j == p)
      continue;
    dfs1(j, u);
  }
  etim[u] = ctr;
}

void dfs2(int u, int p, int cur) {
  int next = (sum(etim[u], anc) - sum(stim[u], anc));
  next = next == 0;
  int didYou = next;
  int prev = sum(stim[u], subt);
  if(prev != 0) {
    next--;
    remove(prev-1);
  }
  next += cur;

  if(didYou)
    insert(u);
  ans = std::max(ans, next);


  for(int j : Adj2[u]) {
    if(j == p)
      continue;

    dfs2(j, u, next);
  }
  if(didYou)
    remove(u);
  if(prev != 0) {
    insert(prev-1);
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

    ctr = -1;
    ans = 1;

    for(int i = 0; i < n; i++) {
      Adj1[i].clear();
      Adj2[i].clear();
    }

    for(int i = 1; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      Adj2[x].push_back(i);
    }

    for(int i = 1; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      Adj1[x].push_back(i);
    }

    dfs1(0, -1);
    dfs2(0, -1, 0);

    std::cout << ans << std::endl;
  }

  return 0;
}