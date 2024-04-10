#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

bool isnumber(char ch) {
  return '0' <= ch && ch <= '9';
}

std::string convert(int number) {
  if(number == 0)
    return "";
  else 
    return convert((number -1) / 26) + (char)('A' + (number - 1) % 26);
}

int convert2(std::string s) {
  int number = 0;
  for(int i = 0; i < s.size(); i++) 
    number = number * 26 + (s[i] - 'A' + 1);

  return number;
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++) {
    std::string s;
    std::cin >> s;
    int dif = 0;
    for(int j = 1; j < s.size(); j++)
      if((isnumber(s[j - 1]) ^ isnumber(s[j])) == 1)
        dif++;
    if(dif == 1) {
      int ptr = 0;
      std::string s2;
      while(ptr < s.size() && isnumber(s[ptr]) == 0) {
        s2 = s2 + s[ptr];
        ptr++;
      }
      int number = 0;
      while(ptr < s.size() && isnumber(s[ptr]) == 1) {
        number = number * 10 + (s[ptr] - '0');
        ptr++;
      }
      std::cout << "R" << number << "C" << convert2(s2) << '\n';
      
    } else {
      int ptr = 1;
      int number = 0, number2 = 0;
      while(ptr < s.size() && isnumber(s[ptr]) == 1) {
        number = number * 10 + s[ptr] - '0';
        ptr++;
      }
      ptr++;
      while(ptr < s.size() && isnumber(s[ptr]) == 1) {
        number2 = number2 * 10 + s[ptr] - '0';
        ptr++;
      }
      std::cout << convert(number2) << number << '\n';
    }
  }
}