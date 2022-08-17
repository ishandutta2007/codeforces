#include <iostream>
#include <vector>

#define int long long

const int MAXN = 400005;

std::vector<int> divi[MAXN];

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {

    int l, r;
    std::cin >> l >> r;

    for(int i = l; i <= 2*r; i++)
      divi[i].clear();

    for(int i = l; i <= r; i++) {
      for(int j = 2*i; j <= 2*r; j += i)
        divi[j].push_back(i);
    }

    int ct = r-l+1;
    int trip = (ct*(ct-1)*(ct-2))/6;
    //int trip = 0;

    for(int i = r; i >= l+2; i--) {
      int u = 2*i;
      int pos = divi[u].size();
      for(int j = 0; j < divi[u].size() && divi[u][j] < i; j++) {
        while(pos > 0 && divi[u][pos-1] + divi[u][j] > i)
          pos--;
        //std::cout << j << " " << pos << std::endl;
        trip -= divi[u].size()-1-std::max(pos, j+1);
      }
      //std::cout << trip << std::endl;
    }

    //std::cout << trip << std::endl;
    for(int i = r; i >= l+2; i--) {
      int u = i;
      int pos = divi[u].size()-1;
      for(int j = 0; j < divi[u].size() && divi[u][j] < i; j++) {
        while(pos > 0 && divi[u][pos-1] + divi[u][j] > i)
          pos--;
        //std::cout << j << " " << pos << std::endl;
        trip -= std::max(0ll, pos-j);
      }
    }

    std::cout << trip << "\n";
  }

  return 0;
}