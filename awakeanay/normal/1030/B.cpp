#include <iostream>

std::pair<int, int> trans(std::pair<int, int> p) {
  std::pair<int, int> ret;
  ret.first = p.first + p.second;
  ret.second = p.first - p.second;
  return ret;
}

signed main() {
  int n, d;
  std::cin >> n >> d;

  std::pair<int, int> p[4];
  p[0] = {0, d};
  p[1] = {d, 0};
  p[2] = {n, n-d};
  p[3] = {n-d, n};
  std::pair<int, int> max, min;

  for(int i = 0; i < 4; i++) {
    p[i] = trans(p[i]);
  }

  max = p[0], min = p[0];

  for(int i = 1; i < 4; i++) {
    if(p[i].first > max.first)
      max.first = p[i].first;
    if(p[i].second > max.second)
      max.second = p[i].second;
    if(p[i].first < max.first)
      min.first = p[i].first;
    if(p[i].second < min.second)
      min.second = p[i].second;
  }

  int m;
  std::cin >> m;

  while(m--) {
    std::pair<int, int> cur;
    std::cin >> cur.first >> cur.second;

    cur = trans(cur);
    bool lie = true;
    if(cur.first > max.first || cur.first < min.first || cur.second > max.second || cur.second < min.second)
      lie = false;
    if(lie)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}