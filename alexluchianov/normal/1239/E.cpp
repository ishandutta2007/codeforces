#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using ll = long long;

int const nmax = 24;
int const valmax = 50000;
int const lim = (2 * nmax) * valmax;
std::vector<int> frec[1 + lim], frec2[1 + lim];
int dp[1 << nmax];
std::pair<int,int> rem[1 + nmax];

int lg(int number) {
  return 31 - __builtin_clz(number);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v;

  for(int i = 1; i <= 2 * n; i++) {
    int val;
    std::cin >> val;
    v.push_back(val);
  }
  std::sort(v.begin(), v.end());
  int smin = v[0], smin2 = v[1];
  v.erase(v.begin());
  v.erase(v.begin());
  int sum = 0;
  n--;
  for(int i = 0; i < v.size(); i++)
    sum += v[i];
  for(int mask = 0; mask < (1 << n); mask++) {
    if(0 < mask) {
      int bit = lg((mask ^ (mask & (mask - 1))));
      dp[mask] = dp[mask & (mask - 1)] + v[bit];
    }
    frec[dp[mask]].push_back(mask);
  }
  for(int mask = 0; mask < (1 << n); mask++) {
    if(0 < mask) {
      int bit = lg((mask ^ (mask & (mask - 1))));
      dp[mask] = dp[mask & (mask - 1)] + v[n + bit];
    }
    frec2[dp[mask]].push_back(mask);
  }
  for(int i = 0; i <= nmax; i++)
    rem[i] = {0, -1};
  
  int best = -1;
  ll bestmask = 0;
  int target = sum / 2;

  for(int i = target; 0 <= i; i--) {
    for(int h = 0; h < frec2[target - i].size(); h++) {
      int mask = frec2[target - i][h];
      rem[__builtin_popcount(mask)] = {target - i, mask};
    }

    for(int h = 0; h < frec[i].size(); h++) {
      int mask = frec[i][h];
      int sz = __builtin_popcount(mask);
      if(rem[n - sz].second != -1) {
        if(best < i + rem[n - sz].first) {
          best = i + rem[n - sz].first;
          bestmask = mask + ((1LL * rem[n - sz].second)<<n);
        }
      }
    }
  }
  std::vector<int> row[2];
  row[0].push_back(smin);
  row[1].push_back(smin2);
  
  for(int i = 0; i < 2 * n; i++)
    if(0 < (bestmask & (1LL << i)))
      row[0].push_back(v[i]);
    else
      row[1].push_back(v[i]);
  std::reverse(row[1].begin(), row[1].end());
  
  for(int h = 0; h < 2; h++) {
    for(int i = 0; i < row[h].size(); i++)
      std::cout << row[h][i] << " ";
    std::cout << '\n';
  }
  return 0;
}