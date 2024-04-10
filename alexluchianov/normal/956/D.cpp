#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>

using ll = long long;
using ld = long double;

class FenwickTree{
private:
  std::vector<int> aib;
  int n;
public:
  FenwickTree(int n_) {
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val) {
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] += val;
  }
  int query(int pos) {
    int result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
};

std::map<ld, int> mp;

void normalize(std::vector<std::pair<ld, ld>> &v) {
  std::vector<ld> aux;
  for(int i = 0; i < v.size(); i++) {
    aux.push_back(v[i].first);
    aux.push_back(v[i].second);
  }
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  for(int i = 0; i < aux.size(); i++)
    mp[aux[i]] = 1 + i;
  for(int i = 0; i < v.size(); i++) {
    v[i].first = mp[v[i].first];
    v[i].second = mp[v[i].second];
  }
}

bool compare(std::pair<ld, ld> f1, std::pair<ld, ld> f2) {
  if(f1.first != f2.first)
    return f1.first < f2.first;
  else
    return f1.second > f2.second; 
}

ll solve(std::vector<std::pair<ld, ld>> &v) {
  int n = v.size(); 
  normalize(v);
  FenwickTree aib(2 * n);
  ll result = 0;
  std::sort(v.begin(), v.end(), compare);
  for(int i = 0; i < v.size(); i++) {
    result += i - aib.query(v[i].second - 1);
    aib.update(v[i].second, 1);
  }

  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, w;
  std::cin >> n >> w;
  std::vector<std::pair<ld, ld>> v;
  for(int i = 1;i <= n; i++) {
    int start, speed;
    std::cin >> start >> speed;
    v.push_back({- 1.0 * start / (speed - w), -1.0 * start / (speed + w)});
  }
  std::cout << solve(v);  
  return 0;
}