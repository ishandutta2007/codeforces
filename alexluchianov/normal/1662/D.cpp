#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

std::string reduce(std::string s) {
  std::string result;
  for(int i = 0; i < s.size(); i++) {
    result += s[i];
    bool cuts = true;
    while(cuts == true) {
      int len = result.size();
      if(2 <= result.size() && result[len - 2] == result[len - 1]) {
        result.pop_back();
        result.pop_back();
      } else if(3 <= result.size() && (result[len - 3] == result[len - 1] && (result[len - 1] == 'B' || result[len - 2] == 'B'))) {
        char ch = result[len - 2];
        result.pop_back();
        result.pop_back();
        result.pop_back();
        result.push_back(ch);
      } else
        cuts = false;
    }
  }
  return result;
}

std::string reduceF(std::string s) {
  std::string result;
  bool bcount = 0;
  for(int i = 0; i < s.size(); i++)
    if(s[i] == 'B')
      bcount ^= 1;
    else
      result += s[i];
  if(bcount == 1)
    result += 'B';
  return result;
}

bool solve() {
  std::string s, s2;
  std::cin >> s >> s2;
  return reduceF(reduce(s)) == reduceF(reduce(s2));
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    if(solve())
      std::cout << "YES\n";
    else
      std::cout << "NO\n";
  return 0;
}