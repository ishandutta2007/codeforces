#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int N;

struct node
{
  int pre, suff, best;
};

struct change
{
  int pre, suff;
};

node merge(node a, node b) {
  node ret;
  ret.pre = std::min(a.pre, b.pre);
  ret.suff = std::min(a.suff, b.suff);
  ret.best = std::min(a.best, b.best);
  ret.best = std::min(ret.best, a.pre + b.suff);
  return ret;
}

node apply(node a, change b) {
  a.pre += b.pre;
  a.suff += b.suff;
  a.best += b.pre + b.suff;
  return a;
}

change apply(change a, change b) {
  a.pre += b.pre;
  a.suff += b.suff;
  return a;
}

struct seg
{
  std::vector<node> arr;
  std::vector<change> lazy;

  void push(int id, int l, int r) {
    arr[left] = apply(arr[left], lazy[id]);
    arr[right] = apply(arr[right], lazy[id]);
    lazy[left] = apply(lazy[left], lazy[id]);
    lazy[right] = apply(lazy[right], lazy[id]);
    lazy[id] = {0, 0};
  }

  void update(int x, int y, change v, int id = 0, int l = 0, int r = N-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] = apply(lazy[id], v);
      arr[id] = apply(arr[id], v);
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    arr[id] = merge(arr[left], arr[right]);
  }

  node query(int x, int y, int id = 0, int l = 0, int r = N-1) {
    if(y < l || r < x)
      return {N+1, N+1, N+1};

    if(x <= l && r <= y)
      return arr[id];

    push(id, l, r);
    return merge(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }
};

seg tree;
int b_count;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;

  N = n+2;

  tree.arr = std::vector<node>(2*N-1, {0, 0, N+1});
  tree.lazy = std::vector<change>(2*N-1, {0, 0});

  std::string s;
  std::cin >> s;

  b_count = 0;

  int cur = 0;
  for(int i = 1; i <= n; i++) {
    if(s[i-1] == 'a')
      cur++;
    else if(s[i-1] == 'b') {
      cur--;
      b_count++;
    }
    tree.update(i, i, {cur, 0});
  }

  cur = 0;
  for(int i = n; i >= 1; i--) {
    if(s[i-1] == 'c')
      cur++;
    else if(s[i-1] == 'b')
      cur--;
    tree.update(i, i, {0, cur});
  }

  while(q--) {
    int x;
    char c;
    std::cin >> x >> c;

    if(s[x-1] == 'a') {
      tree.update(x, N-1, {-1, 0});
    }
    else if(s[x-1] == 'b') {
      b_count--;
      tree.update(x, N-1, {1, 0});
      tree.update(0, x, {0, 1});
    }
    else {
      tree.update(0, x, {0, -1});
    }

    s[x-1] = c;
    if(c == 'a') {
      tree.update(x, N-1, {1, 0});
    }
    else if(c == 'b') {
      b_count++;
      tree.update(x, N-1, {-1, 0});
      tree.update(0, x, {0, -1});
    }
    else {
      tree.update(0, x, {0, 1});
    }

    /*
    std::cout << "OK " << b_count << std::endl;
    for(int i = 0; i < N; i++) {
      std::cout << tree.query(i, i).pre << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < N; i++) {
      std::cout << tree.query(i, i).suff << " ";
    }
    std::cout << std::endl;
    */


    std::cout << b_count + tree.arr[0].best << std::endl;
  }

  return 0;
}