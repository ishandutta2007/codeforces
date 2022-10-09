#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 200000;
int v[1 + nmax];
int n;
std::vector<int> sol;

void makemove(int pos) {
  if(1 <= pos && pos <= n - 2) {
    int val = v[pos] ^ v[pos + 1] ^ v[pos + 2];
    v[pos] = v[pos + 1] = v[pos + 2] = val;
    sol.push_back(pos);
  }
}

void solve() {
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  int sum = 0;
  for(int i = 1;i <= n; i++)
    sum ^= v[i];
  if(sum == 1) {
    std::cout << "NO\n";
    return ;
  }

  sum = 0;
  bool verdict = false;
  sol.clear();

  for(int i = 1;i <= n && verdict == false; i++) {
    sum ^= v[i];
    if(v[i] == 0 && sum == 0) {
      for(int j = i - 1; 1 <= j; j--)
        while(v[j] == 1) {
          if(v[j - 1] == 1)
            makemove(j - 1);
          else
            makemove(j - 2);
        }
      for(int j = i + 1; j <= n; j++)
        while(v[j] == 1) {
          if(v[j + 1] == 1)
            makemove(j - 1);
          else
            makemove(j);
        }
      verdict = true;
    }
  }

  int last = 0;
  for(int i = 1;i <= n && verdict == false; i++) {
    if(v[i] == 1) {
      if((i - last) % 2 == 0) {
        for(int j = last; j + 2 < i; j += 2)
          makemove(j);
        makemove(i - 2);

        for(int j = i - 1; 1 <= j; j--)
          while(v[j] == 1) {
            if(v[j - 1] == 1)
              makemove(j - 1);
            else
              makemove(j - 2);
          }
        for(int j = i + 1; j <= n; j++)
          while(v[j] == 1) {
            if(v[j + 1] == 1)
              makemove(j - 1);
            else
              makemove(j);
          }
        verdict = true;
      }
      last = i;
    }
  }
  
  if(verdict == false) {
    std::cout << "NO\n";
    return ;
  }

  std::cout << "YES\n";
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " " ;
  std::cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}