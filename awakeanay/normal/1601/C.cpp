#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int n, m;

const int MAXN = 1000006;

int bit[MAXN];

void add(int x, int v) {
  x += 1;
  while(x < MAXN) {
    bit[x] += v;
    x += x&(-x);
  }
}

int sum(int x) {
  x += 1;
  int ret = 0;
  while(x > 0) {
    ret += bit[x];
    x -= x&(-x);
  }
  return ret;
}

struct seg
{
  std::vector<int> arr, lazy;

  void push(int id, int l, int r) {
    if(lazy[id] == 0)
      return;

    arr[left] += lazy[id];
    arr[right] += lazy[id];
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];

    lazy[id] = 0;
  }

  void update(int x, int y, int val, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] += val;
      arr[id] += val;
      return;
    }

    push(id, l, r);
    update(x, y, val, left, l, mid);
    update(x, y, val, right, mid+1, r);

    arr[id] = std::min(arr[left], arr[right]);
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n >> m;

    seg tree;
    tree.arr = tree.lazy = std::vector<int>(2*n-1, 0);

    int cur[n];
    for(int i = 0; i < n; i++) {
      tree.update(i, n-1, 1);
      cur[i] = 1;
    }

    int nones = 0;
    std::pair<int, int> help[n];
    for(int i = 0; i < n; i++) {
      std::cin >> help[i].first;
      help[i].second = i;
      bit[i+1] = 0;
    }

    int b[m];
    for(int i = 0; i < m; i++)
      std::cin >> b[i];

    std::sort(help, help+n);
    std::sort(b, b+m);

    int init = 0;
    for(int i = 0; i < n; i++) {
      init += sum(n-1-help[i].second);
      add(n-1-help[i].second, 1);
    }

    int op = 0, zp = 0;
    int ans = 0;

    for(int i = 0; i < m; i++) {
      while(op < n && help[op].first <= b[i]) {
        tree.update(help[op].second, n-1, -1);
        op++;
      }

      while(zp < n && help[zp].first < b[i]) {
        tree.update(help[zp].second, n-1, -1);
        nones++;
        zp++;
      }

      ans += nones;
      ans += std::min(tree.arr[0], 0ll);
    }

    std::cout << ans+init << std::endl;
  }

  return 0;
}