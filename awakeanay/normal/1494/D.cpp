#include <iostream>
#include <vector>

std::vector<int> col, par;
std::vector<std::vector<int> > arr(501, std::vector<int>(501, 0));

int calc(int n, std::vector<int> &next) {
  if(n == 1) {
    col[next[0]] = arr[next[0]][next[0]];
    return next[0];
  }

  int id = col.size();
  par.push_back(-1); col.push_back(-1);

  int max = -1;
  for(int i = 0; i < n; i++)
    max = std::max(max, arr[next[0]][next[i]]);

  col[id] = max;
  std::vector<int> vis(n, false);

  for(int i = 0; i < n; i++) {
    if(vis[i])
      continue;

    std::vector<int> rec;

    for(int j = 0; j < n; j++) {
      if(arr[next[i]][next[j]] != max) {
        vis[j] = true;
        rec.push_back(next[j]);
      }
    }

    int m = rec.size();
    int p = calc(m, rec);
    par[p] = id;
  }

  return id;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      std::cin >> arr[i][j];
    }
  }

  col = par = std::vector<int>(n, -1);
  std::vector<int> init;
  for(int i = 0; i < n; i++)
    init.push_back(i);

  int root = calc(n, init);

  std::cout << col.size() << std::endl;
  for(int j : col)
    std::cout << j << " ";
  std::cout << std::endl;
  std::cout << root+1 << std::endl;
  for(int i = 0; i < par.size(); i++) {
    if(i == root)
      continue;
    std::cout << i+1 << " " << par[i]+1 << std::endl;
  }

  return 0;
}