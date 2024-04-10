#include <iostream>

using ll = long long;

int const nmax = 200000;
int const lgmax = 20;
int coef[1 + lgmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 1; i <= n; i++) {
    int val;
    std::cin >> val;
    for(int j = 0; j < lgmax; j++)
      if((1 << j) & val)
        coef[j]++;
  }
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    int number = 0;
    for(int j = 0; j < lgmax; j++)
      if(0 < coef[j]) {
        number |= (1 << j);
        coef[j]--;
      }
    result += 1LL * number * number;
  }
  std::cout << result;
}