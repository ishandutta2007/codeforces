#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 2000000;
int const modulo = 51123987;
int const inv2 = (modulo + 1) / 2;

std::vector<int> manacher(std::string &init) {
  int n = init.size();
  std::string s;
  s += "#";
  for(int i = 0; i < init.size(); i++) {
    s += "*";
    s += init[i];
  }
  s += "*";
  s += "&";
  int last = 0;
  std::vector<int> p(s.size());
  for(int i = 1; i < s.size() - 1; i++) {
    if(i <= last + p[last]) {
      int ref = 2 * last - i;
      p[i] = std::min(p[ref], last + p[last] - i);
    }
    while(s[i - p[i] - 1] == s[i + p[i] + 1])
      p[i]++;
    if(last + p[last] < i + p[i])
      last = i;
  }
  return p;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  std::vector<int> p = manacher(s);
  std::vector<int> sum(n), sum2(n);
  for(int i = 0; i < s.size(); i++) {
    int val = (p[2 + i * 2] + 1) / 2;
    sum[i - val + 1]++;
    if(i + 1 < n)
      sum[i + 1]--;
    sum2[i]++;
    if(i + val < n)
      sum2[i + val]--;
  }
  for(int i = 0; i < s.size() - 1; i++) {
    int val = (p[3 + i * 2] ) / 2;
    sum[i - val + 1]++;
    if(i + 1 < n)
      sum[i + 1]--;
    sum2[i + 1]++;
    if(i + 1 + val < n)
      sum2[i + 1 + val]--;
  }
  for(int i = 1;i < s.size(); i++)
    sum[i] += sum[i - 1];
  for(int i = 1;i < s.size(); i++)
    sum2[i] += sum2[i - 1];
  int result = 0, acc = 0;
  for(int i = s.size() - 1; 0 <= i; i--) {
    result = (result + 1LL * sum2[i] * acc) % modulo;
    acc += sum[i];
    if(modulo <= acc)
      acc -= modulo;
  }
  std::cout << (modulo + 1LL * acc * (acc - 1) % modulo * inv2 % modulo - result) % modulo << '\n';
  return 0;
}