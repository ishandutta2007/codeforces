#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::cin >> n;

    std::map<int, int> count;
    for(int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      count[x]++;
    }

    std::vector<int> seq;
    for(auto x : count) {
      seq.push_back(x.second);
    }

    int sum = 0;
    for(int i = 0; i < seq.size(); i++)
      sum += seq[i];

    std::sort(seq.begin(), seq.end());

    int k = seq.size();
    if(seq[k-1]*2 >= n)
      std::cout << (seq[k-1]*2-n) << std::endl;
    else
      std::cout << (n%2) << std::endl;
  }

  return 0;
}