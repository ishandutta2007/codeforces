#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int const sigma = 26;
int frec[5 + sigma];

void solve() {
  std::string s;
  std::cin >> s;
  for(int i = 0; i < sigma; i++)
    frec[i] = 0;
  for(int i = 0; i < s.size(); i++) {
    frec[s[i] - 'a']++;
  }
  std::vector<std::pair<int,int>> v;
  for(int i = 0; i < sigma; i++)
    if(0 < frec[i])
      v.push_back({i, frec[i]});
  
  int smin = -1;
  for(int i = 0; i < v.size(); i++)
    if(1 == v[i].second && smin == -1)
      smin = i;
  
  if(-1 != smin) {
    std::cout << (char)(v[smin].first + 'a');
    for(int i = 0; i < v.size(); i++)
      if(smin != i)
        for(int j = 0; j < v[i].second; j++)
          std::cout << (char)(v[i].first + 'a');
  } else if(v.size() == 1) {
    for(int i = 0; i < v[0].second; i++)
      std::cout << char(v[0].first + 'a');
  } else if(v.size() == 2) {
    if(v[0].second - v[1].second <= 2) {
      v[0].second -= 2;
      v[1].second --;
      std::cout << (char)(v[0].first + 'a') << (char)(v[0].first + 'a') << (char)(v[1].first + 'a');
      while(0 < v[0].second && 0 < v[1].second) {
        v[0].second--;
        v[1].second--;
        std::cout << (char)(v[0].first + 'a') << (char)(v[1].first + 'a');
      }

      for(int i = 0; i < v[1].second; i++)
        std::cout << (char)(v[1].first + 'a');
      for(int i = 0; i < v[0].second; i++)
        std::cout << (char)(v[0].first + 'a');
    } else {
      v[0].second--;
      std::cout << (char)(v[0].first + 'a');
      for(int i = 0; i < v[1].second; i++)
        std::cout << (char)(v[1].first + 'a');
      for(int i = 0; i < v[0].second; i++)
        std::cout << (char)(v[0].first + 'a');
    }
  } else {
    if(v[0].second * 2 <= s.size() + 2) {
      v[0].second -= 2;
      v[1].second --;
      std::cout << (char)(v[0].first + 'a') << (char)(v[0].first + 'a') << (char)(v[1].first + 'a');
      int ptr = 1;
      while(true) {
        while(ptr < v.size() && v[ptr].second == 0)
          ptr++;
        if(ptr == v.size() || 0 == v[0].second || 0 == v[ptr].second)
          break;
        v[0].second--;
        v[ptr].second--;
        std::cout << (char)(v[0].first + 'a') << (char)(v[ptr].first + 'a');
      }
      for(int i = 0; i < v[0].second; i++)
        std::cout << (char)(v[0].first + 'a');
      v[0].second = 0;
      for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].second; j++)
          std::cout << (char)(v[i].first + 'a');
    } else {
      v[0].second--;
      v[1].second--;
      std::cout << (char)(v[0].first + 'a') << (char)(v[1].first + 'a');
      for(int i = 0; i < v[0].second; i++)
        std::cout << (char)(v[0].first + 'a');
      v[0].second = 0;
      std::cout << (char)(v[2].first + 'a');
      v[2].second--;
      for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].second; j++)
          std::cout << (char)(v[i].first + 'a');
    }
  }
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    solve();
  }
  return 0;
}