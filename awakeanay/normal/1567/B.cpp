#include <iostream>

#define int long long

const int MAXN = 300005;

int pref[MAXN];
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  pref[0] = 0;
  for(int i = 1; i < MAXN; i++)
    pref[i] = pref[i-1]^i;

  while(t--) {
    int a, b;
    std::cin >> a >> b;

    if(pref[a-1] == b)
      std::cout << a << std::endl;
    else if((pref[a-1]^b) != a)
      std::cout << a+1 << std::endl;
    else
      std::cout << a+2 << std::endl;
  }

  return 0;
}