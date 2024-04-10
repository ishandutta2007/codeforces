#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int n, k;

struct seg
{
  std::vector<int> arr, lazy;

  void push(int id, int l, int r) {
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];
    arr[left] += lazy[id];
    arr[right] += lazy[id];
    lazy[id] = 0;
  }

  void upd(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      arr[id] += v;
      lazy[id] += v;
      return;
    }

    push(id, l, r);
    upd(x, y, v, left, l, mid);
    upd(x, y, v, right, mid+1, r);

    arr[id] = std::max(arr[left], arr[right]);
  }
};

int len = 0;

seg tree;

bool check() {
  return tree.arr[0] >= k && len-(n-len) >= k;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n >> k;

    int a[n];
    std::pair<int, int> help[n];

    for(int i = 0; i < n; i++) {
      std::cin >> a[i];
      help[i] = {a[i], i};
    }

    std::sort(help, help+n);

    tree.arr = tree.lazy = std::vector<int>(2*n-1, 0);

    for(int i = 0; i < n; i++)
      tree.upd(i, n-1, -1);
    len = 0;

    int cl = 0, cr = 0;
    int best = n+1;
    int cx = -1, cy = -1;

    for(int i = 0; i < n; i++) {
      while(cr < n && !check()) {
        tree.upd(help[cr++].second, n-1, 2);
        len++;
      }

      if(!check())
        break;

      int x = help[i].first;
      int y = help[cr-1].first;

      if(y-x < best) {
        best = y-x;
        cx = x;
        cy = y;
      }

      tree.upd(help[i].second, n-1, -2);
      len--;
    }

    std::cout << cx << " " << cy << std::endl;
    int last = -1;
    int cur = 0;
    int done = 0;
    for(int i = 0; i < n; i++) {
      int ct = cx <= a[i] && a[i] <= cy;
      if(ct)
        cur++;
      else
        cur--;

      if(cur > 0) {
        done++;
        std::cout << last+2 << " ";
        std::cout << (done == k ? n : i+1) << std::endl;
        cur = 0;
        last = i;

        if(done == k)
          break;
      }
    }
  }

  return 0;
}