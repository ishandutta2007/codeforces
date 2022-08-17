#include <iostream>
#include <vector>

#define int long long

int total[34];
int zeroes[34];

void count(std::vector<int> &arr, int bit) {
  std::vector<int> ones, nots;
  for(int j : arr) {
    if((j >> bit)&(1ll)) {
      ones.push_back(j);
      total[bit] += nots.size();
    }
    else {
      nots.push_back(j);
      total[bit] += ones.size();
      zeroes[bit] += ones.size();
    }
  }
  if(bit > 0) {
    if(ones.size() > 0) count(ones, bit-1);
    if(nots.size() > 0) count(nots, bit-1);
  }
}

signed main() {
  int n;
  std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; i++)
    std::cin >> a[i];

  int x = 0;
  int min = 0;

  count(a, 33);

  for(int i = 33; i >= 0; i--) {
    min += std::min(total[i]-zeroes[i], zeroes[i]);
    if(zeroes[i] > total[i]-zeroes[i])
      x ^= (1ll << i);
  }

  std::cout << min << " " << x << std::endl;

  return 0;
}