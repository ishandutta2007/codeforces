#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 200000;

int v[5 + nmax];
int mv[1 + nmax];

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 0;i < n; i++)
    std::cin >> v[i];
  std::sort(v, v + n);
  std::string s;
  std::cin >> s;
  
  std::vector<std::pair<int, int>> sol;
  
  int start = 0, stop = 0;
  int signstart = 0, signstop = 0;
  
  if(s[0] == 'L') {
    signstart = signstop = 1;
    start = stop = 0;
    sol.push_back({start, 1});
  } else {
    signstart = signstop = -1;
    start = stop = 0;
    sol.push_back({start, -1});
  }

  for(int i = 1;i < s.size(); i++) {
    if(s[i] == 'L') {
      if(signstop == -1) {
        stop++;
        signstop *= -1;
        sol.push_back({stop, signstop});
      } else {
        start--;
        signstart *= -1;
        sol.push_back({start, signstart});
      }
    } else {
      if(signstop == 1) {
        stop++;
        signstop *= -1;
        sol.push_back({stop, signstop});
      } else {
        start--;
        signstart *= -1;
        sol.push_back({start, signstart});
      }

    }
  }
  for(int i = 0; i < sol.size(); i++) {
    if(sol[i].second == -1)
      std::cout << v[sol[i].first + (-start)] << " " << "R\n";
    else
      std::cout << v[sol[i].first + (-start)] << " " << "L\n";
  }
  return 0;
}