#include <iostream>
#include <queue>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int n;

struct seg
{
  std::vector<std::pair<int, int> > min, max;

  void update(int x, int v, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      min[id] = {v, x};
      max[id] = {v, x};
      return;
    }

    if(x <= mid)
      update(x, v, left, l, mid);
    else
      update(x, v, right, mid+1, r);

    min[id] = std::min(min[left], min[right]);
    max[id] = std::max(max[left], max[right]);
  }

  std::pair<int, int> minq(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return {n+1, -1};

    if(x <= l && r <= y)
      return min[id];

    return std::min(minq(x, y, left, l, mid), minq(x, y, right, mid+1, r));
  }

  std::pair<int, int> maxq(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return {-1, -1};

    if(x <= l && r <= y)
      return max[id];

    return std::max(maxq(x, y, left, l, mid), maxq(x, y, right, mid+1, r));
  }
};
seg tnlr, tplr, tpgr, tngr;

void disable(int u) {
  tplr.update(u, n+1);
  tpgr.update(u, n+1);
  tngr.update(u, -1);
  tnlr.update(u, -1);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int pgr[n], plr[n], ngr[n], nlr[n];
    for(int i = 0; i < n; i++) {
      pgr[i] = i-1;
      while(pgr[i] > -1 && a[pgr[i]] < a[i])
        pgr[i] = pgr[pgr[i]];
    }
    for(int i = 0; i < n; i++) {
      plr[i] = i-1;
      while(plr[i] > -1 && a[plr[i]] > a[i])
        plr[i] = plr[plr[i]];
    }
    for(int i = n-1; i >= 0; i--) {
      ngr[i] = i+1;
      while(ngr[i] < n && a[ngr[i]] < a[i])
        ngr[i] = ngr[ngr[i]];
    }
    for(int i = n-1; i >= 0; i--) {
      nlr[i] = i+1;
      while(nlr[i] < n && a[nlr[i]] > a[i])
        nlr[i] = nlr[nlr[i]];
    }

    tnlr.min = tnlr.max = tpgr.min = tpgr.max = tngr.min = tngr.max = tplr.min = tplr.max = std::vector<std::pair<int, int> >(2*n-1);

    for(int i = 0; i < n; i++) {
      tnlr.update(i, nlr[i]);
      tngr.update(i, ngr[i]);
      tplr.update(i, plr[i]);
      tpgr.update(i, pgr[i]);
    }

    std::vector<int> d(n, n+1);
    std::queue<int> bfsq;
    bfsq.push(0);
    d[0] = 0;
    disable(0);

    while(!bfsq.empty()) {
      int u = bfsq.front();
      bfsq.pop();

      if(u+1 < n) {
        if(a[u] > a[u+1]) {
          int r = ngr[u]-1;
          while(true) {
            std::pair<int, int> v = tplr.minq(u+1, r);
            if(v.first < u) {
              d[v.second] = d[u] + 1;
              bfsq.push(v.second);
              disable(v.second);
            }
            else
              break;
          }
        }
        else {
          int r = nlr[u]-1;
          while(true) {
            std::pair<int, int> v = tpgr.minq(u+1, r);
            if(v.first < u) {
              d[v.second] = d[u] + 1;
              bfsq.push(v.second);
              disable(v.second);
            }
            else
              break;
          }
        }
      }
      if(u-1 >= 0) {
        if(a[u] > a[u-1]) {
          int l = pgr[u]+1;
          while(true) {
            std::pair<int, int> v = tnlr.maxq(l, u-1);
            if(v.first > u) {
              d[v.second] = d[u] + 1;
              bfsq.push(v.second);
              disable(v.second);
            }
            else
              break;
          }
        }
        else {
          int l = plr[u]+1;
          while(true) {
            std::pair<int, int> v = tngr.maxq(l, u-1);
            if(v.first > u) {
              d[v.second] = d[u] + 1;
              bfsq.push(v.second);
              disable(v.second);
            }
            else
              break;
          }
        }
      }
    }

    std::cout << d[n-1] << std::endl;
  }

  return 0;
}