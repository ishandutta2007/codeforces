#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

int n;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int N;
    std::cin >> N;

    n = 2*N;
    std::vector<std::pair<int, int> > ans;

    std::string s;
    std::cin >> s;

    while(true) {
      int fr[n], bk[n+1];
      int cur = 0;
      bool need = 0;
      int bcur = -1;
      for(int i = 0; i < n; i++) {
        if(s[i] == '(')
          cur++;
        else
          cur--;
        fr[i] = cur;
        if(need == 0) {
          if(bcur == -1 && cur > 0)
            bcur = i;
          if(bcur != -1 && cur > fr[bcur])
            bcur = i;
        }

        if(cur < 0)
          need = i+1;
      }

      if(!need)
        break;

      cur = 0;

      for(int i = 0; i < n; i++) {
        if(s[n-1-i] == '(')
          cur++;
        else
          cur--;
        bk[n-1-i] = cur;
      }
      bk[n] = 0;

      int cmin = bk[bcur+1];
      int out = -1;
      for(int j = bcur+1; j < n; j++) {
        cmin = std::min(bk[j], cmin);
        if((bcur == -1 ? 0 : fr[bcur])+(cmin-bk[j+1]) >= 0) {
          out = j;
        }
      }

      ans.push_back({bcur+2, out+1});
      std::reverse(s.begin()+bcur+1, s.begin()+out+1);
    }

    std::cout << ans.size() << "\n";
    for(auto j : ans)
      std::cout << j.first << " " << j.second << "\n";
  }

  return 0;
}