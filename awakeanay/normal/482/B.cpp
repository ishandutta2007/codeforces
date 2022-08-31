#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right id+2*(mid-l+1)

int n;

struct seg
{
  std::vector<int> arr, lazy;

  void push(int id, int l, int r) {
    arr[left] |= lazy[id];
    arr[right] |= lazy[id];
    lazy[left] |= lazy[id];
    lazy[right] |= lazy[id];
    lazy[id] = 0;
  }

  void update(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] |= v;
      arr[id] |= v;
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    arr[id] = arr[left] | arr[right];
  }

  int get(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return 0;

    if(x <= l && r <= y)
      return arr[id];

    push(id, l, r);
    return get(x, y, left, l, mid) | get(x, y, right, mid+1, r);
  }
};

struct seg2
{
  std::vector<int> arr, lazy;

  void push(int id, int l, int r) {
    arr[left] &= lazy[id];
    arr[right] &= lazy[id];
    lazy[left] &= lazy[id];
    lazy[right] &= lazy[id];
    lazy[id] = ~0;
  }

  void update(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] &= v;
      arr[id] &= v;
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    arr[id] = arr[left] & arr[right];
  }

  int get(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return ~0;

    if(x <= l && r <= y)
      return arr[id];

    push(id, l, r);
    return get(x, y, left, l, mid) & get(x, y, right, mid+1, r);
  }
};


signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int m;
  std::cin >> n >> m;

  seg tree;
  tree.arr = tree.lazy = std::vector<int>(2*n-1, 0);

  int l[m], r[m], q[m];
  for(int i = 0; i < m; i++) {
    std::cin >> l[i] >> r[i] >> q[i];
    l[i]--; r[i]--;
    tree.update(l[i], r[i], q[i]);
  }

  seg2 t2;
  t2.arr = t2.lazy = std::vector<int>(2*n-1, ~0);

  for(int i = 0; i < n; i++)
    t2.update(i, i, tree.get(i, i));

  bool poss = true;
  for(int i = 0; i < m; i++) {
    if(t2.get(l[i], r[i]) != q[i])
      poss = false;
  }

  if(poss) {
    std::cout << "YES" << std::endl;
    for(int i = 0; i < n; i++)
      std::cout << t2.get(i, i) << " ";
    std::cout << std::endl;
  }
  else
    std::cout << "NO" << std::endl;

  return 0;
}