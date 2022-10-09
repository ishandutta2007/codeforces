#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 100;
int const modulo = 1000000007;
int comb[1 + nmax][1 + nmax];

void computecomb() {
  comb[0][0] = 1;
  for(int i = 1;i <= nmax; i++) {
    comb[i][0] = 1;
    for(int j = 1;j <= i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if(nmax < comb[i][j])
        comb[i][j] = nmax + 1;
    }
  }
}

struct State{
  int elements;
  int holes;
  int coef;
  int number;
  bool operator < (State const oth) {
    if(elements != oth.elements)
      return elements < oth.elements;
    else if(holes != oth.holes)
      return holes < oth.holes;
    else if(coef != oth.coef)
      return coef < oth.coef;
    return 0;
  }
  bool operator == (State const oth) {
    return elements == oth.elements &&
           holes == oth.holes &&
           coef == oth.coef;
  }
};

int main() {
  computecomb();
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<State> v, v2;

  int result = 0;
  for(int i = 1; i <= n; i++) {
    v.push_back({i, i, 1, 1});
  }
  
  for(int i = 1; i <= m; i++) {
    std::sort(v.begin(), v.end());
    std::vector<State> aux;
    std::swap(aux, v);
    for(int j = 0; j < aux.size(); j++) {
      if(0 < v.size() && v.back() == aux[j]) {
        v.back().number += aux[j].number;
        if(modulo <= v.back().number)
          v.back().number -= modulo;
      } else
        v.push_back(aux[j]);
    }

    aux.clear();
    
    for(int j = 0; j < v.size(); j++) {
      if(v[j].holes == 0)
        result = (result + 1LL * v[j].number * (m - i + 1)) % modulo;
      else
        for(int h = v[j].holes; h <= n; h++)
          if(comb[h - 1][v[j].holes - 1] * v[j].coef <= k && v[j].elements + h <= n) 
            v2.push_back({v[j].elements + h, h - v[j].holes, v[j].coef * comb[h - 1][v[j].holes - 1], v[j].number});
          else
            break;
    }
    v = v2;
    v2.clear();
  }

  std::cout << result << '\n';
  return 0;
}