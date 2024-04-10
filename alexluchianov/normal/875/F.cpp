#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

int mult[1 + nmax], cost[1 + nmax];

int jump(int gala) {
  if(gala != mult[gala])
    mult[gala] = jump(mult[gala]);
  return mult[gala];
}

void unite(int gala, int galb) {
  gala = jump(gala);
  galb = jump(galb);
  if(gala != galb) {
    cost[galb] += cost[gala];
    cost[gala] = 0;
    mult[gala] = galb;
  }
}

struct Event{
  int x;
  int y;
  int cost;
  bool operator < (Event const oth) {
    return cost < oth.cost;
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<Event> v;
  for(int i = 1;i <= n; i++) {
    mult[i] = i;
    cost[i] = 1;
  }

  for(int i = 1;i <= m; i++) {
    Event curr;
    std::cin >> curr.x >> curr.y >> curr.cost;
    v.push_back(curr);
  }
  std::sort(v.begin(), v.end());
  std::reverse(v.begin(), v.end());
  int result = 0;
  for(int i = 0; i < v.size(); i++) {
    int x = v[i].x, y = v[i].y, val = v[i].cost;
    x = jump(x);
    y = jump(y);
    if(0 < cost[x] + cost[y]) {
      unite(x, y);
      cost[jump(x)]--;
      result += val;
    }
  }
  std::cout << result;
  return 0;
}