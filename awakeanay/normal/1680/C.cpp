#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();

    std::vector<int> pos1;
    std::vector<int> pr(n, 0);
    pos1.push_back(-1);
    int c1 = 0;
    for(int i = 0; i < n; i++) {
      pr[i] = i > 0 ? pr[i-1] : 0;
      if(s[i] == '1') {
        pos1.push_back(i);
        c1++;
      }
      else
        pr[i]++;
    }
    pos1.push_back(n);
    pr.push_back(pr.back());

    if(c1 <= 1) {
      std::cout << 0 << std::endl;
      continue;
    }

    int lo = 0, hi = n;
    while(lo < hi) {
      int mid = (lo+hi)/2;

      int take = std::min(mid, c1);
      bool poss = false;
      for(int i = 0; i <= take; i++) {
        int l = pos1[i+1];
        int r = pos1[c1-(take-i)];
        if(pr[r] - (l == 0 ? 0 : pr[l-1]) <= mid)
          poss = true;
      }

      if(poss)
        hi = mid;
      else
        lo = mid+1;
    }

    std::cout << lo << std::endl;
  }

  return 0;
}