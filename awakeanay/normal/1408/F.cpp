#include <iostream>
#include <vector>

std::vector<std::pair<int, int> > ans;

std::vector<int> combine(std::vector<int> a, std::vector<int> b) {
  for(int i = 0; i < a.size(); i++) {
    ans.push_back({a[i]+1, b[i]+1});
  }

  while(b.size() > 0) {
    a.push_back(b[b.size()-1]);
    b.pop_back();
  }

  return a;
}

std::pair<std::vector<int>, std::vector<int> > split(std::vector<int> vec, int a, int b) {
  std::vector<int> x, y;
  for(int i = 0; i < a; i++)
    x.push_back(vec[i]);
  for(int i = a; i < (a+b); i++)
    y.push_back(vec[i]);
  return {x, y};
}

std::vector<int> compress(int k, std::vector<int> vec[]) {
  if(k == 1)
    return vec[0];
  if(k == 2)
    return combine(vec[0], vec[1]);
  return combine(compress(k/2, vec), compress(k/2, vec+k/2));
}

std::vector<int> vec[15001];
std::vector<std::vector<int> > pows;

signed main() {
  int n;
  std::cin >> n;

  for(int i = 0; i < n; i++)
    vec[i].push_back(i);

  int p = 1;
  while(2*p <= n)
    p *= 2;

  compress(p, vec);
  compress(p, vec+n-p);

  std::cout << ans.size() << std::endl;
  for(auto j : ans)
    std::cout << j.first << " " << j.second << std::endl;

  return 0;
}