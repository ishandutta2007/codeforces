#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <functional>
#include <numeric>
#include <algorithm>

struct Student {
  int index;
  int msgs;
};

int readInt() {
  int x;
  std::cin >> x;
  return x;
}

uint32_t bit_count(uint32_t num) {
  num = num - ((num >> 1) & 0x55555555);
  num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
  return (((num + (num >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

const int MAX = 10001;

int main() {

  std::vector<uint64_t> counters(MAX, 0);

  int n = readInt();
  int k = readInt();

  for (int i = 0; i < n; ++i) {
    ++counters[readInt()];
  }

  uint64_t ans = 0;

  for (uint32_t value_i = 0; value_i < MAX; ++value_i) {
    for (uint32_t value_j = value_i; value_j < MAX; ++value_j) {
      if (bit_count(value_i ^ value_j) == k) {
        if (value_i == value_j) {
          ans += (counters[value_i] * (counters[value_i] - 1)) / 2;
        } else {
          ans += counters[value_i] * counters[value_j];
        }
      }
    }
  }

  std::cout << ans << "\n";

  return 0;
}