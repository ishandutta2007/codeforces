#include <iostream>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  std::string s;
  std::cin >> s;
  ll result = 0;
  for(char ch = 'a'; ch <= 'z'; ch++) {
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
      if(s[i] == ch)
        sum++;
    result = std::max(result, 1LL * sum);
  }

  for(char ch = 'a'; ch <= 'z'; ch++)
    for(char ch2 = 'a'; ch2 <= 'z'; ch2++) {
      ll result2 = 0;
      int sum = 0;
      for(int i = 0; i < s.size(); i++) {
        if(s[i] == ch)
          result2 += sum;
        if(s[i] == ch2)
          sum++;
      }
      result = std::max(result, result2);
    }
  std::cout << result;
  return 0;
}