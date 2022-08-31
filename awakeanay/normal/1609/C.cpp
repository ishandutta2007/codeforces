#include <iostream>

#define int long long

const int MAXA = 1000006;

int comp[MAXA];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 2; i < MAXA; i++) {
    if(!comp[i]) {
      for(int j = i*i; j < MAXA; j+=i)
        comp[j] = 1;
    }
  }

  comp[1] = 1;

  int t;
  std::cin >> t;

  while(t--) {
    int n, d;
    std::cin >> n >> d;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    int right[n];
    int left[n];

    for(int i = 0; i < n; i++) {
      if(a[i] != 1) {
        left[i] = 0;
      }
      else {
        left[i] = 1;
        if(i-d >= 0)
          left[i] += left[i-d];
      }
    }

    for(int i = n-1; i >= 0; i--) {
      if(a[i] != 1) {
        right[i] = 0;
      }
      else {
        right[i] = 1;
        if(i+d < n)
          right[i] += right[i+d];
      }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(comp[a[i]])
        continue;

      int l = (i-d >= 0 ? left[i-d] : 0);
      int r = (i+d < n ? right[i+d] : 0);

      ans += (l+1)*(r+1) - 1;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}