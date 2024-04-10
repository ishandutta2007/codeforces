#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int INF = 1000'000'009;

int n;

struct seg
{
  std::vector<int> arr;

  void update(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(r < x || y < l)
      return;

    if(x <= l && r <= y) {
      arr[id] += v;
      return;
    }

    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);
  }

  int get(int x, int v = 0, int id = 0, int l = 0, int r = n-1) {
    v += arr[id];
    if(l == r)
      return v;
    if(x <= mid)
      return get(x, v, left, l, mid);
    else
      return get(x, v, right, mid+1, r);
  }
} tree;

int inc;

void erase(int i) {
  if(i == 0 || i == n)
    return;
  int x = tree.get(i);
  int y = tree.get(i-1);
  if(x > y)
    inc -= x-y;
}

void add(int i) {
  if(i == 0 || i == n)
    return;
  int x = tree.get(i);
  int y = tree.get(i-1);
  if(x > y)
    inc += x-y;
}

int far2(int x) {
  if(x%2 == 0)
    return x/2;
  if(x < 0)
    return x/2;
  return (x+1)/2;
}

int answer() {
  return far2(tree.get(0) + inc);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n;
  tree.arr = std::vector<int>(2*n-1, 0);
  
  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    tree.update(i, i, x);
    add(i);
  }

  std::cout << answer() << std::endl;
  int q;
  std::cin >> q;
  for(int i = 0; i < q; i++) {
    int l, r, x;
    std::cin >> l >> r >> x;
    l--; r--;
    erase(l);
    erase(r+1);
    tree.update(l, r, x);
    add(l);
    add(r+1);
    std::cout << answer() << std::endl;
  }

  return 0;
}