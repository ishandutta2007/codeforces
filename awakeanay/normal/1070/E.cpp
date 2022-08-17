#include <iostream>
#include <algorithm>
#include <vector>

#define int long long
#define MAXN 500005
#define left id+1
#define mid (l+r)/2
#define right id+2*(mid-l+1)

std::vector<int> bit, seg;

int n, m;
void build(int id = 0, int l = 0, int r = n-1) {
  seg[id] = r-l+1;
  if(l < r) {
    build(left, l,  mid);
    build(right, mid+1, r);
  }
}

void add(int x, int val) {
  x += 1;
  while(x < n+1) {
    bit[x] += val;
    x += (x&(-x));
  }
}

int sum(int x) {
  int ret = 0; x += 1;
  while(x > 0) {
    ret += bit[x];
    x -= (x&(-x));
  }
  return ret;
}

int find(int k, int id = 0, int l = 0, int r = n-1) {
  if(l == r)
    return l;

  if(k <= seg[left])
    return find(k, left, l, mid);
  else return find(k-seg[left], right, mid+1, r);
}

int sneak(int x) {
  return x - x%m - m*(x%m == 0);
}

void upd(int x, int val, int id = 0, int l = 0, int r = n-1) {
  if(l == r) {
    seg[id] = val;
    return;
  }

  if(x <= mid)
    upd(x, val, left, l, mid);
  else
    upd(x, val, right, mid+1, r);

  seg[id] = seg[left] + seg[right];
}

signed main() {
  int c;
  std::cin >> c;

  while(c--) {
    std::cin >> n;
    int  t;
    std::cin >> m >> t;

    bit = std::vector<int>(n+1, 0);
    seg = std::vector<int>(2*n + 5, 0);
    int p[n];
    std::vector<std::pair<int, int> > help;
    for(int i = 0; i < n; i++) {
      std::cin >> p[i];
      add(i, p[i]);
      help.push_back({p[i], i});
    }

    std::sort(help.begin(), help.end());
    build();

    int last = n-1;
    int best = 0;
    int ans = 1;
    int cur = help[n-1].first;
    while(last >= 0) {
      cur = help[last].first;
      int l = 0, r = seg[0];
      while(l < r) {
        if(sum(find(mid)) + (sneak(mid) > 0 ? sum(find(sneak(mid))) : 0) > t)
          r = mid;
        else
          l = mid+1;
      }
      if(sum(find(l)) + (sneak(l) > 0 ? sum(find(sneak(l))) : 0) > t) {
        l--;
      }
      //std::cout << l << std::endl;
      if(l > best) {
        ans = cur;
        best = l;
      }

      while(last >= 0 && help[last].first == cur) {
        add(help[last].second, -help[last].first);
        upd(help[last].second, 0);
        last--;
      }
    }

    std::cout << best << " " << std::min(t, ans) << std::endl;
  }

  return 0;
}