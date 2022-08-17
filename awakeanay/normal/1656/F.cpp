#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

const int MAXS = 7000000;
const int MAXM = 1e12+5;
const int INF = 1e18;

__int128 eval(std::pair<int, int> p, int x) {
  
  __int128 a = p.first;
  __int128 b = x;
  __int128 c = p.second;
  return a*b + c;
}

int free_id = 0;

int lc[MAXS], rc[MAXS];
std::pair<int, int> fn[MAXS];

int create() {
  lc[free_id] = rc[free_id] = -1;
  fn[free_id].second = INF;
  return free_id++;
}

void add_fn(std::pair<int, int> nx, int v, int l = -MAXM, int r = MAXM) {
  int m = (l+r)/2;
  bool lef = eval(nx, l) < eval(fn[v], l);
  bool mid = eval(nx, m) < eval(fn[v], m);

  if(mid) {
    std::swap(nx, fn[v]);
  }

  if(r-l == 1) {
    return;
  }
  else if(lef != mid) {
    if(lc[v] == -1)
      lc[v] = create();
    add_fn(nx, lc[v], l, m);
  }
  else {
    if(rc[v] == -1)
      rc[v] = create();
    add_fn(nx, rc[v], m, r);
  }
}

__int128 get(int x, int v, int l = -MAXM, int r = MAXM) {
  int m = (l+r)/2;
  __int128 cur = eval(fn[v], x);
  if(r-l == 1)
    return cur;
  else if(x < m) {
    if(lc[v] == -1)
      return cur;
    return std::min(cur, get(x, lc[v], l, m));
  }
  else {
    if(rc[v] == -1)
      return cur;
    return std::min(cur, get(x, rc[v], m, r));
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

    free_id = 0;
    int a[n];
    int root = create();
    int p1 = true, p2 = true;

    int s = 0;
    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      s += a[i];
    }

    std::sort(a, a+n);
    int c = 0;
    for(int i = 0; i+1 < n; i++) {
      c += a[i];
      int x = s + i*a[n-1] + (n-i-2)*a[0];
      int y = c*a[n-1] + (s-c)*a[0] - a[0]*a[n-1];
      add_fn({x, y}, root);
    }

    for(int i = 0; i < n; i++) {
      int x = (n-2)*a[i] + s;
      if(x <= 0)
        p1 = false;
      if(x >= 0)
        p2 = false;
      add_fn({x, (s-a[i])*a[i]}, root);
    }

    if(p1 || p2)
      std::cout << "INF" << std::endl;
    else {
      int l = 1-MAXM;
      int r = MAXM;

      while(l < r) {
        int m = l + (r-l)/2;
        if(get(m, root) < get(m-1, root))
          r = m;
        else
          l = m+1;
      }

      std::cout << ((int)get(l-1, root)) << std::endl;
    }
  }

  return 0;
}