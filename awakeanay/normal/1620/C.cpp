#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, k, x;
    std::cin >> n >> k >> x;

    std::string s;
    std::cin >> s;

    std::vector<int> sz1;
    std::vector<int> sz2;

    int cur = 0;
    while(cur < n) {
      int c1 = 0;
      while(cur < n && s[cur] == '*') {
        cur++;
        c1++;
      }
      sz1.push_back(c1);

      int c2 = 0;
      while(cur < n && s[cur] == 'a') {
        c2++;
        cur++;
      }
      sz2.push_back(c2);
    }

    int szz = sz1.size();
    std::vector<int> ans(szz, 0);
    std::vector<int> tot(szz, 0);

    cur = 1;
    for(int i = szz-1; i >= 0; i--) {
      ans[i] = cur;
      int lcur = cur;
      if(cur <= x) {
        cur *= sz1[i]*k + 1;
        if(cur < 0)
          cur = x+1;
      }
      tot[i] = sz1[i]*k+1;
    }

    x--;
    for(int i = 0; i < szz; i++) {
      int u = x/ans[i];
      x -= u*ans[i];
      for(int j = 0; j < u; j++)
        std::cout << 'b';
      for(int j = 0; j < sz2[i]; j++)
        std::cout << 'a';
    }

    std::cout << std::endl;
  }

  return 0;
}