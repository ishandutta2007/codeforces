#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <iomanip>

using ll = long long;
using ld = long double;

int const nmax = 300000;
int const kmax = 50;

int v[1 + nmax];
int far[1 + nmax], far2[1 + nmax];

bool compare(int x, int y) {
  if(v[x] != v[y])
    return v[x] < v[y];
  else
    return x < y;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  std::set<int> myset;
  std::vector<int> ord;
  for(int i = 1; i <= n; i++)
    ord.push_back(i);
  std::sort(ord.begin(), ord.end(), compare);
  std::reverse(ord.begin(), ord.end());
  
  ld result = 0;

  for(int i = 0; i < ord.size(); i++) {
    int node = ord[i];
    std::set<int>::iterator it = myset.lower_bound(node);
    std::vector<int> sright, sleft;
    sleft.push_back(node);
    sright.push_back(node);

    if(it != myset.end()) {
      int to = *it;
      far[to] = node;
      far2[node] = to;
      while(to != 0) {
        if(sright.size() == kmax)
          break;
        sright.push_back(to);
        to = far2[to];
      }
    }
    if(it != myset.begin()) {
      it--;
      int to = *it;
      far2[to] = node;
      far[node] = to;
      while(to != 0) {
        if(sleft.size() == kmax)
          break;
        sleft.push_back(to);
        to = far[to];
      }
    }
    sleft.push_back(0);
    sright.push_back(n + 1);
    ld sum = 0, acc = 1, sum2 = 0, acc2 = 1;
    for(int j = 0; j + 1 < sleft.size(); j++) {
      sum += acc * (sleft[j] - sleft[j + 1]);
      acc = acc / 2;
    }
    for(int j = 0; j + 1 < sright.size(); j++) {
      sum2 += acc2 * (sright[j + 1] - sright[j]);
      acc2 = acc2 / 2;
    }
    result += v[node] * sum * sum2 / 2;
    myset.insert(node);
  }
  std::cout << std::setprecision(9) << std::fixed << result / n / n<< '\n';
  return 0;
}