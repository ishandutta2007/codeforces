#include <iostream>

#define int long long
#define MOD 1000000007

signed main() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  int pref[3];
  pref[0] = pref[1] = pref[2] = 0;
  int count = 1;
  for(int i = 0; i < n; i++) {
    int c[3];

    

    c[1] = 0;
    if(s[i] == 'b' || s[i] == '?')
      c[1] = pref[0];

    c[0] = 0;
    if(s[i] == 'a' || s[i] == '?')
      c[0] = count;

    c[2] = 0;
    if(s[i] == 'c' || s[i] == '?')
      c[2] = pref[1];

    if(s[i] == '?') {
      for(int i = 0; i < 3; i++)
        pref[i] = (pref[i]*3)%MOD;
    }

    for(int i = 0; i < 3; i++)
      pref[i] = (pref[i] + c[i])%MOD;

    if(s[i] == '?') {
      count = (count*3)%MOD;
    }
  }

  std::cout << pref[2] << std::endl;

  return 0;
}