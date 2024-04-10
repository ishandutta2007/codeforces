#include <iostream>
#include <vector>
#include <set>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int n = 0;

void readcircuit(std::set<int> &sol) {
  char ch;
  std::cin >> ch;
  std::set<int> aux;

  if(ch == '*') {
    n++;
    sol.insert(n);
  } else if(ch == '(') {
    readcircuit(sol);
    char op;
    std::cin >> op;
    if(op == 'S') {
      while(op != ')') {
        readcircuit(aux);
        if(aux.size() < sol.size()) {
          std::swap(sol, aux);
        }
        aux.clear();
        std::cin >> op;
      }
    } else {
      while(op != ')') {
        readcircuit(aux);
        if(sol.size() < aux.size())
          std::swap(aux, sol);
        for(std::set<int>::iterator it = aux.begin(); it != aux.end(); it++)
          sol.insert(*it);
        aux.clear();
        std::cin >> op;
      }
    }
  }
}

void solve() {
  int target;
  std::cin >> target;
  n = 0;
  std::set<int> sol;
  readcircuit(sol);

  std::cout << "REVOLTING ";
  for(int i = 1; i <= n; i++)
    if(sol.find(i) == sol.end())
      std::cout << 0 << " ";
    else
      std::cout << 1LL * sol.size() * target << " ";
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}