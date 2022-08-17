#include <iostream>

#define int long long

const int MAXN = 3005;
const int INF = (1ll << 32);
const int LOG = 30;

int par[MAXN];
int a[MAXN];
int n;

int root(int u) {
  if(par[u] < 0)
    return u;
  return par[u] = root(par[u]);
}

void merge(int u, int v) {
  u = root(u);
  v = root(v);

  if(u == v)
    return;

  if(par[u] > par[v])
    u ^= v ^= u ^= v;
  
  par[u] += par[v];
  par[v] = u;
}

int b[MAXN];
int c[MAXN];
int d[MAXN];

int solve() {
  for(int i = 0; i < n+LOG; i++)
    par[i] = -1;
  for(int i = 0; i < n; i++) {
    c[i] = b[i];
    for(int j = 0; j < LOG; j++)
      if((b[i] >> j)&1)
        merge(i+LOG, j);
  }

  int req = 0;
  bool done = true;
  for(int i = 1; i < n; i++)
    if(root(i+LOG) != root(LOG))
      done = false;

  if(!done) {
    for(int i = 0; i < n; i++) {
      if(root(0) != root(i+LOG)) {
        merge(0, i+LOG);
        c[i]++;
        req++;
      }
    }
  }

  return req;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int best;
    for(int j = 0; j < n; j++)
      b[j] = a[j];

    best = solve();
    for(int i = 0; i < n; i++)
      d[i] = c[i];

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++)
        b[j] = a[j];
      for(int j = 1; j < LOG; j++) {
        if((a[i] >> j)&1) {
          int req = (((1 << j)-1)&a[i])+1;
          if(req > best)
            continue;
          b[i] = a[i] - req;
          int next = req + solve();
          if(next < best) {
            best = next;
            for(int i = 0; i < n; i++)
              d[i] = c[i];
          }
        }
      }
    }

    std::cout << best << "\n";
    for(int i = 0; i < n; i++)
      std::cout << d[i] << " ";
    std::cout << "\n";
  }

  return 0;
}