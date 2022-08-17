#include <iostream>

#define int long long

signed main() {
  int h, w;
  std::cin >> h >> w;

  std::string s[h];
  for(int i = 0; i < h; i++)
    std::cin >> s[i];

  int cur = 0;
  int next = 0;
  int ans = 0;
  
  int x = 0, y = 0;
  while(true) {
    if(s[x][y] == '*')
      ans++;

    if(x == h-1 && y == w-1)
      break;

    if(x == h-1)
      y++;
    else if(y == w-1)
      x++;
    else if(s[x+1][y] == '*')
      x++;
    else
      y++;
  }

  std::cout << ans << std::endl;

  return 0;
}