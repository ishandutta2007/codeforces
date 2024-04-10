#include <iostream>
#include <vector>

#define mid (l+r)/2
#define left id+1
#define right id+2*(mid-l+1)

int n;

struct segtree {
  std::vector<int> seg, lazy, count;

  void build(int id, int l = 0, int r = n-1) {
    count[id] = r-l+1;

    if(l == r)
      return;

    build(left, l, mid);
    build(right, mid+1, r);
  }

  void init() {
    seg = lazy = count = std::vector<int>(2*n-1, 0);
    build(0);
  }

  void shift(int id, int l, int r) {
    seg[left] += lazy[id];
    seg[right] += lazy[id];
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];
    lazy[id] = 0;
  }

  void update(int x, int y, int val, int id = 0, int l = 0, int r = n-1) {
    if(y < l || x > r)
      return;

    if(x <= l && r <= y) {
      lazy[id] += val;
      seg[id] += val;
      return;
    }

    shift(id, l, r);

    update(x, y, val, left, l, mid);
    update(x, y, val, right, mid+1, r);

    if(seg[left] < seg[right]) {
      seg[id] = seg[left];
      count[id] = count[left];
    }
    else if(seg[left] > seg[right]) {
      seg[id] = seg[right];
      count[id] = count[right];
    }
    else {
      seg[id] = seg[left];
      count[id] = count[left] + count[right];
    }
  }
};

std::vector<std::vector<int> > Adj;
segtree euler;
std::vector<int> match;
std::vector<int> roots[2];
std::vector<int> stime, etime;
int curtime = -1;
long long ans = 0;

void dfs1(int u) {
  stime[u] = ++curtime;

  for(int j : Adj[u])
    dfs1(j);
  etime[u] = curtime;
}

void dfs0(int u) {
  int v = match[u];

  euler.update(stime[v], etime[v], 1);
  ans += n;
  if(euler.seg[0] == 0)
    ans -= euler.count[0];

  for(int j : Adj[u])
    dfs0(j);

  euler.update(stime[v], etime[v], -1);
}

int main() {
  int N, M;
  std::cin >> N >> M;

  n = (N*M)/2;
  euler.init();
  stime = etime = std::vector<int>(N*M, 0);
  Adj = std::vector<std::vector<int> > (N*M, std::vector<int>(0));
  match.reserve(N*M);

  for(int i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;
    for(int j = 0; j < M; j++) {
      int par = -1;

      if(s[j] == 'U') {
        if(i + 2 < N)
          par = (i+2)*M + j;
        if((i + j)%2 == 0)
          match[i*M+j] = (i+1)*M + j;
      }
      else if(s[j] == 'L') {
        if(j + 2 < M)
          par = i*M + j + 2;
        if((i + j)%2 == 0)
          match[i*M+j] = i*M + j+1;
      }
      else if(s[j] == 'R') {
        if(j > 1)
          par = i*M + j - 2;
        if((i + j)%2 == 0)
          match[i*M+j] = i*M + j-1;
      }
      else {
        if(i > 1)
          par = (i-2)*M + j;
        if((i + j)%2 == 0)
          match[i*M+j] = (i-1)*M + j;
      }

      if(par == -1)
        roots[(i + j)%2].push_back(i*M+j);
      else
        Adj[par].push_back(i*M+j);
    }
  }

  for(int j : roots[1])
    dfs1(j);

  for(int j : roots[0])
    dfs0(j);

  std::cout << ans << std::endl;

  return 0;
}