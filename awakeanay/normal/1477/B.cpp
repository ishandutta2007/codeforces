#include <iostream>
#include <vector>

#define int long long
#define mid (l+r)/2
#define left id+1
#define right id+2*(mid-l+1)
int n;

struct seg
{
  std::vector<int> arr, lazy;

  void push(int id, int l, int r) {
    if(lazy[id] == -1)
      return;

    arr[left] = (mid-l+1)*lazy[id];
    arr[right] = (r-mid)*lazy[id];
    lazy[left] = lazy[right] = lazy[id];
    lazy[id] = -1;
  }

  void update(int x, int y, int val, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] = val;
      arr[id] = val*(r-l+1);
      return;
    }

    push(id, l, r);
    update(x, y, val, left, l, mid);
    update(x, y, val, right, mid+1, r);
    arr[id] = arr[left] + arr[right];
  }

  int query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return 0;

    if(x <= l && r <= y) {
      return arr[id];
    }

    push(id, l, r);
    return query(x, y, left, l, mid) + query(x, y, right, mid+1, r);
  }
};

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int q;
    std::cin >> n >> q;

    std::string s, f;
    std::cin >> s >> f;

    seg cur;
    cur.lazy = std::vector<int>(2*n-1, -1);
    cur.arr = std::vector<int>(2*n-1, 0);
    bool poss = true;

    for(int i = 0; i < n; i++)
      cur.update(i, i, f[i] == '1');

    std::vector<std::pair<int, int> > que;
    for(int i = 0; i < q; i++) {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      que.push_back({u, v});
    }

    for(int i = q-1; i >= 0; i--) {
      int l = que[i].first, r = que[i].second;
      int sz = r-l+1;
      int sum = cur.query(l, r);

      if(sum*2 == sz) {
        poss = false;
        break;
      }
      else if(sum*2 < sz) {
        cur.update(l, r, 0);
      }
      else
        cur.update(l, r, 1);
    }

    for(int i = 0; i < n; i++)
      poss &= cur.query(i, i) == s[i] - '0';

    if(poss)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}