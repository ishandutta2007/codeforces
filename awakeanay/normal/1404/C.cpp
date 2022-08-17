#include <iostream>
#include <algorithm>

#define MAXN 300005
#define int long long

int bit[MAXN];

void add(int x) {
  x += 1;
  while(x < MAXN) {
    bit[x] += 1;
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

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n, q;
  std::cin >> n >> q;

  int a[n];
  for(int i = 0; i < n; i++) {
    std::cin >> a[i];
    a[i]--;
  }

  int max[n];
  for(int i = 0; i < n; i++) {
    if(a[i] > i) {
      max[i] = -1;
      continue;
    }

    int l = 0, r = i+1;
    while(l < r) {
      int m = (l+r)/2;
      
      bool check = (sum(n-m) < (i-a[i]));

      if(check)
        r = m;
      else
        l = m+1;
    }

    max[i] = l-1;
    add(n-max[i]);
  }
  
  for(int i = 0; i < n+2; i++)
    bit[i] = 0;

  std::pair<std::pair<int, int>, int> qs[q];
  for(int i = 0; i < q; i++) {
    std::cin >> qs[i].first.second >> qs[i].first.first;
    qs[i].second = i;
  }

  std::sort(qs, qs+q);

  int r = 0;
  int ans[q];
  for(int i = q-1; i >= 0; i--) {
    int v = n-qs[i].first.first;
    while(r < v) {
      add(n-max[r]);
      r++;
    }
    ans[qs[i].second] = sum(n-qs[i].first.second);
  }

  for(int i = 0; i < q; i++)
    std::cout << ans[i] << std::endl;

  return 0;
}