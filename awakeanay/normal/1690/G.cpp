#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int INF = 1000'000'007;

int n;

struct seg1
{
  std::vector<int> arr, lazy;

  void push(int id, int l, int r) {
    if(lazy[id] != -1) {
      lazy[left] = lazy[right] = arr[left] = arr[right] = lazy[id];
      lazy[id] = -1;
    }
  }

  void upd(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      arr[id] = lazy[id] = v;
      return;
    }

    push(id, l, r);
    upd(x, y, v, left, l, mid);
    upd(x, y, v, right, mid+1, r);
    arr[id] = std::min(arr[left], arr[right]);
  }

  int query(int v, int id = 0, int l = 0, int r = n-1) {
    if(l == r)
      return l;

    push(id, l, r);
    if(arr[left] < v)
      return query(v, left, l, mid);
    return query(v, right, mid+1, r);
  }
};

struct seg2
{
  std::vector<int> arr, lazy;

  void push(int id, int l, int r) {
    if(lazy[id] != -1) {
      lazy[left] = lazy[right] = lazy[id];
      arr[left] = (mid-l+1)*lazy[id];
      arr[right] = (r-mid)*lazy[id];
      lazy[id] = -1;
    }
  }

  void upd(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] = v;
      arr[id] = (r-l+1)*v;
      return;
    }

    push(id, l, r);
    upd(x, y, v, left, l, mid);
    upd(x, y, v, right, mid+1, r);
    arr[id] = arr[left] + arr[right];
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int N, m;
    std::cin >> N >> m;

    n = N+1;

    seg1 tree1;
    seg2 tree2;

    tree1.arr = std::vector<int>(2*n-1, INF);
    tree1.lazy = tree2.lazy = std::vector<int>(2*n-1, -1);
    tree2.arr = std::vector<int>(2*n-1, 0);
    tree2.upd(N, N, 0);
    tree1.upd(N, N, 0);

    int a[n];
    int cmin = INF;
    for(int i = 0; i < N; i++) {
      std::cin >> a[i];
      a[i]++;
      if(a[i] < cmin) {
        cmin = a[i];
        tree2.upd(i, i, 1);
      }
      tree1.upd(i, i, cmin);
    }

    for(int i = 0; i < m; i++) {
      int k, d;
      std::cin >> k >> d;
      k--;

      if(d != 0) {
        int nx = a[k]-d;
        int j = tree1.query(nx);
        int u = tree1.query(nx+1);
        if(u > k) {
          tree2.upd(k, k, 1);
          tree1.upd(k, j-1, nx);
          tree2.upd(k+1, j-1, 0);
        }
        a[k] = nx;
      }

      std::cout << tree2.arr[0] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}