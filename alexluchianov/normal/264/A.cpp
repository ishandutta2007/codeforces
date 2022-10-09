#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int const nmax = 1000000;
int sol[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::string s;
  std::cin >> s;
  int n = s.size();
  int ptr = 0, ptr2 = n - 1;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'r')
      sol[ptr++] = 1 + i;
    else
      sol[ptr2--] = 1 + i;
  }
  for(int i = 0; i < n; i++)
    std::cout << sol[i] << '\n';
  return 0;
}