#include <iostream>

#define MAXN 200001
#define INF 10000000000
#define int long long

int k = 18;
int st_min[MAXN][19];
int st_max[MAXN][19];
int log[MAXN+1];
int n;

int min(int L, int R) {
  int j = log[R - L + 1];
  return std::min(st_min[L][j], st_min[R - (1 << j) + 1][j]);
}

int max(int L, int R) {
  int j = log[R - L + 1];
  return std::max(st_max[L][j], st_max[R - (1 << j) + 1][j]);
}

int check(int l, int k) {
  if(l == n-1)
    return 0;

  int a1 = n, a2 = n;

  int lo = l, hi = n-1;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    if(min(l, mid) < k)
      hi = mid;
    else
      lo = mid+1;
  }

  if(min(l, lo) < k)
    a2 = lo;

  lo = l, hi = n-1;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    if(min(l, mid) <= k)
      hi = mid;
    else
      lo = mid+1;
  }

  if(min(l, lo) <= k)
    a1 = lo;

  int b1 = -1, b2 = -1;

  lo = l, hi = n-1;
  while(lo < hi) {
    int mid = (lo+hi) - (lo+hi)/2;
    if(max(mid, n-1) > k)
      lo = mid;
    else
      hi = mid-1;
  }

  if(max(lo, n-1) > k)
    b1 = lo;

  lo = l, hi = n-1;
  while(lo < hi) {
    int mid = (lo+hi) - (lo+hi)/2;
    if(max(mid, n-1) >= k)
      lo = mid;
    else
      hi = mid-1;
  }

  if(max(lo, n-1) >= k)
    b2 = lo;

  if(a1 == a2 || b1 == b2)
    return 0;

  b1++; a2--;

  //std::cout << a1 << " " << a2 << " " << b1 << " " << b2 << " " << l << " " << k <<  std::endl;

  if(a2+1 < b1 || b2 < a1+1)
    return 0;

  return std::max(a1, b1-1)-l+1;
}

signed main() {
  int t;
  std::cin >> t;

  log[1] = 0;
  for (int i = 2; i <= MAXN; i++)
    log[i] = log[i/2] + 1;

  while(t--) {
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    for(int i = 0; i < n; i++) {
      st_min[i][0] = st_max[i][0] = a[i];
    }

    for(int j = 1; j <= k; j++) {
      for(int i = 0; i + (1 << j) <= n; i++) {
        st_min[i][j] = std::min(st_min[i][j-1], st_min[i + (1 << (j - 1))][j - 1]);
        st_max[i][j] = std::max(st_max[i][j-1], st_max[i + (1 << (j - 1))][j - 1]);
      }
    }

    int cur_max = a[0];
    int done = false;
    for(int i = 0; i+2 < n; i++) {
      cur_max = std::max(cur_max, a[i]);
      int ret = check(i+1, cur_max);
      if(ret) {
        done = true;
        std::cout << "YES" << std::endl;
        std::cout << i+1 << " " << ret << " " << n-ret-i-1 << std::endl;
        break;
      }
    }

    if(!done)
      std::cout << "NO" << std::endl;
  }

  return 0;
}