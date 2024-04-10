#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <functional>
#include <numeric>

int readInt() {
  int x;
  std::cin >> x;
  return x;
}

int main() {

  int group_count = readInt();
  std::vector<int> groups;

  for (int i = 0; i < group_count; ++i) {
    groups.push_back(readInt());
  }

  int sum = std::accumulate(groups.begin(), groups.end(), 0);
  std::cout << sum / group_count << "\n";

  return 0;
}