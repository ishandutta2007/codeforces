#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();
    
    int pre[n];
    for(int i = 0; i < n; i++) {
      pre[i] = s[i] - '0';
      if(i) pre[i] += pre[i-1];
    }

    int ans = n;
    for(int i = 0; i < n; i++) {
      int cur = pre[i] + (n - (i+1) - (pre[n-1] - pre[i]));
      ans = std::min(cur, ans);
      cur = (i+1 - pre[i]) + (pre[n-1] - pre[i]);
      ans = std::min(cur, ans);
    }

    std::cout << ans << std::endl;
  }

  return 0;
}