#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

int N;
const int INF = 10000000000;

struct seg
{
  std::vector<int> min, max, lazy;

  void push(int id, int l, int r) {
    if(lazy[id]) {
      min[left] += lazy[id];
      max[left] += lazy[id];
      lazy[left] += lazy[id];
      min[right] += lazy[id];
      max[right] += lazy[id];
      lazy[right] += lazy[id];
      lazy[id] = 0;
    }
  }

  int qmin(int x, int y, int l = 0, int r = N-1, int id = 0) {
    if(y < l || r < x)
      return INF;

    if(x <= l && r <= y)
      return min[id];

    push(id, l, r);
    return std::min(qmin(x, y, l, mid, left), qmin(x, y, mid+1, r, right));
  }

  int qmax(int x, int y, int l = 0, int r = N-1, int id = 0) {
    if(y < l || r < x)
      return -INF;

    if(x <= l && r <= y)
      return max[id];

    push(id, l, r);
    return std::max(qmax(x, y, l, mid, left), qmax(x, y, mid+1, r, right));
  }

  void update(int x, int y, int v, int l = 0, int r = N-1, int id = 0) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      lazy[id] += v;
      min[id] += v;
      max[id] += v;
      return;
    }

    push(id, l, r);
    update(x, y, v, l, mid, left);
    update(x, y, v, mid+1, r, right);
    min[id] = std::min(min[left], min[right]);
    max[id] = std::max(max[left], max[right]);
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[n];
  std::vector<std::pair<int, int> > help;
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    help.push_back({a[i], i+1});
  }

  std::sort(help.begin(), help.end());

  N = n+1;
  seg tree;
  tree.min = tree.max = tree.lazy = std::vector<int>(2*N-1, 0);

  for(int i = 1; i <= n; i++)
    tree.update(i, i, -i);

  int ans[n+1];
  for(int i = 1; i <= n; i++)
    ans[i] = 0;

  int j = 0;
  for(int i = 0; i < help.size(); i++) {
    while(j < n && help[j].first <= help[i].first) {
      tree.update(help[j].second, N-1, 2);
      j++;
    }

    int cur = tree.qmax(help[i].second, n)-tree.qmin(0, help[i].second-1);
    int k = help[i].second;
    ans[k] = std::max(ans[k], (cur-1)/2);
  }

  tree.min = tree.max = tree.lazy = std::vector<int>(2*N-1, 0);

  for(int i = 1; i <= n; i++)
    tree.update(i, i, -i);

  j = n-1;
  for(int i = n-1; i >= 0; i--) {
    while(j >= 0 && help[j].first >= help[i].first) {
      tree.update(help[j].second, N-1, 2);
      j--;
    }

    int cur = tree.qmax(help[i].second, n)-tree.qmin(0, help[i].second-1);
    int k = help[i].second;
    ans[k] = std::max(ans[k], (cur)/2);
  }

  for(int i = 1; i <= n; i++)
    std::cout << ans[i] << " ";
  std::cout << std::endl;
  return 0;
}