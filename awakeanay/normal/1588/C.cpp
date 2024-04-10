#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int INF = 1000'000'000'000'00000;

struct node
{
  int min[2], minc[2], len;
} empty;

int done = 0;
int ansreq;

node merge(const node& a, const node& b) {
  node next;
  next.len = a.len + b.len;
  for(int i = 0; i < 2; i++) {
    int j = i;
    next.min[i] = std::min(a.min[i], b.min[j]);
    next.minc[i] = 0;
    if(b.min[j] == next.min[i]) {
      next.minc[i] += b.minc[j];
    }
    if(a.min[i] == next.min[i]) {
      next.minc[i] += a.minc[i];
    }
  }

  return next;
}

int n;

struct seg
{
  std::vector<int> lazy;
  std::vector<node> arr;

  void apply(int v, int id) {
    if(arr[id].min[0] != INF)
      arr[id].min[0] += v;
    if(arr[id].min[1] != INF)
      arr[id].min[1] -= v;
  }

  int searchSeg(int id, int l, int r) {
    if(l == r)
      return l;
    push(id, l, r);
    if(arr[left].min[0] < 0 || arr[left].min[1] < 0)
      return searchSeg(left, l, mid);
    else
      return searchSeg(right, mid+1, r);
  }

  void getN(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(done)
      return;
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      if(arr[id].min[0] < 0 || arr[id].min[1] < 0) {
        done = 1;
        ansreq = searchSeg(id, l, r);
      }
      return;
    }

    push(id, l, r);
    getN(x, y, left, l, mid);
    getN(x, y, right, mid+1, r);
  }

  void build(int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      int x = l&1;
      arr[id] = {{x ? INF : 0, x ? 0 : INF}, {!x, x}, 1};
      return;
    }

    build(left, l, mid);
    build(right, mid+1, r);
  }

  void push(int id, int l, int r) {
    if(lazy[id]) {
      lazy[left] += lazy[id];
      lazy[right] += lazy[id];

      apply(lazy[id], left);
      apply(lazy[id], right);

      lazy[id] = 0;
    }
  }

  // add v to even indices
  // subtract v from odd
  void update(int x, int y, int v,  int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      apply(v, id);
      lazy[id] += v;
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    arr[id] = merge(arr[left], arr[right]);
  }

  node query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return empty;

    if(x <= l && r <= y) {
      return arr[id];
    }

    push(id, l, r);
    return merge(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  empty = {{INF, INF}, {0, 0}, 0};

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    seg tree;
    tree.lazy = std::vector<int>(2*n-1, 0);
    tree.arr = std::vector<node>(2*n-1);
    tree.build();
    
    int cur = 0;
    for(int i = 0; i < n; i++) {
      cur = a[i]-cur;
      int up = i%2 ? -cur : cur;
      tree.update(i, i, up);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
      /*
      for(int j = 0; j < n; j++) {
        node cur = tree.query(j, j);
        std::cout << std::min(cur.min[0], cur.min[1]) << " ";
      }
      std::cout << std::endl;
      */

      node next = tree.query(i, n-1);
      int minc = 0, lid = n+1;
      int min = std::min(next.min[0], next.min[1]);

      int hi = n;
      if(min < 0) {
        done = 0;
        tree.getN(i, n-1);
        hi = ansreq;
      }

      //std::cout << hi << std::endl;

      if(hi > i) {
        node next = tree.query(i, hi-1);
        int minc = 0, lid = n+1;
        int min = std::min(next.min[0], next.min[1]);
        for(int j = 0; j < 2; j++) {
          if(min == next.min[j]) {
            minc += next.minc[j];
          }
        }
        if(min == 0)
          ans += minc;
      }

      int up = i%2 ? a[i] : -a[i];
      tree.update(i, n-1, up);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}