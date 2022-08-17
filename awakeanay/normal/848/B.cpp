/*
Author: AwakeAnay
Date: 14/02/2020
Time: 22:44:18
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 300000
#define OFF 100000

int
main() {
  int n, dim[2];
  std::cin >> n >> dim[0] >> dim[1];

  int fin[n][2];
  std::vector<std::pair<int, std::pair<int, int> > > cat[MAX];
  std::vector<std::vector<int> > len(MAX, std::vector<int>(2, 0));
  for(int i = 0; i < n; i++) {
    int g, p, t;
    std::cin >> g >> p >> t;
    g = 2-g;

    cat[p-t+OFF].push_back({g, {(2*g-1)*p, i}});
    len[p-t+OFF][g]++;
    fin[i][g] = dim[g];
    fin[i][1-g] = p;
    
    //std::cout << p-t << std::endl;
  }

  for(int i = 0; i < MAX; i++)
    std::sort(cat[i].begin(), cat[i].end());
 
  int ans[n];
  for(int i = 0; i < MAX; i++) {
    for(int j = 0; j < cat[i].size(); j++) {
      //std::cout << cat[i][j].first << " " << cat[i][j].second.first << " " << cat[i][j].second.second << std::endl;
      ans[cat[i][j].second.second] = cat[i][(j + (2*(len[i][0]<len[i][1])-1)*std::min(len[i][0], len[i][1]) + cat[i].size())%cat[i].size()].second.second;
    }
  }
  
  for(int i = 0; i < n; i++) {
	//std::cout << ans[i] << std::endl;
    std::cout << fin[ans[i]][0] << " " << fin[ans[i]][1] << std::endl;
  }

  return 0;
}