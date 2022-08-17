#include <iostream>
#include <map>
#include <vector>

const int MAXN = 200005;

std::map<std::pair<int, int>, int> cedge;
int happyc, dualc;
std::map<std::pair<std::pair<int, int>, int>, int> exist;

void add_edge(int u, int x, int y) {
  exist[{{u, x}, y}]++;

  if(x == y)
    happyc += exist[{{u, y}, x}];
}

void remove_edge(int u, int x, int y) {
  if(x == y)
    happyc -= exist[{{u, y}, x}];

  exist[{{u, x}, y}]--;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;

  for(int i = 0; i < m; i++) {
    char t;
    std::cin >> t;

    if(t == '?') {
      int k;
      std::cin >> k;

      if(k%2) {
        if(dualc)
          std::cout << "YES" << std::endl;
        else
          std::cout << "NO" << std::endl;
      }
      else {
        if(happyc)
          std::cout << "YES" << std::endl;
        else
          std::cout << "NO" << std::endl;
      }
    }
    else if(t == '+') {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      char c;
      std::cin >> c;

      cedge[{u, v}] = c-'a';
      if(cedge.find({v, u}) != cedge.end()) {
        //std::cout << " okay not bad " << std::endl;
        add_edge(u, c-'a', cedge[{v, u}]);
        add_edge(v, cedge[{v, u}], c-'a');
        dualc++;
      }

      //std::cout << "check " << happyc << std::endl;
    }
    else {
      int u, v;
      std::cin >> u >> v;
      u--; v--;
      auto x = cedge.find({u, v});
      auto y = cedge.find({v, u});
      if(x != cedge.end() && y != cedge.end()) {
        remove_edge(u, (*x).second, (*y).second);
        remove_edge(v, (*y).second, (*x).second);
        dualc--;
      }

      cedge.erase({u, v});
    }
  }

  return 0;
}