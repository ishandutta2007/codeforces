#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 52;
int v[1 + nmax];
int v2[1 + nmax];
int n;

std::vector<std::vector<int>> answer;

void makemove(std::vector<int> sol) {
  for(int i = sol.size() - 1; 0 <= i; i--)
    if(sol[i] == 0)
      sol.erase(sol.begin() + i);
  if(1 == sol.size())
    return ;
  answer.push_back(sol);

  int ptr = 0;
  for(int i = 0; i < sol.size(); i++) {
    for(int j = 1; j <= sol[i]; j++)
      v2[n - ptr - sol[i] + j] = v[ptr + j];
    ptr += sol[i];
  }
  for(int i = 1;i <= n; i++)
    v[i] = v2[i];
}

int main() {
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    if(v[i] == 1) {
      makemove({i - 1, n - i + 1});
      break;
    }
  for(int i = 2;i <= n; i++) {
    int verdict = 1;
    for(int j = 1;j <= n; j++) {
      if(v[j] != j)
        verdict = 0;
    }
    if(verdict == 1)
      break;
    if(i % 2 == 0) {
      for(int j = 1; j <= n; j++)
        if(i == v[j]){
          std::vector<int> mv;
          for(int h = 1; h < i; h++)
            mv.push_back(1);
          mv.push_back(j - (i - 1));
          mv.push_back(n - j);
          makemove(mv);
          break;
        }
    } else {
      for(int j = 1;j <= n; j++)
        if(i == v[j]) {
          std::vector<int> mv;
          mv.push_back(j - 1);
          mv.push_back(n - i + 1 - j + 1);
          for(int h = 1; h < i; h++)
           mv.push_back(1);
         makemove(mv);
         break;
        }
    }
  }

  std::cout << answer.size() << '\n';
  for(int i = 0; i < answer.size(); i++) {
    std::cout << answer[i].size() << " ";
    for(int j = 0; j < answer[i].size(); j++)
      std::cout << answer[i][j] << " ";
    std::cout << '\n';
  }
  return 0;
}