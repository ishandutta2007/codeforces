#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int n;

struct save
{
  int assign;
  int mul;
  int offset;
};

struct node
{
  int a;
  long long b;
};

struct seg
{
  std::vector<save> lazy;
  std::vector<node> arr;

  void unset(int id) {
    lazy[id] = {-1, 0, 0};
  }

  void updLazy(int id, save upd) {
    lazy[id].offset += upd.offset;
    if(lazy[id].assign == -1) {
      lazy[id].mul += upd.mul;
    }
    else {
      lazy[id].offset += upd.mul*lazy[id].assign;
    }
    if(upd.assign != -1) 
      lazy[id].assign = upd.assign;
  }

  void apply(int id, int l, int r, save upd) {
    arr[id].b += (r-l+1)*upd.offset;
    arr[id].b += upd.mul*arr[id].a;
    if(upd.assign != -1) {
      arr[id].a = (r-l+1)*upd.assign;
    }
  }

  int testRandom() {
    save s1 = {rand()%5-1, rand()%5, rand()%5};
    save s2 = {rand()%5-1, rand()%5, rand()%5};
    lazy[0] = s1;
    updLazy(0, s2);
    save s3 = lazy[0];

    node init = {rand()%5, rand()%5};
    arr[0] = init;
    apply(0, 0, n-1, s1);
    apply(0, 0, n-1, s2);

    node o1 = arr[0];
    arr[0] = init;
    apply(0, 0, n-1, s3);
    node o2 = arr[0];
    bool ret = o1.a == o2.a && o1.b == o2.b;
    if(!ret) {
      std::cout << s1.assign << " " << s1.mul << " " << s1.offset << std::endl;
      std::cout << s2.assign << " " << s2.mul << " " << s2.offset << std::endl;
      std::cout << init.a << " " << init.b << std::endl;
    }
    return ret;
  }

  void push(int id, int l, int r) {
    apply(left, l, mid, lazy[id]);
    apply(right, mid+1, r, lazy[id]);
    updLazy(left, lazy[id]);
    updLazy(right, lazy[id]);
    unset(id);
  }

  node merge(const node &a, const node &b) {
    return {a.a + b.a, a.b + b.b};
  }

  void update(int x, int y, save upd, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      apply(id, l, r, upd);
      updLazy(id, upd);
      return;
    }

    push(id, l, r);
    update(x, y, upd, left, l, mid);
    update(x, y, upd, right, mid+1, r);

    arr[id] = merge(arr[left], arr[right]);
  }

  node query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return {0, 0};

    if(x <= l && r <= y)
      return arr[id];

    push(id, l, r);
    return merge(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

const int MAXN = 200005;
const int MAXQ = 1000006;

int p[MAXN];
int rev[MAXN];
std::pair<std::pair<int, int>, int> qs[MAXQ];
long long ans[MAXQ];
int prev[MAXN], next[MAXN];
seg tree;
std::vector<int> min;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int q;
  std::cin >> n >> q;

  for(int i = 0; i < n; i++) {
    std::cin >> p[i];
    rev[p[i]] = i;
  }

  for(int i = 0; i < q; i++) {
    int l, r;
    std::cin >> l >> r;
    l--; r--;
    qs[i] = {{l, r}, i};
  }

  std::sort(qs, qs+q);
  std::reverse(qs, qs+q);

  for(int i = 0; i < n; i++) {
    prev[i] = i-1;
    while(prev[i] != -1 && p[prev[i]] < p[i])
      prev[i] = prev[prev[i]];
  }
  for(int i = n-1; i >= 0; i--) {
    next[i] = i+1;
    while(next[i] != n && p[next[i]] < p[i])
      next[i] = next[next[i]];
  }

  tree.arr = std::vector<node>(2*n-1, {0, 0});
  tree.lazy = std::vector<save>(2*n-1, {-1, 0, 0});
  tree.update(0, n-1, {0, 0, 0});

  /*
  bool check = 1;
  srand(2342342);
  for(int i = 0; i < 1024; i++) {
    check &= tree.testRandom();
    if(!check)
      break;
  }
  std::cout << check << std::endl;
  return 0;
  */

  min = std::vector<int>(n+1, n);

  int ct = 0;
  for(int i = n-1; i >= 0; i--) {
    tree.update(i, next[i]-1, {0, 0, 0});
    for(int j = 1; p[i]*j <= n; j++) {
      if(j == p[i])
        continue;
      int k = p[i]*j;
      if(rev[j] >= i && rev[k] >= i) {
        int l = std::max(rev[j], rev[k]);
        int r = next[rev[k]]-1;
        if(prev[rev[k]] < i) {
          tree.update(l, r, {1, 0, 0});
        }
      }

      if(rev[k] <= i && i < rev[j]) {
        min[k] = std::min(min[k], rev[j]);
      }
    }

    tree.update(min[p[i]], next[i]-1, {1, 0, 0});
    tree.update(i, n-1, {-1, 1, 0});

    /*
    std::cout << i << std::endl;
    for(int i = 0; i < n; i++)
      std::cout << tree.query(i, i).a << " ";
    std::cout << std::endl;
    */

    while(ct < q && qs[ct].first.first == i) {
      ans[qs[ct].second] = tree.query(i, qs[ct].first.second).b;
      ct++;
    }
  }

  for(int i = 0; i < q; i++) {
    std::cout << ans[i] << "\n";
  }

  return 0;
}