#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

signed main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > adj(n, std::vector<int>(n, 0));
  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--; v--;
    adj[u][v] = adj[v][u] = true;
  }

  for(int i = 0; i < n; i++)
    adj[i][i] = 1;

  std::vector<int> root(n, -1);

  for(int i = 0; i < n; i++) {
    if(root[i] != -1)
      continue;

    for(int j = i+1; j < n; j++) {
      bool poss = true;
      for(int k = 0; k < n && poss; k++)
        poss &= adj[i][k] == adj[j][k];
      if(poss)
        root[j] = i;
    }
  }
  
  std::set<int> list[n];

  for(int i = 0; i < n; i++) {
    if(root[i] != -1)
      continue;
    for(int j = 0; j < n; j++) {
      if(root[j] == -1 && i != j && adj[i][j])
        list[i].insert(j);
    }
  }

  std::vector<int> val(n, -1);

  bool poss1 = true;
  for(int i = 0; i < n; i++)
    poss1 &= list[i].size() <= 2;

  if(!poss1) {
    std::cout << "No" << std::endl;
    return 0;
  }

  int count = -2;
  for(int i = 0; i < n; i++) {
    if(list[i].size() == 0 && root[i] == -1) {
      count += 2;
      val[i] = count;
    }
    else if(list[i].size() == 1 && val[i] == -1) {
      count += 2;
      val[i] = count;
      int next = *list[i].begin();
      int prev = i;

      while(list[next].size() != 1) {
        val[next] = ++count;

        int out;
        for(int j : list[next]) {
          if(j != prev) {
            out = j;
          }
        }

        prev = next;
        next = out;
      }

      val[next] = ++count;
    }
  }

  bool poss2 = true;
  for(int i = 0; i < n; i++)
    if(root[i] == -1 && val[i] == -1)
      poss2 = false;

  poss2 &= count < 3;

  if(!poss2) {
    std::cout << "No" << std::endl;
    return 0;
  }


  std::cout << "Yes" << std::endl;
  for(int i = 0; i < n; i++) {
    int x = root[i] < 0 ? i : root[i];
    std::cout << (char)(val[x] + 'a');
  }

  std::cout << std::endl;

  return 0;
}