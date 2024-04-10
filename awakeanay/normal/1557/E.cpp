#include <iostream>

#define int long long

int done;
std::string s;
int rel;

void update(int x, int y) {
  if(done)
    return;

  std::cout << x << " " << y << std::endl;
  std::cin >> s;
  if(s == "Done") {
    done = true;
    return;
  }

  for(int i = 0; i < s.length(); i++) {
    if(s[i] == 'L' || s[i] == 'R')
      rel ^= 1;
    if(s[i] == 'U' || s[i] == 'D')
      rel ^= 2;
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cout << "1 1" << std::endl;
    std::cin >> s;
    int x = 1, y = 1;

    done = false;
    rel = 0;

    for(int i = 0; i < 4 && (!done); i++) { 
      int dirx = 1;
      int cur = i^rel;

      if(cur%2 != y%2 && cur/2 != x%2) {
        x = 7;
        update(x, y);
        dirx = -1;
      }

      while(!done) {
        int nx = x, ny = y;

        int cur = rel^i;
        if(cur%2 == y%2)
          ny++;
        if(cur/2 == x%2)
          nx += dirx;;

        if(((dirx == 1 && nx > 7) || (dirx == -1 && nx < 2)) || ny > 7) {
          if(x != 1)
            update(1, y);
          if(y != 1)
            update(1, 1);
          x = y = 1;
          break;
        }

        update(nx, ny);
        x = nx; y = ny;
      }
    }
  }

  return 0;
}