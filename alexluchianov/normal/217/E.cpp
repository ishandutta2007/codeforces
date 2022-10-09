#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

using ll = long long;

int const nmax = 5000;
int l[1 + nmax], r[1 + nmax];

class FenwickTree{
private:
  std::vector<int> aib;
  int n;
public:
  FenwickTree(int n_ = 0){
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val) {
    for(int x = pos; x <= n; x += x ^ (x & (x - 1)))
      aib[x] += val;
  }
  int query(int pos) {
    int result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result;
  }
  int find_target(int target) {
    int x = 0;
    for(int jump = (1 << 21); 0 < jump; jump /= 2)
      if(x + jump < n && aib[x + jump] < target) {
        x += jump;
        target -= aib[x];
      }
    return x + 1;
  }
};

std::string sol;
std::string origin;
FenwickTree aib;

void solve(int n, int k) {
  if(n == 0) {
    assert(k <= origin.size());
    for(int i = 0; i < k; i++) {
      int pos = aib.find_target(1);
      aib.update(pos, -1);
      sol[pos - 1] = origin[i];
    }
  } else {
    if(r[n] < k) {
      int el = std::min(k - r[n], r[n] - l[n] + 1);
      std::vector<int> aux, aux2;
      int secpos = l[n] + 1;
      for(int i = 1;i <= el; i++) {
        if(r[n] < secpos)
          secpos = l[n];
        int pos = aib.find_target(r[n] + 1);
        aib.update(pos, -1);
        aux.push_back(pos);
        aux2.push_back(aib.find_target(secpos));
        secpos += 2;
      }

      solve(n - 1, k - el);
      for(int i = 0; i < aux.size(); i++) {
        sol[aux[i] - 1] = sol[aux2[i] - 1];
      }
    } else
      solve(n - 1, k);
  }
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int k, n;
  std::cin >> origin >> k >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> l[i] >> r[i];
  sol.resize(k);
  aib = FenwickTree(k);
  for(int i = 1; i <= k; i++)
    aib.update(i, 1);
  solve(n, k);
  std::cout << sol << '\n';
  return 0;
}