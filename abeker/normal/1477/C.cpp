#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector <pair <int, int>> pts(N);
  for (auto &it : pts)
    scanf("%d%d", &it.first, &it.second);
  int prev = 0;
  vector <int> rest(N - 1);
  iota(rest.begin(), rest.end(), 1);
  printf("1");
  while (!rest.empty()) {
    auto sqr = [&](int x) {
      return (long long)x * x;
    };
    auto dist = [&](int x, int y) { 
      return sqr(pts[x].first - pts[y].first) + sqr(pts[x].second - pts[y].second); 
    };
    auto it = max_element(rest.begin(), rest.end(), [&](int x, int y) { return dist(prev, x) < dist(prev, y); } );
    printf(" %d", *it + 1);
    prev = *it;
    rest.erase(it);
  }
  puts("");
  return 0;
}