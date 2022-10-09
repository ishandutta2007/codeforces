#include <iostream>
#include <vector>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
int v[1 + nmax], pref[1 + nmax];

int main() {
  int n;
  std::cin >> n;
  ll result = 0;
  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    pref[i] = std::max(pref[i - 1], v[i] + 1);
    result -= v[i] + 1;
  }
  int height = pref[n];

  for(int i = n; 1 <= i; i--) {
    height = std::max(height - 1, pref[i]);
    result += height;
  }
  std::cout << result;
  return 0;
}