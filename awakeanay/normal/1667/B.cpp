#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int INF = 1000'000'000;

int N;

struct seg
{
  std::vector<int> arr;

  void upd(int x, int v, int id = 0, int l = 0, int r = N-1) {
    if(l == r) {
      arr[id] = std::max(arr[id], v);
      return;
    }

    if(x <= mid)
      upd(x, v, left, l, mid);
    else
      upd(x, v, right, mid+1, r);

    arr[id] = std::max(arr[left], arr[right]);
  }

  int query(int x, int y, int id = 0, int l = 0, int r = N-1) {
    if(y < l || r < x)
      return -INF;

    if(x <= l && r <= y)
      return arr[id];

    return std::max(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    N = n+1;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int b[n+1];
    b[0] = 0;
    for(int i = 1; i <= n; i++) {
      b[i] = a[i-1];
      b[i] += b[i-1];
    }

    std::sort(b, b+n+1);

    seg tree[3];
    for(int j = 0; j < 3; j++)
      tree[j].arr = std::vector<int>(2*N-1, -INF);

    int ans;

    int u = std::lower_bound(b, b+N, 0)-b;
    tree[0].upd(u, 1);
    tree[1].upd(u, 0);
    tree[2].upd(u, -1);

    int cur = 0;
    for(int i = 0; i < n; i++) {
      cur += a[i];

      ans = -INF;
      u = std::lower_bound(b, b+N, cur)-b;
      ans = std::max(ans, tree[0].query(0, u-1) + i);
      ans = std::max(ans, tree[1].query(u, u));
      ans = std::max(ans, tree[2].query(u+1, n) - i);

      tree[0].upd(u, ans-i);
      tree[1].upd(u, ans);
      tree[2].upd(u, ans+i);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}