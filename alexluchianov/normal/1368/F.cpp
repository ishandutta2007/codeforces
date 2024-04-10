#include <iostream>
#include <cmath>
#include <cassert>
#include <set>

int const nmax = 10000;
int v[1 + nmax];
int n;

void set(int k) {
  int start;
  std::cin >> start;
  for(int i = 0; i < k; i++) {
    int id = (start + i - 1) % n + 1;
    v[id] &= 2;
  }
}

void boostp(int k) {
  std::set<int> sol;

  for(int i = 1; i <= n; i++)
    if(v[i] == 0 && 0 < k){
      v[i] = 1;
      sol.insert(i);
      k--;
    }
  for(int i = 1;i <= n; i++)
    if(0 < k && v[i] == 1 && sol.find(i) == sol.end()) {
      sol.insert(i);
      k--;
    }
  
  std::cout << sol.size() << " ";
  for(std::set<int>::iterator it = sol.begin(); it != sol.end(); it++)
    std::cout << *it << " ";  
  std::cout << '\n';
  std::cout << std::flush;
}

bool full() {
  for(int i = 1;i <= n; i++)
    if(v[i] == 0)
      return 0;
  return 1;
}

int main() {
  std::cin >> n;
  if(n <= 3) {
    std::cout << 0;
    return 0;
  }
  int block = sqrt(n);
  for(int i = 1;i <= n; i += block)
    v[i] = 2;
  while(true) {
    boostp(block);
    bool verdict = full();
    set(block);
    if(verdict == 1) {
      std::cout << 0;
      return 0;
    }
  }
}