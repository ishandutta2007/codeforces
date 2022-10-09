#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using ll = long long;

int const nmax = 100000;
int a[5 + nmax], b[5 + nmax];

int solve() {
  int n;
  std::cin >> n;
  for(int i = 1;i <= n; i++)
    std::cin >> b[i];
  for(int i = 1; i <= n; i++)
    std::cin >> a[i];
  ll result = 0;
  for(int i = 1;i <= n; i++)
    result += a[i];
  for(int i = 1;i <= n; i++)
    result -= b[i];

  std::multiset<int> pq1, pq2, pq3;
  std::multiset<int>::iterator it;

  for(int i = 1;i <= n; i++)
    pq1.insert(a[i]);
  for(int i = 1;i <= n; i++)
    pq2.insert(b[i]);

  for(int i = 1;i <= n / 4; i++) {
    it = pq1.begin();
    result -= *it;
    pq3.insert(*it);
    pq1.erase(it);
  }
  for(int i = 1;i <= n / 4; i++) {
    it = pq2.begin();
    result += *it;
    pq2.erase(it);
  }

  if(result <= 0)
    return 0;
  int coef = 0;
  while(true) {
    ++coef;
    pq1.insert(0);
    pq2.insert(100);
    result -= 100;
    
    if(0 < pq3.size()) {
      it = pq3.end();
      it--;
      
      pq1.erase(pq1.find(0));
      pq1.insert(*it);
      result += *it;
      pq3.erase(it);
      pq3.insert(0);
    }

    if((n + coef) % 4 == 0) {
      it = pq1.begin();
      result -= *it;
      pq3.insert(*it);
      pq1.erase(it);
      
      it = pq2.begin();
      result += *it;
      pq2.erase(it);
    }
    if(result <= 0)
      return coef;
  }
}

int main() {
  int t;
  std::cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    std::cout << solve() << '\n';
  return 0;
}