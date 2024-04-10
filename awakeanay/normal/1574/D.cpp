#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long

const int INF = 1000000000000;

bool comp(const std::vector<int> &a, const std::vector<int> &b) {
  int s = 0;
  for(int j : a)
    s += j;
  for(int j : b)
    s -= j;
  return s > 0;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<int> a[n];
  for(int i = 0; i < n; i++) {
    int c;
    std::cin >> c;
    for(int j = 0; j < c; j++) {
      int x;
      std::cin >> x;
      a[i].push_back(x);
    }
  }

  int m;
  std::cin >> m;

  std::vector<int> build[m];
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      int x;
      std::cin >> x;
      x--;
      build[i].push_back(x);
    }
  }

  std::sort(build, build+m, comp);

  std::set<std::vector<int> > s;
  for(int i = 0; i < m; i++) {
    s.insert(build[i]);
  }

  std::vector<int> full;
  for(int i = 0; i < n; i++)
    full.push_back(((int)a[i].size())-1);


  std::vector<int> best;
  int best_cur = -1;

  if(!s.count(full)) {
    best = full;
  }
  else {
    for(int i = 0; i < m; i++) {
      std::vector<int> cur = build[i];
      int sum = 0;
      for(int j = 0; j < n; j++)
        sum += a[j][cur[j]];
      for(int j = 0; j < n; j++) {
        if(cur[j] > 0) {
          sum -= a[j][cur[j]];
          cur[j]--;
          sum += a[j][cur[j]];
          if(!s.count(cur)) {
            if(sum > best_cur) {
              best_cur = sum;
              best = cur;
            }
          }
          sum -= a[j][cur[j]];
          cur[j]++;
          sum += a[j][cur[j]];
        }
      }
    }
  }

  for(int j : best)
    std::cout << j+1 << " ";
  std::cout << std::endl;

  return 0;
}