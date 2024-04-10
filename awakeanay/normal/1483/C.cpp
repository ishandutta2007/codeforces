#include <iostream>
#include <vector>

#define int long long
#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int INF = 100000000000000000;

int n;

struct seg
{
  std::vector<int> vec;
  
  void upd(int x, int val, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      vec[id] = val;
      return;
    }

    if(x <= mid)
      upd(x, val, left, l, mid);
    else
      upd(x, val, right, mid+1, r);

    vec[id] = std::max(vec[left], vec[right]);
  }

  int query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return -INF;

    if(x <= l && r <= y)
      return vec[id];

    return std::max(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

signed main() {
  std::cin >> n;
  n++;

  int h[n], b[n];
  int ans[n];
  seg tree;
  tree.vec.resize(2*n-1);

  h[0] = 0; ans[0] = 0;
  for(int i = 1; i < n; i++)
    std::cin >> h[i];
  for(int i = 1; i < n; i++)
    std::cin >> b[i];

  int back[n];
  for(int i = 1; i < n; i++) {
    back[i] = i-1;
    while(h[back[i]] > h[i])
      back[i] = back[back[i]];
  }

  for(int i = 1; i < n; i++) {
    ans[i] = b[i] + tree.query(back[i], i-1);
    if(back[i])
      ans[i] = std::max(ans[i], ans[back[i]]);
    tree.upd(i, ans[i]);
  }

  std::cout << ans[n-1] << std::endl;

  return 0;
}