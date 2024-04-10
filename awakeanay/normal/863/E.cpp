#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int INF = 1000000000;

int sz;

struct seg
{
  std::vector<int> tree, lazy;

  void push(int id, int l, int r) {
    if(lazy[id] == 0)
      return;
    tree[left] += lazy[id];
    tree[right] += lazy[id];
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];
    lazy[id] = 0;
  }

  void update(int x, int y, int val, int id = 0, int l = 0, int r = sz-1) {
    if(r < x || y < l)
      return;

    if(x <= l && r <= y) {
      tree[id] += val;
      lazy[id] += val;
      return;
    }

    push(id, l, r);
    update(x, y, val, left, l, mid);
    update(x, y, val, right, mid+1, r);

    tree[id] = std::min(tree[left], tree[right]);
  }

  int query(int x, int y, int id = 0, int l = 0, int r = sz-1) {
    if(y < l || r < x)
      return INF;

    if(x <= l && r <= y)
      return tree[id];

    push(id, l, r);
    return std::min(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

signed main() {
  int n;
  std::cin >> n;

  std::vector<std::pair<int, int> > arr;
  int orig[2*n];
  for(int i = 0; i < 2*n; i++) {
    int x;
    std::cin >> x;
    arr.push_back({x, i});
    arr.push_back({x-1, -1});
    arr.push_back({x+1, -1});
  }

  std::sort(arr.begin(), arr.end());

  seg tree;
  sz = 6*n+5;
  tree.tree = tree.lazy = std::vector<int>(2*sz-1, 0);

  int cur_val = 0;
  for(int i = 0; i < arr.size(); i++) {
    if(i && arr[i-1].first < arr[i].first)
      cur_val++;
    if(arr[i].second > -1)
      orig[arr[i].second] = cur_val;
  }

  for(int i = 0; i < n; i++) {
    tree.update(orig[2*i], orig[2*i+1], 1);
  }

  int ans = -1;
  for(int i = 0; i < n; i++) {
    if(tree.query(orig[2*i], orig[2*i+1]) > 1) {
      ans = i+1;
      break;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}