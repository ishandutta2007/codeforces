#include <iostream>
#include <algorithm>
#include <vector>

const int MAXN = 15;

std::vector<int> cur, best;
int valc, valb;
int x[MAXN];
std::string s[MAXN];
int n, m;

int abso(int x) {
  if(x < 0)
    return -x;
  return x;
}

void eval() {
  valc = 0;
  for(int i = 0; i < n; i++) {
    int ct = 0;
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '1')
        ct += cur[j]+1;
    }
    valc += abso(ct-x[i]);
  }
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n >> m;
    cur = best = std::vector<int>(m);
    valb = -1;

    for(int i = 0; i < n; i++)
      std::cin >> x[i];

    for(int i = 0; i < n; i++)
      std::cin >> s[i];

    int k = (1 << n);
    for(int i = 0; i < k; i++) {
      std::vector<std::pair<int, int> > io(m);
      for(int j = 0; j < m; j++)
        io[j] = {0, j};

      for(int p = 0; p < n; p++) {
        for(int q = 0; q < m; q++) {
          if(s[p][q] == '1') {
            if((i >> p)&1)
              io[q].first += 1;
            else
              io[q].first -= 1;
          }
        }
      }

      std::sort(io.begin(), io.end());

      int ct = 0;
      for(int j = 0; j < m; j++)
        cur[io[j].second] = ct++;

      eval();
      if(valc > valb) {
        valb = valc;
        best = cur;
      }
    }

    for(int j : best)
      std::cout << j+1 << " ";
    std::cout << std::endl;
  }

  return 0;
}