#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using ll = long long;

int const nmax = 500000;
int const lgmax = 30;
std::multiset<int> myset[1 + lgmax];
ll sum[1 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int q;
  std::cin >> q;
  for(int i = 1;i <= q; i++) {
    char op;
    int val;
    std::cin >> op >> val;
    int p = 0;
    while((1 << (p + 1)) <= val)
      p++;
    if(op == '+') {
      sum[p] += val;
      myset[p].insert(val);
    } else {
      sum[p] -= val;
      myset[p].erase(myset[p].find(val));
    }
    int result = 0;
    ll curr = 0;
    for(int j = 0; j <= lgmax; j++) {
      if(0 < myset[j].size()) {
        if(0 < curr) {
          if(curr * 2 < *myset[j].begin())
            result--;
        }
        curr += sum[j];
      }
      result += myset[j].size();
    }
    std::cout << std::max(0, result - 1) << '\n';
  }
}