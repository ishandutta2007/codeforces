#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, a, b;
    std::cin >> n >> a >> b;

    int seq[n];
    int m = n/2;
    seq[m-1] = a;
    seq[m] = b;
    std::vector<int> mark(n+1, 0);
    mark[a] = mark[b] = 1;
    int j = n;
    for(int i = 0; i+1 < m; i++) {
      while(mark[j])
        j--;
      mark[j] = 1;
      seq[i] = j;
    }

    j = 1;
    for(int i = n-1; i > m; i--) {
      while(mark[j])
        j++;
      mark[j] = 1;
      seq[i] = j;
    }

    int minl = n+1;
    int minr = 0;
    for(int i = 0; i < m; i++) {
      minl = std::min(minl, seq[i]);
      minr = std::max(minr, seq[n-i-1]);
    }

    if(minl == a && minr == b) {
      for(int i = 0; i < n; i++)
        std::cout << seq[i] << " ";
      std::cout << std::endl;
    }
    else
      std::cout << -1 << std::endl;
  }

  return 0;
}