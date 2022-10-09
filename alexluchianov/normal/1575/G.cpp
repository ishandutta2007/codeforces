#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 100000;
int const modulo = 1000000007;

std::vector<int> divs[1 + nmax];
int v[1 + nmax];
int dp[1 + nmax], dp2[1 + nmax], _count[1 + nmax];
std::vector<int> aux;

int extract(int start, int n) {
  aux.clear();

  for(int j = start; j <= n; j += start) {
    for(int h = 0;h < divs[v[j]].size(); h++) {
      _count[divs[v[j]][h]]++;
      if(1 == _count[divs[v[j]][h]])
        aux.push_back(divs[v[j]][h]);
    }
  }
  std::sort(aux.begin(), aux.end());
  
  int result = 0;

  for(int h = aux.size() - 1; 0 <= h; h--) {
    int node = aux[h];
    dp2[node] = (dp2[node] + 1LL * _count[node] * _count[node]) % modulo;
    result = (result + 1LL * dp2[node] * node) % modulo;
    for(int j = 0; j < divs[node].size(); j++) {
      dp2[divs[node][j]] -= dp2[node];
      if(dp2[divs[node][j]] < 0) {
        dp2[divs[node][j]] += modulo;
      }
    }
  }

  for(int h = 0; h < aux.size(); h++)
    _count[aux[h]] = dp2[aux[h]] = 0;
  return result;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  for(int i = 1;i <= nmax; i++)
    for(int j = i; j <= nmax; j += i)
      divs[j].push_back(i);

  for(int i = 1; i <= n; i++)
    std::cin >> v[i];
  int result = 0;

  for(int i = n; 1 <= i; i--) {
    dp[i] = extract(i, n);
    for(int j = i * 2; j <= n; j += i) {
      dp[i] -= dp[j];
      if(dp[i] < 0)
        dp[i] += modulo;
    }
    result = (result + 1LL * dp[i] * i) % modulo;
  }
  std::cout << result << '\n';
  return 0;
}