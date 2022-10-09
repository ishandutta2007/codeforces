#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>


using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

struct Person{
  int time;
  int x, y;
} v[1 + nmax];

int dist(Person a, Person b) {
  return fabs(a.x - b.x) + fabs(a.y - b.y);
}

int dp[1 + nmax], pref[1 + nmax];

int main() {
  int range, n;
  std::cin >> range >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i].time >> v[i].x >> v[i].y;
  v[0] = {0, 1, 1};
  dp[0] = pref[0] = 1;
  for(int i = 1;i <= n; i++) {
    dp[i] = -n;
    for(int j = std::max(0, i - 1000); j < i; j++)
      if(dist(v[i], v[j]) <= v[i].time - v[j].time)
        dp[i] = std::max(dp[i], dp[j] + 1);
    if(0 <= i - 1000)
      dp[i] = std::max(dp[i], pref[i - 1000] + 1);
    if(0 < i)
      pref[i] = std::max(pref[i - 1], dp[i]);
  }
  std::cout << pref[n] - 1;
  return 0;
}