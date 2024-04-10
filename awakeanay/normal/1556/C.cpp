#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  int a[n];
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int ans = 0;

  for(int i = 0; i < n; i+=2) {
    int c = 0, o = 0;
    for(int j = i+1; j < n; j++) {
      if(j%2 == 1) {
        int ex1 = std::max(a[i]-c+1, 0ll);
        int ex2 = std::max(a[j]-o+1, 0ll);
        ans += std::min(ex1, ex2);

        int cur = a[j];
        int next = std::min(o, a[j]);
        o -= next;
        cur -= next;
        c += cur;
      }
      else {
        int cur = a[j];
        o += a[j];
      }
    }
  }

  std::cout << ans-n/2 << std::endl;

  return 0;
}