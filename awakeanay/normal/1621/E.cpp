#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int MAXN = 200005;
const int INF = 1000'000'009;

std::vector<int> b[MAXN];
std::vector<int> c[MAXN];
int sum[MAXN];
int a[MAXN];

int N, n;

int find(int i, int j) {
  int k = b[i].size();
  k--;

  int lo = 0, hi = N;
  while(lo < hi) {
    int mi = (lo+hi)/2;

    if(a[mi]*(k-(j!=0)) >= sum[i]-b[i][j])
      hi = mi;
    else
      lo = mi+1;
  }

  return lo;
}

struct seg
{
  std::vector<int> lazy, arr;

  void push(int id, int l, int r) {
    lazy[left] += lazy[id];
    lazy[right] += lazy[id];
    arr[left] += lazy[id];
    arr[right] += lazy[id];
    lazy[id] = 0;
  }

  int query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return INF;

    if(x <= l && r <= y)
      return arr[id];

    push(id, l, r);
    return std::min(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }

  void update(int x, int y, int v, int id = 0, int l = 0, int r = n-1) {
    if(r < x || y < l)
      return;

    if(x <= l && r <= y) {
      arr[id] += v;
      lazy[id] += v;
      return;
    }

    push(id, l, r);
    update(x, y, v, left, l, mid);
    update(x, y, v, right, mid+1, r);

    arr[id] = std::min(arr[left], arr[right]);
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int m;
    std::cin >> N >> m;

    for(int i = 0; i < N; i++)
      std::cin >> a[i];
    a[N] = INF;

    std::sort(a, a+N);
    n = N+1;

    seg tree;
    tree.arr = tree.lazy = std::vector<int>(2*n-1, 0);
    for(int i = 0; i < N; i++)
      tree.update(0, i, 1);

    for(int i = 0; i < m; i++) {
      sum[i] = 0;
      b[i].clear();
      c[i].clear();
      b[i].push_back(0);

      int k;
      std::cin >> k;
      for(int j = 0; j < k; j++) {
        int x;
        std::cin >> x;
        sum[i] += x;
        b[i].push_back(x);
      }

      for(int j = 0; j <= k; j++) {
        c[i].push_back(find(i, j));
        //std::cout << c[i][j] << " ";
      }
      //std::cout << std::endl;

      tree.update(0, c[i][0], -1);
    }

    for(int i = 0; i < m; i++) {
      for(int j = 1; j < b[i].size(); j++) {
        tree.update(0, c[i][0], 1);
        tree.update(0, c[i][j], -1);

        //for(int k = 0; k <= N; k++)
          //std::cout << tree.query(k, k) << " ";
        //std::cout << std::endl;
        std::cout << (tree.arr[0] >= 0);

        tree.update(0, c[i][j], 1);
        tree.update(0, c[i][0], -1);
      }
    }

    std::cout << std::endl;
  }

  return 0;
}