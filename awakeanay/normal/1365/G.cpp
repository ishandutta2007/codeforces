#include <iostream>
#include <vector>

#define int long long
#define MAXN 1005

std::vector<int> queries[13];
int key[MAXN];
int ans[13];

signed main() {
  int n;
  std::cin >> n;


  int done = 0;
  for(int a = 0; a < 13 && done < n; a++) {
    for(int b = a+1; b < 13 && done < n; b++) {
      for(int c = b+1; c < 13 && done < n; c++) {
        for(int d = c+1; d < 13 && done < n; d++) {
          for(int e = d+1; e < 13 && done < n; e++) {
            for(int f = e+1; f < 13 && done < n; f++) {
              key[done] = (1 << a) | (1 << b) | (1 << c) | (1 << d) | (1 << e) | (1 << f);

              queries[a].push_back(done+1);
              queries[b].push_back(done+1);
              queries[c].push_back(done+1);
              queries[d].push_back(done+1);
              queries[e].push_back(done+1);
              queries[f].push_back(done+1);

              done++;
            }
          }
        }
      }
    }
  }

  for(int i = 0; i < 13; i++) {
    if(queries[i].size() == 0)
      continue;

    std::cout << "? " << queries[i].size() << " ";
    for(int j : queries[i])
      std::cout << j << " ";
    std::cout << std::endl;
    std::cin >> ans[i];
  }

  std::cout << "! ";
  for(int i = 0; i < n; i++) {
    int ret = 0;
    for(int j = 0; j < 13; j++) {
      if(((1ll << j) & key[i]) == 0)
        ret |= ans[j];
    }
    std::cout << ret << " ";
  }

  std::cout << std::endl;
  return 0;
}