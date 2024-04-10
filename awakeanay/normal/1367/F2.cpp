#include <iostream>
#include <vector>
#include <algorithm>

#define left id+1
#define mid (l+r)/2
#define right id+2*(mid-l+1)
#define MAXN 200005
#define INF 10000000000

#define int long long

int n;
struct seg
{
  std::vector<int> arr;

  void init(int sz) {
    arr = std::vector<int>(2*sz-1, INF);
    n = sz;
  }

  void upd(int x, int val, int id = 0, int l = 0, int r = n-1) {
    if(l == r) {
      arr[id] = val;
      return;
    }

    if(x <= mid)
      upd(x, val, left, l, mid);
    else
      upd(x, val, right, mid+1, r);

    arr[id] = std::min(arr[left], arr[right]);
  }

  int range(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(l > y || x > r)
      return INF;

    if(x <= l && r <= y)
      return arr[id];

    return std::min(range(x, y, left, l, mid), range(x, y, right, mid+1, r));
  }
} min, max;

std::pair<int, int> seq[MAXN];

void insert(int x) {
  min.upd(-seq[x].second, seq[x].first);
  max.upd(-seq[x].second, -seq[x].first);
}

void remove(int x) {
  min.upd(-seq[x].second, INF);
  max.upd(-seq[x].second, INF);
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    for(int i = 0; i < n; i++) {
      std::cin >> seq[i].first;
      seq[i].second = -i;
    }

    std::sort(seq, seq+n);

    min.init(n); max.init(n);

    int ans = n-1;
    int r = 0;
    for(int i = 0; i < n; i++) {
      while(r < n && (seq[r].second == 0 || -max.range(0, -seq[r].second-1) <= seq[r].first) 
                  && (seq[r].second == 1-n || min.range(1-seq[r].second, n-1) >= seq[r].first)) {
        //std::cout << i << " " << r << " " << 1-seq[r].second << " " <<  n-1 << " " << seq[r].first << std::endl;
        insert(r);
        r++;
      }
      //std::cout << i << " " << r << std::endl;
      ans = std::min(ans, n-r+i);
      remove(i);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}