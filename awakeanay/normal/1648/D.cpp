#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int INF = 100000000000000000;
const int MAXN = 500005;

struct node
{
  int mx, my, mf;
};

node merge(const node &a, const node &b) {
  node c;
  c.mx = std::max(a.mx, b.mx);
  c.my = std::max(a.my, b.my);
  c.mf = std::max(a.mf, b.mf);
  c.mf = std::max(c.mf, a.mx + b.my);
  return c;
}

node init(int x, int y) {
  node r;
  r.mx = x;
  r.my = y;
  r.mf = x + y;
  return r;
}

int x[MAXN], y[MAXN];
int n;

struct seg2
{
  std::vector<node> arr;

  void build(int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      arr[id] = init(x[l], y[r]);
      return;
    }

    build(left, l, mid);
    build(right, mid+1, r);

    arr[id] = merge(arr[left], arr[right]);
  }

  node query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return {-INF, -INF, -INF};

    if(x <= l && r <= y)
      return arr[id];

    return merge(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

struct seg1
{
  std::vector<int> arr;

  void update(int x, int v, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      arr[id] = std::max(arr[id], v);
      return;
    }

    if(x <= mid)
      update(x, v, left, l, mid);
    else
      update(x, v, right, mid+1, r);

    arr[id] = std::max(arr[left], arr[right]);
  }

  int query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return -INF;

    if(x <= l && r <= y)
      return arr[id];

    return std::max(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

#define fi first
#define se second

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int q;
  std::cin >> n >> q;

  int a[3][n];
  int p[3][n];

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < n; j++) {
      std::cin >> a[i][j];
      p[i][j] = a[i][j];
      if(j)
        p[i][j] += p[i][j-1];
    }
  }

  std::pair<std::pair<int, int>, int> qs[q];
  for(int i = 0; i < q; i++) {
    std::cin >> qs[i].fi.fi >> qs[i].fi.se >> qs[i].se;
    qs[i].fi.fi--;
    qs[i].fi.se--;
  }

  std::sort(qs, qs+q);

  seg1 tree1;
  tree1.arr = std::vector<int>(2*n-1, -INF);

  for(int i = 0; i < n; i++) {
    int u = p[1][i] + p[2][n-1];
    if(i)
      u -= p[2][i-1];
    tree1.update(i, u);
  }

  for(int i = 0; i < n; i++) {
    x[i] = p[0][i];
    if(i)
      x[i] -= p[1][i-1];
    //std::cout << x[i] << " ";
  }
  //std::cout << std::endl;

  for(int i = q-1; i >= 0; i--) {
    if(qs[i].fi.fi == 0)
      continue;

    int u = qs[i].fi.fi-1;
    int v = tree1.query(qs[i].fi.fi, qs[i].fi.se) - qs[i].se;
    tree1.update(u, v);
  }

  for(int i = 0; i < n; i++) {
    y[i] = tree1.query(i, i);
  }

  seg2 tree2;
  tree2.arr = std::vector<node>(2*n-1);
  tree2.build();

  int ans = -INF;
  for(int i = 0; i < q; i++) {
    ans = std::max(ans, tree2.query(qs[i].fi.fi, qs[i].fi.se).mf - qs[i].se);
  }

  std::cout << ans << std::endl;

  return 0;
}