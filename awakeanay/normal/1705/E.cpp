#include <iostream>
#include <vector>
 
#define int long long
 
#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))
 
const int MAXN = 400005;
 
int n;
 
std::pair<std::pair<int, int>, int> best;
int ans[MAXN];
 
struct seg
{
  std::vector<int> arr, lazy;
 
  void push(int id, int l, int r) {
    if(lazy[id] != -1) {
      lazy[left] = lazy[right] = lazy[id];
      arr[left] = (mid-l+1)*lazy[id];
      arr[right] = (r-mid)*lazy[id];
      lazy[id] = -1;
    }
  }
 
  void update(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;
 
    if(x <= l && r <= y) {
      lazy[id] = v;
      arr[id] = (r-l+1)*v;
      return;
    }
 
    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);
    arr[id] = arr[left] + arr[right];
  }

  int find(int id = 0, int l = 0, int r = n-1) {
    if(l == r)
      return l;
    push(id, l, r);
    if(arr[right])
      return find(right, mid+1, r);
    else
      return find(left, l, mid);
  }
 
  int query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return 0;
 
    if(x <= l && r <= y) {
      return arr[id];
    }
 
    push(id, l, r);
    return query(x, y, left, l, mid) + query(x, y, right, mid+1, r);
  }
 
  void sweep(int x, int y, int b, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;
 
    if(x <= l && r <= y) {
      int cur = arr[id];
      if(!b)
        cur = r-l+1-cur;
      if(cur)
        best = std::min(best, {{l, r}, id});
      return;
    }
 
    push(id, l, r);
    sweep(x, y, b, left, l, mid);
    sweep(x, y, b, right, mid+1, r);
  }
 
  int first(int b, int id, int l, int r) {
    if(l == r)
      return l;
    push(id, l, r);
    int cur = arr[left];
    if(!b)
      cur = mid-l+1-cur;
    if(cur)
      return first(b, left, l, mid);
    else
      return first(b, right, mid+1, r);
  }
 
  int getFirst(int x, int y, int b) {
    best = {{n, n}, n};
    sweep(x, y, b);
    return first(b, best.second, best.first.first, best.first.second);
  }
};
 
seg tree;
 
// add 2^x
void add(int x) {
  int f = tree.getFirst(x, n-1, 0);
  tree.update(f, f, 1);
  if(f > x) tree.update(x, f-1, 0);
}
 
// subtract 2^x
void subtract(int x) {
  int f = tree.getFirst(x, n-1, 1);
  tree.update(f, f, 0);
  if(f > x) tree.update(x, f-1, 1);
}

signed main() {
  n = MAXN;

  int N, q;
  std::cin >> N >> q;
  
  tree.arr = std::vector<int>(2*n-1, 0);
  tree.lazy = std::vector<int>(2*n-1, -1);
  int a[N];
  for(int i = 0; i < N; i++) {
    std::cin >> a[i];
    add(a[i]);
  }

  for(int i = 0; i < q; i++) {
    int k, l;
    std::cin >> k >> l;
    k--;
    subtract(a[k]);
    a[k] = l;
    add(a[k]);
    std::cout << tree.find() << "\n";
  }
}