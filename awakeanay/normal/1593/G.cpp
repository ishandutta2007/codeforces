#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

struct node
{
  int len, par;
};

node merge(const node &a, const node &b) {
  node ret;
  if(a.par^(a.len%2)^b.par^1) {
    ret.par = a.par;
    ret.len = a.len + b.len;
  }
  else {
    if(a.len > b.len) {
      ret.par = a.par;
      ret.len = a.len-b.len;
    }
    else {
      ret.par = b.par^(a.len%2);
      ret.len = b.len-a.len;
    }
  }
  return ret;
}

int n;

struct seg
{
  std::vector<node> arr;

  void update(int x, int p, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      arr[id].par = p;
      arr[id].len = 1;
      return;
    }

    if(x <= mid)
      update(x, p, left, l, mid);
    else
      update(x, p, right, mid+1, r);

    arr[id] = merge(arr[left], arr[right]);
  }

  node query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return {0, 0};

    if(x <= l && r <= y)
      return arr[id];

    return merge(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    n = s.length();
    seg tree;
    tree.arr = std::vector<node>(2*n-1);

    for(int i = 0; i < n; i++) {
      if(s[i] == '(' || s[i] == ')')
        tree.update(i, 0);
      else
        tree.update(i, 1);
    }

    int q;
    std::cin >> q;

    while(q--) {
      int l, r;
      std::cin >> l >> r;
      l--; r--;
      std::cout << tree.query(l, r).len/2 << std::endl;
    }
  }

  return 0;
}