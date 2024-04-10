#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 1000000007;
int dp[5 + nmax], nxt[5 + nmax];
std::vector<std::pair<int,int>> bonus[1 + nmax];

int solve(std::vector<int> v) {
  v.insert(v.begin(), 0);
  int n = v.size();

  v.push_back(1 + nmax);
  dp[0] = 1;
  for(int i = v.size() - 2; 0 <= i; i--) {
    nxt[i] = i + 1;
    while(v[nxt[i]] <= v[i])
      nxt[i] = nxt[nxt[i]];
  }
  for(int i = 0; i < n; i++) {
    int pass = 0;
    for(int h = 0; h < bonus[i].size(); h++ ){
      dp[i] += 1LL * bonus[i][h].first * bonus[i][h].second % modulo;
      if(modulo <= dp[i])
        dp[i] -= modulo;
      pass += bonus[i][h].second;
      if(modulo <= pass)
        pass -= modulo;
    }
    bonus[nxt[i]].push_back({v[nxt[i]] - v[i] ,pass});
    bonus[i + 1].push_back({v[i + 1] + 1, dp[i]});
  }
  int result = 0;
  for(int i = 0; i < n; i++){
    result += dp[i];
    if(modulo <= result)
      result -= modulo;
  }
  return result;
}

int main() {
  std::string s;
  std::cin >> s;
  int n = s.size(), sum = 0;
  std::vector<int> v;
  for(int i = 0; i < n; i++) {
    if(s[i] == '1') {
      v.push_back(sum);
      sum = 0;
    } else
      sum++;
  }
  v.push_back(sum);
  if(v.size() == 1)
    std::cout << v.back();
  else {
    std::vector<int> new_v;
    for(int i = 1; i < v.size() - 1; i++)
      new_v.push_back(v[i]);
    std::cout << 1LL * (1 + v[0]) * (1 + v.back()) % modulo * solve(new_v) % modulo << '\n';
  }
}