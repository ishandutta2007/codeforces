#include <iostream>
#include <vector>

#define int long long

const int MAXN = 300005;
const int MXT = 300003;

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

std::vector<int> Adj[MAXN];
std::vector<std::pair<int, int> > ad[MAXN];
int val[MAXN];

void dfs(int u, int p, int d) {
  for(std::pair<int, int> j : ad[u]) {
    int dt = d+j.second;
    int v = j.first;
    dt = std::min(MXT, dt);

    add(MXT-dt, v);
  }

  val[u] = sum(MXT-d);

  for(int j : Adj[u]) {
    if(j == p)
      continue;
    dfs(j, u, d+1);
  }

  for(std::pair<int, int> j : ad[u]) {
    int dt = d+j.second;
    dt = std::min(MXT, dt);
    int v = j.first;

    add(MXT-dt, -v);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    x--; y--;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }

  int m;
  std::cin >> m;

  for(int i = 0; i < m; i++) {
    int v, d, x;
    std::cin >> v >> d >> x;
    ad[v-1].push_back({x, std::min(n, d)});
  }

  dfs(0, -1, 0);

  for(int i = 0; i < n; i++)
    std::cout << val[i] << " ";
  std::cout << std::endl;

  return 0;
}