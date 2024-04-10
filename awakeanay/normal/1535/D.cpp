#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int n;

struct seg
{
  std::vector<int> min, minc, lazy;

  void push(int id, int l, int r) {
    if(lazy[id]) {
      min[left] += lazy[id];
      min[right] += lazy[id];
      lazy[left] += lazy[id];
      lazy[right] += lazy[id];
      lazy[id] = 0;
    }
  }

  int gval(int x, int id = 0, int l = 0, int r = n-1) {
    if(l == r)
      return min[id];
    push(id, l, r);
    if(x <= mid)
      return gval(x, left, l, mid);
    else
      return gval(x, right, mid+1, r);
  }

  void update(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] += v;
      min[id] += v;
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    min[id] = std::min(min[left], min[right]);
    minc[id] = 0;
    if(min[id] == min[left])
      minc[id] += minc[left];
    if(min[id] == min[right])
      minc[id] += minc[right];
  }

  void build(int id = 0, int l = 0, int r = n-1) {
    min[id] = 0;
    minc[id] = r-l+1;
    if(l < r) {
      build(left, l, mid);
      build(right, mid+1, r);
    }
  }
};

seg tree;

int eval(char c) {
  return (c-'0');
}

void result(int l, int r, int res, int inv) {
  if(res == 0) {
    tree.update(mid+1, r, inv);
  }
  else if(res == 1) {
    tree.update(l, mid, inv);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k;
  std::cin >> k;

  n = (1 << k);
  int m = n-1;

  tree.min = tree.minc = tree.lazy = std::vector<int>(2*n-1, 0);
  tree.build();

  int lo[m], hi[m];

  int cnt = 0;
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < n; j += (1 << (i+1))) {
      lo[cnt] = j;
      hi[cnt] = j + (1 << (i+1)) - 1;
      cnt++;
    }
  }

  std::string s;
  std::cin >> s;

  for(int i = 0; i < m; i++) {
    result(lo[i], hi[i], eval(s[i]), 1);
  }

  int q;
  std::cin >> q;

  while(q--) {
    int p;
    char c;
    std::cin >> p >> c;
    p--;
    result(lo[p], hi[p], eval(s[p]), -1);
    s[p] = c;
    result(lo[p], hi[p], eval(s[p]), 1);

    if(tree.min[0] != 0)
      std::cout << 0 << std::endl;
    else
      std::cout << tree.minc[0] << std::endl;
  }

  return 0;
}