#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int MAXN = 300005;
const int MOD = 1'000'000'009;

int n;
int fib[MAXN], fib_sum[MAXN];

// returns fib(n) if fib(0) = x and fib(1) = y
int getFib(int x, int y, int n) {
  return (y*fib[n] + x*fib[n-1])%MOD;
}

// return sum of first n fibonacci numbers
// if fib(0) = x and fib(1) = y
int getFibSum(int x, int y, int n) {
  return (y*fib_sum[n] + x*(fib_sum[n-1]+1))%MOD;
}

struct seg
{
  std::vector<int> arr, lazy[2];

  void push(int id, int l, int r) {
    if(lazy[0][id] || lazy[1][id]) {
      int cur_right[2] = {getFib(lazy[0][id], lazy[1][id], mid-l+1),
                          getFib(lazy[0][id], lazy[1][id], mid-l+2)};
      lazy[0][left] = (lazy[0][id] + lazy[0][left])%MOD;
      lazy[1][left] = (lazy[1][id] + lazy[1][left])%MOD;
      lazy[0][right] = (cur_right[0] + lazy[0][right])%MOD;
      lazy[1][right] = (cur_right[1] + lazy[1][right])%MOD;
      arr[left] = (arr[left] + getFibSum(lazy[0][id], lazy[1][id], mid-l+1))%MOD;
      arr[right] = (arr[right] + getFibSum(cur_right[0], cur_right[1], r-mid))%MOD;
      lazy[0][id] = lazy[1][id] = 0;
    }
  }

  int query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return 0;

    if(x <= l && r <= y)
      return arr[id];

    push(id, l, r);
    return (query(x, y, left, l, mid) + query(x, y, right, mid+1, r))%MOD;
  }

  void update(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      int cur[2] = {getFib(0, 1, l-x+1), getFib(0, 1, l-x+2)};
      lazy[0][id] = (lazy[0][id] + cur[0])%MOD;
      lazy[1][id] = (lazy[1][id] + cur[1])%MOD;
      arr[id] += getFibSum(cur[0], cur[1], r-l+1);
      arr[id] %= MOD;
      return;
    }

    push(id, l, r);
    update(x, y, left, l, mid);
    update(x, y, right, mid+1, r);

    arr[id] = (arr[left] + arr[right])%MOD;
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  fib[0] = fib_sum[0] = 0;
  fib_sum[1] = 1;
  fib[1] = 1;

  for(int i = 2; i < MAXN; i++) {
    fib[i] = (fib[i-1] + fib[i-2])%MOD;
    fib_sum[i] = (fib_sum[i-1]+fib[i])%MOD;
  }

  for(int i = MAXN-1; i > 0; i--)
    fib_sum[i] = fib_sum[i-1];

  int m;
  std::cin >> n >> m;

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    if(i)
      a[i] = (a[i] + a[i-1])%MOD;
  }

  seg tree;
  tree.arr = tree.lazy[0] = tree.lazy[1] = std::vector<int>(2*n-1, 0);

  for(int i = 0; i < m; i++) {
    int t, l, r;
    std::cin >> t >> l >> r;
    l--; r--;
    if(t == 1) {
      tree.update(l, r);
    }
    else {
      std::cout << (a[r]-(l ? a[l-1] : 0) + MOD + tree.query(l, r))%MOD << std::endl;
    }
  }

  return 0;
}