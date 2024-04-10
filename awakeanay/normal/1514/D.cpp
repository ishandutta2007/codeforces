#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int n, q;

std::pair<int, int> merge(std::pair<int, int> a, std::pair<int, int> b) {
    std::pair<int, int> res;
    if(a.first == b.first) {
      res = {a.first, a.second+b.second};
    }
    else if(a.second > b.second) {
      res = {a.first, a.second-b.second};
    }
    else {
      res = {b.first, b.second-a.second};
    }
    return res;
}

struct seg
{
  std::vector<std::pair<int, int> > arr;

  void build(int input[], int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      arr[id] = {input[l], 1};
      return;
    }

    build(input, left, l, mid);
    build(input, right, mid+1, r);

    arr[id] = merge(arr[left], arr[right]);
  }

  std::pair<int, int> query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(x <= l && r <= y)
      return arr[id];

    if(r < x || y < l)
      return {-1, 0};

    std::pair<int, int> a = query(x, y, left, l, mid);
    std::pair<int, int> b = query(x, y, right, mid+1, r);
    return merge(a, b);
  }
};

signed main() {
  std::cin >> n >> q;
  int seq[n];

  std::vector<int> pos[n];
  for(int i = 0; i < n; i++) {
    std::cin >> seq[i];
    seq[i]--;
    pos[seq[i]].push_back(i);
  }

  seg tree;
  tree.arr = std::vector<std::pair<int, int> >(2*n-1);
  tree.build(seq);

  while(q--) {
    int l, r;
    std::cin >> l >> r;
    l--; r--;

    std::pair<int, int> opt = tree.query(l, r);
    if(opt.first == -1) {
      std::cout << 1 << std::endl;
      continue;
    }
    else {
      int u = opt.first;
      int gc = std::upper_bound(pos[u].begin(), pos[u].end(), r)-std::lower_bound(pos[u].begin(), pos[u].end(), l);
      int inv = r-l+1-gc;
      std::cout << std::max(1ll, gc-inv) << std::endl;
    }
  }

  return 0;
}