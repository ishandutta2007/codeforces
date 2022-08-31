#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int MAXN = 100005;
const int INF = 10000000000000000;

int arr[MAXN];
int n, q;

struct seg
{
  std::vector<int> min, max;

  void build(int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      min[id] = max[id] = arr[l];
      return;
    }

    build(left, l, mid);
    build(right, mid+1, r);

    max[id] = std::max(max[left], max[right]);
    min[id] = std::min(min[left], min[right]);
  }

  int minq(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return INF;

    if(x <= l && r <= y)
      return min[id];

    return std::min(minq(x, y, left, l, mid), minq(x, y, right, mid+1, r));
  }
  
  int maxq(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return -INF;

    if(x <= l && r <= y)
      return max[id];

    return std::max(maxq(x, y, left, l, mid), maxq(x, y, right, mid+1, r));
  }
};

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> q;

  for(int i = 0; i < n; i++)
    std::cin >> arr[i];

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    arr[i] -= x;
    if(i)
      arr[i] += arr[i-1];
  }

  seg tree;
  tree.min = tree.max = std::vector<int>(2*n-1, 0);
  tree.build();

  while(q--) {
    int l, r;
    std::cin >> l >> r;
    l--; r--;
    int sub = (l == 0 ? 0 : arr[l-1]);

    int min = tree.minq(l, r), max = tree.maxq(l, r);
    //std::cout << min << " " << max << std::endl;
    if(max-sub > 0 || arr[r] != sub)
      std::cout << -1 << std::endl;
    else
      std::cout << sub-min << std::endl;
  }

  return 0;
}