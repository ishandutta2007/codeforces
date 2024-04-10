#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 1000000;
int frec[1 + nmax][3][3];

int getop(char ch) {
  if(ch == 'R')
    return 0;
  else if(ch == 'G')
    return 1;
  else
    return 2;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::string s, t;
  std::cin >> s >> t;
  int ptr = 0, ptr2 = 0;
  ll result = 0;
  
  for(int i = 1; i < t.size(); i++) {
    for(int h = 0; h < 3; h++)
      for(int h2 = 0; h2 < 3; h2++)
        frec[i][h][h2] = frec[i - 1][h][h2];
    frec[i][getop(t[i - 1])][getop(t[i])]++;
  }

  for(int i = 0; i < s.size(); i++) {
    while(ptr2 + 1 < t.size() && t[ptr2] != s[i])
      ptr2++;
    if(ptr < t.size()) {
      ptr2 = std::min((int)t.size() - 1, ptr2);
      result += ptr2 - ptr + 1;
      if(0 < i) {
        int h = getop(s[i]);
        int h2 = getop(s[i - 1]);
        if(h != h2) {
          result -= (frec[ptr2][h][h2] - frec[ptr][h][h2]);
        }
      }
    }

    if(t[ptr2] == s[i])
      ptr2++;
    if(t[ptr] == s[i])
      ptr++;
  }
  std::cout << result << '\n';
  return 0;
}