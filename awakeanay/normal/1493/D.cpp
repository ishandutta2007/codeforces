#include <iostream>
#include <set>
#include <vector>

#define int long long

const int MOD = 1000000007;

std::vector<std::multiset<int> > vals;
int gcd = 1;
std::vector<int> np;
int n;

void add(int i, int p) {
  vals[i].insert(p);

  if(vals[i].count(p) == 1) {
    np[p]++;
  }

  if(np[p] == n) {
    gcd = (gcd*p)%MOD;
    np[p] = 0;
    for(int j = 0; j < n; j++) {
      vals[j].erase(vals[j].find(p));
      np[p] += (vals[j].count(p) > 0);
    }
  }
}

std::vector<int> fact(int x) {
  std::vector<int> ret;
  for(int i = 2; i*i <= x; i++) {
    if(x%i == 0) {
      while(x%i == 0) {
        x /= i;
        ret.push_back(i);
      }
    }
  }
  if(x != 1)
    ret.push_back(x);
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int q;
  std::cin >> n >> q;

  vals = std::vector<std::multiset<int> >(n);
  np = std::vector<int>(200005, 0);

  for(int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    std::vector<int> next = fact(x);
    for(int j : next)
      add(i, j);
  }

  for(int i = 0; i < q; i++) {
    int u, x;
    std::cin >> u >> x;
    u--;
    std::vector<int> next = fact(x);
    for(int j : next)
      add(u, j);
    std::cout << gcd << std::endl;
  }

  return 0;
}