#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    int last = m;
    std::string s;
    std::cin >> s;

    std::vector<int> col(m, 0);
    std::vector<int> row(m, 0);
    int tcol = 0;
    for(int i = 0; i < n*m; i++) {
      if(s[i] == '1') {
        last = 0;
        if(col[i%m] == 0) {
          col[i%m] = 1;
          tcol++;
        }
      }
      else {
        last++;
      }

      last = std::min(m, last);

      if(last < m)
        row[i%m]++;


      std::cout << row[i%m]+tcol << " ";
    }
    std::cout << "\n";
  }

  return 0;
}