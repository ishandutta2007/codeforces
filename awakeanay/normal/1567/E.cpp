#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

struct node
{
  int lft, rght;
  int suff, pref, len;
  int ans;

  node add(node b) {
    node next;
    next.ans = ans + b.ans;
    next.suff = b.suff + (b.suff == b.len && rght <= b.lft)*suff;
    next.pref = pref + (pref == len && rght <= b.lft)*b.pref;
    next.len = len + b.len;
    if(rght <= b.lft)
      next.ans += suff*b.pref;
    next.lft = len ? lft : b.lft;
    next.rght = b.len ? b.rght : rght;
    return next;
  }

  void create(int x) {
    lft = rght = x;
    pref = suff = 1;
    len = 1;
    ans = 1;
  }
};

node empty;

int n, q;

struct seg
{
  std::vector<node> arr;

  void update(int x, int v, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      arr[id].create(v);
      return;
    }

    if(x <= mid)
      update(x, v, left, l, mid);
    else
      update(x, v, right, mid+1, r);

    arr[id] = arr[left].add(arr[right]);
  }

  node query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return empty;

    if(x <= l && r <= y)
      return arr[id];

    node a = query(x, y, left, l, mid);
    return a.add(query(x, y, right, mid+1, r));
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> q;

  seg tree;
  tree.arr = std::vector<node>(2*n-1);

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    tree.update(i, x);
  }

  while(q--) {
    int t;
    std::cin >> t;

    if(t == 1) {
      int x, v;
      std::cin >> x >> v;
      x--;
      tree.update(x, v);
    }
    else {
      int l, r;
      std::cin >> l >> r;
      l--; r--;
      std::cout << tree.query(l, r).ans << std::endl;
    }
  }

  return 0;
}