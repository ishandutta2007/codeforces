#include <iostream>

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
    if(n == 1) {
      std::cout << "Bob " << ((s[0]-'a')+1) << std::endl;
      continue;
    }

    int sum = 0;
    int min = 26;
    for(int i = 0; i < n; i++) {
      sum += (s[i]-'a')+1;
    }
    min = std::min((int)((s[0]-'a')+1), (int)((s[n-1]-'a')+1));

    std::cout << "Alice " << (sum - (n%2 ? 2*min : 0)) << std::endl;
  }

  return 0;
}