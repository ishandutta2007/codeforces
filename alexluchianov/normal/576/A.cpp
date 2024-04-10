#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 1000;
int primeCount[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  for(int i = 2;i <= n; i++)
    if(primeCount[i] == 0)
      for(int j = i; j <= n; j += i)
        primeCount[j]++;
  int result = 0;
  for(int i = 2;i <= n; i++)
    result += (primeCount[i] == 1);
  std::cout << result << '\n';
  for(int i = 2;i <= n; i++)
    if(primeCount[i] == 1)
      std::cout << i << " ";
  std::cout << '\n';
  return 0;
}