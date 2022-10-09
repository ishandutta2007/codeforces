#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

int const nmax = 100000;
int const threshold = 100;
int const kmax = 5;
int const inf = 2000000001;

int v[5 + nmax][1 + kmax], weight[5 + nmax];
int id[5 + nmax];

void normalize(int n, int m) {
  std::vector<int> aux;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      aux.push_back(v[i][j]);
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      v[i][j] = std::lower_bound(aux.begin(), aux.end(), v[i][j]) - aux.begin() + 1;
}

namespace FastTransform{
  std::bitset<5 + nmax> mem[5 + kmax * threshold];
  int newPtr() {
    static int ptr = 1;
    mem[ptr].set();
    return ptr++;
  }
  void update(int ptr, int pos) {
    mem[ptr][pos] = 0;
  }
};

std::vector<int> frec[5 + nmax * kmax];
int fastId[5 + nmax * kmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  
  for(int i = 1;i <= n; i++) {
    for(int j = 1; j <= m; j++)
      std::cin >> v[i][j];
    std::cin >> weight[i];
  }
  for(int i = 1;i <= n; i++)
    id[i] = i;
  std::sort(id + 1, id + n + 1, [&](int x, int y) {return weight[x] < weight[y];});
  normalize(n, m);
  for(int i = 1;i <= n; i++) {
    int pos = id[i];
    for(int j = 1; j <= m; j++)
      frec[v[pos][j]].push_back(i);
  }
  int lim = n * m;
  for(int i = 1;i <= lim; i++)
    if(nmax / threshold <= frec[i].size()) {
      fastId[i] = FastTransform::newPtr();
      for(const auto &pos : frec[i]) {
        FastTransform::update(fastId[i], pos);
      }
    }
  std::bitset<5 + nmax> base, curr;
  for(int i = 1;i <= n; i++)
    base[i] = 1;
  int result = inf;
  for(int i = 1;i <= n; i++) {
    int pos = id[i];
    curr = base;
    for(int j = 1; j <= m; j++) {
      int val = v[pos][j];
      if(fastId[val] == 0)
        for(const auto &cand : frec[val])
          curr[cand] = 0;
      else
        curr = curr & FastTransform::mem[fastId[val]];
    }
    int target = curr._Find_first();
    if(target <= n)
      result = std::min(result, weight[pos] + weight[id[target]]);
  }
  if(result < inf)
    std::cout << result << '\n';
  else
    std::cout << -1 << '\n';
  return 0;
}