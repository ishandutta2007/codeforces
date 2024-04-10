#include <iostream>
#include <vector>
#include <cassert>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

std::vector<std::pair<int,int>> st;

void print(int start, int length) {
  for(int jump = 2; jump <= length; jump *= 2) {
    for(int j = 0; j < length; j += jump) 
      for(int i = 0; i < jump / 2; i++) 
        st.push_back({start + j + i, start + j + i + jump / 2});
  }
}

int main () {
  int n;
  std::cin >> n;
  int p = 1;
  while(p * 2 <= n)
    p *= 2;
  print(1, p);
  print(n - p + 1, p);
  std::cout << st.size() << '\n';
  for(int i = 0;i < st.size(); i++)
    std::cout << st[i].first << " "<< st[i].second << '\n';
  return 0;
}