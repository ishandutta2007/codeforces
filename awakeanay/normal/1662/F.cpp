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
  std::vector<std::pair<int, int> > arr;

  void update(int x, int v, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      arr[id] = {v, x};
      return;
    }

    if(x <= mid)
      update(x, v, left, l, mid);
    else
      update(x, v, right, mid+1, r);

    arr[id] = std::min(arr[left], arr[right]);
  }

  std::pair<int, int> query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return {2*n+1, 2*n+1};

    if(x <= l && r <= y)
      return arr[id];

    return std::min(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int a, b;
    std::cin >> n >> a >> b;
    a--; b--;

    int p[n];
    for(int i = 0; i < n; i++)
      std::cin >> p[i];

    seg ltree, rtree;
    ltree.arr = rtree.arr = std::vector<std::pair<int, int> >(2*n-1);
    for(int i = 0; i < n; i++) {
      ltree.update(i, i-p[i]);
      rtree.update(i, -p[i]-i);
    }

    std::queue<int> bfsq;
    std::vector<int> d(n, n+1);
    d[a] = 0;
    bfsq.push(a);
    ltree.update(a, 2*n+1);
    rtree.update(a, 2*n+1);

    while(!bfsq.empty()) {
      int u = bfsq.front();
      bfsq.pop();

      int r = std::min(n-1, u+p[u]);
      while(true) {
        std::pair<int, int> v = ltree.query(u, r);
        if(v.first <= u) {
          bfsq.push(v.second);
          d[v.second] = d[u] + 1;
          ltree.update(v.second, 2*n+1);
          rtree.update(v.second, 2*n+1);
        }
        else
          break;
      }

      int l = std::max(0ll, u-p[u]);
      while(true) {
        std::pair<int, int> v = rtree.query(l, u);
        v.first *= -1;
        if(v.first >= u) {
          bfsq.push(v.second);
          d[v.second] = d[u] + 1;
          ltree.update(v.second, 2*n+1);
          rtree.update(v.second, 2*n+1);
        }
        else
          break;
      }
    }

    std::cout << d[b] << "\n";
  }

  return 0;
}