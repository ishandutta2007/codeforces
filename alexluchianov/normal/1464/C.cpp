#include <iostream>
#include <vector>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const sigma = 60;
int frec[1 + sigma];

int main() {
  int n;
  ll total;
  std::cin >> n >> total;
  std::string s;
  std::cin >> s;
  total -= (1LL<<(s[n - 1] - 'a'));
  total += (1LL<<(s[n - 2] - 'a'));

  for(int i = 0; i < n - 2; i++) {
    total += (1LL<<(s[i] - 'a'));
    frec[s[i] - 'a' + 1]++;
  }
  if(total < 0 || total % 2 == 1) {
    std::cout << "No";
    return 0;
  }

  for(int i = 1; i <= sigma; i++) {
    if(0 < (total & (1LL << i))) {
      if(0 < frec[i]) {
        frec[i]--;
        total -= (1LL << i);
      }
    }
    if(0 < frec[i]) {
      frec[i + 1] += frec[i] / 2;
      frec[i] %= 2;
    }
  }
  if(0 < total)
    std::cout << "No";
  else
    std::cout << "Yes";
  return 0;
}