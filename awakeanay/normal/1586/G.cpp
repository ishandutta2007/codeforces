#include <iostream>
#include <set>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int MAXN = 400005;
const int MOD = 1000000007;

int bit[MAXN];
int N;

struct seg
{
  std::vector<int> arr;
  
  void update(int x, int v, int id = 0, int l = 0, int r = N-1) {
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

  int max(int x, int y, int id = 0, int l = 0, int r = N-1) {
    if(y < l || r < x)
      return -1;

    if(x <= l && r <= y)
      return arr[id];

    return std::max(max(x, y, left, l, mid), max(x, y, right, mid+1, r));
  }
};

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    bit[x] %= MOD;
    x += x&(-x);
  }
}

int sum(int x) {
  int ret = 0;
  x += 1;
  while(x > 0) {
    ret += bit[x];
    ret %= MOD;
    x -= x&(-x);
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int pos[2*n];
  int bn[n];
  N = 2*n;
  seg tree;
  tree.arr = std::vector<int>(2*N-1, -1);

  for(int i = 0; i < n; i++) {
    int a, b;
    std::cin >> a >> b;
    a--; b--;
    bn[i] = b;
    pos[a] = b;
    pos[b] = a;
  }

  int t;
  std::cin >> t;

  std::vector<int> choose(2*n, 0);
  for(int i = 0; i < t; i++) {
    int x;
    std::cin >> x;
    x--;
    tree.update(bn[x], pos[bn[x]]);
  }

  for(int i = 2*n-1; i >= 0; i--) {
    if(pos[i] < i && tree.max(i, N-1) >= pos[i]) {
      choose[i] = 1;
    }
  }

  int next = 0;
  int ans = 0;
  for(int i = 2*n-1; i >= 0; i--) {
    if(pos[i] < i) {
      int tele = sum(pos[i]);
      tele += choose[i];
      tele %= MOD;
      ans = (ans + tele)%MOD;
      add(pos[i], tele);
      next = (next + tele)%MOD;
    }
    else {
      int tele = (sum(i) - sum(i-1) + MOD)%MOD;
      next = (next-tele+MOD)%MOD;
    }
  }

  std::cout << ans << std::endl;

  return 0;
}