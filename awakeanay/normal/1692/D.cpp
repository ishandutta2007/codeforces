#include <iostream>
#include <vector>

#define int long long

int conv(int a, int b) {
  return a*60 + b;
}

std::pair<int, int> take(std::string s) {
  int a = (s[0]-'0')*10 + (s[1]-'0');
  int b = (s[3]-'0')*10 + (s[4]-'0');
  return {a, b};
}

int check(int x) {
  int a = x/60;
  int b = x%60;
  int p = a%10;
  int q = a/10;
  int u = b%10;
  int v = b/10;
  int r = u*10 + v;
  int ret = (p == v && q == u);
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;
    auto next = take(s);
    std::vector<int> mark(1440, 0);
    int x;
    std::cin >> x;
    int cur = conv(next.first, next.second);

    int ans = 0;
    while(true) {
      if(mark[cur])
        break;
      ans += check(cur);
      mark[cur] = 1;
      cur = (cur + x)%1440;
    }

    std::cout << ans << std::endl;
  }

  return 0;
}