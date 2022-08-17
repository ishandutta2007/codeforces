#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int n;

const int INF = 2000'000'000'000'000;

struct seg
{
  std::vector<int> min, max;

  void update(int x, int v, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      min[id] = max[id] = v;
      return;
    }

    if(x <= mid)
      update(x, v, left, l, mid);
    else
      update(x, v, right, mid+1, r);

    min[id] = std::min(min[left], min[right]);
    max[id] = std::max(max[left], max[right]);
  }

  int queryMin(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return INF;

    if(x <= l && r <= y)
      return min[id];

    return std::min(queryMin(x, y, left, l, mid), queryMin(x, y, right, mid+1, r));
  }

  int queryMax(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return -INF;

    if(x <= l && r <= y)
      return max[id];

    return std::max(queryMax(x, y, left, l, mid), queryMax(x, y, right, mid+1, r));
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int N;
    std::cin >> N;

    n = N+1;
    int a[n];
    int pr[n];
    pr[0] = a[0] = 0;

    for(int i = 1; i <= N; i++) {
      std::cin >> a[i];
      pr[i] = a[i] + pr[i-1];
    }

    int next[n], prev[n];
    for(int i = 1; i <= N; i++) {
      prev[i] = i-1;
      while(prev[i] > 0 && a[prev[i]] < a[i])
        prev[i] = prev[prev[i]];
    }

    seg tree;
    tree.min = tree.max = std::vector<int>(2*n-1, 0);

    for(int i = N; i >= 1; i--) {
      next[i] = i+1;
      while(next[i] < N+1 && a[next[i]] <= a[i])
        next[i] = next[next[i]];
      tree.update(i, pr[i]);
    }

    bool poss = true;
    for(int i = 1; i <= N; i++) {
      int v = tree.queryMax(i, next[i]-1);
      int u = tree.queryMin(prev[i], i-1);
      poss &= a[i] >= v-u;
    }

    std::cout << (poss ? "YES" : "NO") << std::endl;
  }

  return 0;
}