#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

const int MAXN = 200005;

std::vector<int> par, end, start, gcd;

int gcf(int a, int b) {
  if(a == 0)
    return b;
  return gcf(b%a, a);
}

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
  gcd[u] = gcf(gcd[u], gcd[v]);
  start[u] = std::min(start[u], start[v]);
  end[u] = std::max(end[u], end[v]);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, p;
    std::cin >> n >> p;

    int a[n];
    std::vector<std::pair<int, int> > st;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      st.push_back({a[i], i});
    }

    par = end = start = gcd = std::vector<int>(n, 0);
    for(int i = 0; i < n; i++) {
      gcd[i] = a[i];
      par[i] = -1;
      end[i] = start[i] = i;
    }

    std::sort(st.begin(), st.end());
    int edges = 0;
    int ans = 0;

    for(int i = 0; i < n; i++) {
      if(st[i].first >= p) {
        break;
      }

      int u = st[i].second;
      int v = root(u);

      int next = u+1;
      while(next < n && root(u) != root(next) && a[next]%a[u] == 0) {
        merge(u, next);
        edges++;
        ans += st[i].first;
        next++;
      }
      
      next = u-1;
      while(next >= 0 && root(u) != root(next) && a[next]%a[u] == 0) {
        merge(u, next);
        edges++;
        ans += st[i].first;
        next--;
      }
    }
    
    ans += (n-1-edges)*p;

    std::cout << ans << std::endl;
  }

  return 0;
}