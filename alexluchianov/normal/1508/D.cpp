#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 2000;

struct Point{
  ll x;
  ll y;
  int id;
  bool avoid;
};

ll det3(Point a, Point b, Point c) {
  return a.x * b.y + a.y * c.x + b.x * c.y -
         (a.x * c.y + a.y * b.x + b.y * c.x);
}

Point orig;

bool compare(Point a, Point b) {
  return 0 <= det3(orig, a, b);
}
Point v[1 + nmax];
int val[1 + nmax], seen[1 + nmax];

void explore(int node) {
  seen[node] = 1;
  if(seen[val[node]] == 0)
    explore(val[node]);
}

int main() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i].x >> v[i].y >> val[i];
    v[i].id = i;
    if(val[i] != i)
      orig = v[i];
  }
  if(orig.id == 0) {
    std::cout << 0 << '\n';
    return 0;
  }
  for(int i = 1; i <= n; i++)
    if(val[i] != i && ( v[i].x < orig.x || (v[i].x == orig.x && v[i].y < orig.y)))
      orig = v[i];
  std::vector<Point> ord;
  
  for(int i = 1; i <= n; i++)
    if(orig.id != v[i].id && val[v[i].id] != v[i].id)
      ord.push_back(v[i]);

  int last = 0;
  std::vector<std::pair<int,int>> sol;
  
  std::sort(ord.begin(), ord.end(), compare);
  for(int i = 0;i < ord.size(); i++) {
    int node = ord[i].id;
    if(node != val[node]) {
      if(seen[node] == 0) {
        explore(node);
        if(0 < last) {
          std::swap(val[last], val[node]);
          sol.push_back({last, node});
        }
      } 
      last = node;
    }
  }
  int start = orig.id;
  while(val[start] != start) {
    sol.push_back({start, val[start]});
    std::swap(val[start], val[val[start]]);
  }

  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i].first << " " << sol[i].second << '\n';
  return 0;
}