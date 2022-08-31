#include <iostream>

int par[101];

int root(int a[], int l, int r) {
  int max = l;
  for(int i = l+1; i <= r; i++)
    if(a[i] > a[max])
      max = i;

  if(max != l)
    par[root(a, l, max-1)] = max;
  if(max != r)
    par[root(a, max+1, r)] = max;

  return max;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    par[root(a, 0, n-1)] = -1;
    for(int i = 0; i < n; i++) {
      int cp = i;
      int ans = 0;
      while(par[cp] != -1) {
        ans++;
        cp = par[cp];
      }
      std::cout << ans << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}