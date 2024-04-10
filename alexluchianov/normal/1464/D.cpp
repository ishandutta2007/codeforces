#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 1000000;
int const modulo = 1000000007;
int p[1 + nmax], seen[1 + nmax];

int find_cycle(int node) {
  int result = 0;
  do{
    seen[node] = 1;
    result++;
    node = p[node];
  } while(seen[node] == 0);
  return result;
}

int makematches(int ones, int twos, int fours) {
  assert((ones + twos * 2 + fours * 4) % 3 == 0);
  int result = 0;
  ones += fours;
  result += fours;
  fours = 0;
  int d = std::min(ones, twos);
  result += d;
  ones -= d;
  twos -= d;
  
  if(0 < ones) 
    return result + ones - ones / 3;
  else {
    return result + twos;
  }
}

void solve(int testcase) {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> p[i];
  std::vector<int> v;
  for(int i = 1;i <= n; i++)
    seen[i] = 0;
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      v.push_back(find_cycle(i));
  int result = 1;

  if(n % 3 == 0)
    for(int i = 1;i <= n / 3; i++)
      result = 1LL * result * 3 % modulo;
  else if(n % 3 == 1) {
    for(int i = 1;i < n / 3; i++)
      result = 1LL * result * 3 % modulo;
    result = 1LL * result * 4 % modulo;
  } else {
    for(int i = 1;i <= n / 3; i++)
      result = 1LL * result * 3 % modulo;
    result = 1LL * result * 2 % modulo;
  }
  int ones = 0, twos = 0, fours = 0, base = 0;
  for(int i = 0; i < v.size(); i++) {
    if(v[i] == 1)
      ones++;
    else if(v[i] == 2)
      twos++;
    else if(v[i] % 3 == 0) {
      base += v[i] / 3 - 1;
    } else if(v[i] % 3 == 1) {
      base += (v[i] - 4) / 3;
      fours++;
    } else if(v[i] % 3 == 2) {
      base += (v[i] - 2) / 3;
      twos++;
    }
  }
  
  int sum = (ones + twos * 2 + fours * 4);
  int threes = (n - sum) / 3;

  int result2 = n * 20;
  if(n % 3 == 0) {
    result2 = base + makematches(ones, twos, fours);
  } else if(n % 3 == 1) {
    if(0 < fours) {
      result2 = std::min(result2, base + makematches(ones, twos, fours - 1));
    } 
    if(1 < twos) {
      result2 = std::min(result2, base + makematches(ones, twos - 2, fours));
    } 
    if(1 < ones && 0 < twos) {
      result2 = std::min(result2, base + makematches(ones - 2, twos - 1, fours) + 1);
    } 
    if(3 < ones) {
      result2 = std::min(result2, base + makematches(ones - 4, twos, fours) + 2);
    }
    if(0 < ones && 0 < threes){
      result2 = std::min(result2, base + makematches(ones - 1, twos, fours) + 1);
    }
  } else {
    ones += fours;
    base += fours;
    fours = 0;
    if(0 < twos) {
      twos--;
      result2 = base + makematches(ones, twos, fours);
    } else {
      ones -= 2;
      result2 = 1 + base + makematches(ones, twos, fours);
    }
  }
  std::cout  << result << " " << result2 << '\n';
}

int main() {
  /*
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  */

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve(testcase);
  return 0;
}