#include <iostream>
#include <vector>

class FenwickTree{
private:
  int const lgmax = 20;
  std::vector<int> aib;
  int n;
public:
  FenwickTree(int n_) {
    n = n_;
    aib.resize(1 + n);
  }

  void update(int pos, int val) {
    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] += val;
  }
  int query(int pos) {
    int result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
  int find_lower(int target) {
    int x = 0;
    for(int jump = (1 << lgmax); 0 < jump; jump /= 2)
      if(x + jump <= n && aib[x + jump] < target) {
        target -= aib[x + jump];
        x += jump;
      }
    return x + 1;
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  
  int const lim = 1000000;
  int n, q;
  std::cin >> n >> q;
  FenwickTree aib(1 + lim);
  for(int i = 1;i <= n; i++) {
    int val;
    std::cin >> val;
    aib.update(val, 1);
  }
  for(int i = 1;i <= q; i++) {
    int val;
    std::cin >> val;
    if(0 < val)
      aib.update(val, 1);
    else {
      val = -val;
      aib.update(aib.find_lower(val), -1);
    }
  }

  if(aib.find_lower(1) <= lim)
    std::cout << aib.find_lower(1);
  else
    std::cout << 0;
  return 0;
}