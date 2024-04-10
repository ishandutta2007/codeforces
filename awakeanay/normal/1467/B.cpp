#include <algorithm>
#include <vector>
#include <iostream>

#define int long long

int n;
int calc(int i, int a[]) {
  if(i == 0 || i == n-1)
    return 0;
  if(a[i] > a[i-1] && a[i] > a[i+1])
    return 1;
  if(a[i] < a[i-1] && a[i] < a[i+1])
    return 1;
  return 0;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n;

    int vals = 0;

    int a[n];
    for(int i = 0; i < n; i++)
      std::cin >> a[i];

    std::vector<int> kind(n, 0);
    for(int i = 1; i+1 < n; i++) {
      kind[i] = calc(i, a);
      vals += kind[i];
    }

    int max = 0;
    for(int i = 1; i+1 < n; i++) {
      int cur = 0;
      int x = a[i];
      a[i] = a[i-1];
      cur = kind[i] + kind[i-1] + kind[i+1] - calc(i, a) - calc(i-1, a) - calc(i+1, a);
      max = std::max(max, cur);
      a[i] = a[i+1];
      cur = kind[i] + kind[i-1] + kind[i+1] - calc(i, a) - calc(i-1, a) - calc(i+1, a);
      max = std::max(max, cur);
      a[i] = x;
    }

    std::cout << vals - max << std::endl;
  }

  return 0;
}