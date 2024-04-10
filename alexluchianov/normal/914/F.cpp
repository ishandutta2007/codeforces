#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <bitset>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int const sigma = 26;
std::bitset<1 + nmax> v[1 + sigma];
std::bitset<1 + nmax> base;

std::bitset<1 + nmax> extract(int x, int y, int n) {
  return (base<<x) & (base>>(n - y - 1));
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  std::string s;
  std::cin >> s;
  int n = s.size();

  for(int i = 0; i < n; i++)
    v[s[i] - 'a'][i] = 1;
  int q;
  std::cin >> q;
  for(int i = 0; i < n; i++)
    base[i] = 1;
  for(int i = 1;i <= q; i++) {
    int op;
    std::cin >> op;
    if(op == 1) {
      int pos;
      char ch;
      std::cin >> pos >> ch;
      pos--;
      v[s[pos] - 'a'][pos] = 0;
      s[pos] = ch;
      v[s[pos] - 'a'][pos] = 1;
    } else {
      int x, y;
      std::cin >> x >> y;
      x--;
      y--;
      std::string part;
      std::cin >> part;
      if(part.size() <= y - x + 1) {
        std::bitset<1 + nmax> start = extract(x, y - part.size() + 1, n);
        for(int j = 0; j < part.size(); j++)
          start &= (v[part[j] - 'a']>>j);
        std::cout << start.count() << '\n';
      } else
        std::cout << 0 << '\n';
    }
  }
  return 0;
}