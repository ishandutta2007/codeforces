#include <iostream>

#define int long long

int test(std::string s) {
  int remA = 5, remB = 5;
  int gA = 0, gB = 0;

  for(int i = 0; i < 10; i++) {
    if(i%2) {
      remB--;
      gB += s[i]=='1';
    }
    else {
      remA--;
      gA += s[i]=='1';
    }

    if(remA+gA < gB || remB+gB < gA)
      return i+1;
  }
  return 10;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    std::string st;
    st = s;

    int min = 15;
    for(int i = 0; i < 10; i++)
      if(s[i] == '?')
        st[i] = (i%2 ? '1' : '0');
    min = std::min(min, test(st));

    st = s;
    for(int i = 0; i < 10; i++)
      if(s[i] == '?')
        st[i] = (i%2 ? '0' : '1');

    min = std::min(min, test(st));
    std::cout << min << std::endl;
  }

  return 0;
}