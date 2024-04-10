#include <iostream>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int cur = 1;
    for(int i = n-1; i >= 0; i--) {
      int u = s[i]-'0';
      int ncur;
      ncur = -(u > cur);
      int v = (cur-u+10)%10;
      s[i] = '0' + v;
      if(i == 0)
        cur = ncur + 1;
      else
        cur = ncur + (s[0] == '9');
    }

    std::cout << s << std::endl;
  }

  return 0;
}