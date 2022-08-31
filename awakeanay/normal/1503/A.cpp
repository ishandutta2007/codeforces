#include <iostream>

#define int long long

bool check(std::string s) {
  int n = s.length();
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '(')
      count++;
    else
      count--;
    if(count < 0)
      return false;
  }
  if(count != 0)
    return false;
  return true;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::string g;
    std::cin >> g;

    std::string s(n, 'a'), t(n, 'a');
    int tot0 = 0;
    for(int i = 0; i < n; i++)
      tot0 += g[i] == '1';

    int zc = 0, oc = 0;
    for(int i = 0; i < n; i++) {
      if(g[i] == '1') {
        if(zc*2 >= tot0)
          s[i] = t[i] = ')';
        else
          s[i] = t[i] = '(';
        zc++;
      }
      else {
        if(oc%2) {
          s[i] = '(';
          t[i] = ')';
        }
        else {
          s[i] = ')';
          t[i] = '(';
        }
        oc++;
      }
    }

    if(check(s) && check(t)) {
      std::cout << "YES" << std::endl;
      std::cout << s << std::endl << t << std::endl;
    }
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}