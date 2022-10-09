#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> v(1 + n), pref(1 + n);

	for(int i = 1;i <= n; i++)
		std::cin >> v[i];
  for(int i = 1;i <= n; i++)
    pref[i] = pref[i - 1] ^ v[i];

  for(int i = 3; i <= n; i++) 
    if((v[i - 1] ^ v[i]) < v[i - 2]) {

      std::cout << 1;
      return 0;
    }

  assert(n <= 100);
  int result = n;
  for(int i = 1;i <= n; i++)
    for(int j = i; j <= n; j++)
      for(int h = j + 1; h <= n; h++) {
        if((pref[h] ^ pref[j]) < (pref[j] ^ pref[i - 1])) {
          result = std::min(result, h - i - 1);
        }
      }
  if(result == n)
    std::cout << -1;
  else
    std::cout << result; 
  return 0;
}