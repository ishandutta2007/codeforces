#include <iostream>

#define int long long
#define MAXN 500005
#define left id+1
#define mid (l+r)/2
#define right id+2*(mid-l+1)

int seg[2*MAXN];
int n;

int gcd(int a, int b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

void upd(int x, int val, int id = 0, int l = 0, int r = n-1) {
  if(l == r) {
    seg[id] = val;
    return;
  }

  if(x <= mid)
    upd(x, val, left, l, mid);
  else
    upd(x, val, right, mid+1, r);

  seg[id] = gcd(seg[left], seg[right]);
}

int findSeg(int x, int id, int l, int r) {
  if(seg[id]%x == 0)
    return 0;
  if(l == r)
    return 1;
  if(seg[left]%x == 0)
    return findSeg(x, right, mid+1, r);
  if(seg[right]%x == 0)
    return findSeg(x, left, l, mid);
  return 2;
}

int query(int x, int y, int val, int id = 0, int l = 0, int r = n-1) {
  if(y < l || r < x)
    return 0;

  if(x <= l && r <= y)
    return findSeg(val, id, l, r);

  return query(x, y, val, left, l, mid) + query(x, y, val, right, mid+1, r);
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n;

  for(int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    upd(i, val);
  }

  int q;
  std::cin >> q;

  while(q--) {
    int t;
    std::cin >> t;

    if(t == 1) {
      int l, r, x;
      std::cin >> l >> r >> x;
      l--; r--;
      if(query(l, r, x) > 1)
        std::cout << "NO";
      else
        std::cout << "YES";
      std::cout << std::endl;
    }
    else {
      int id, val;
      std::cin >> id >> val;
      id--;
      upd(id, val);
    }
  }

  return 0;
}