#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <set>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

class FenwickTree{
private:
  int n;
  std::vector<ll> aib;
public:
  FenwickTree(int n_) {
    n = n_;
    aib.resize(1 + n);
  }
  void update(int pos, int val) {
    if(pos == 0) {
      aib[0] += val;
      return ;
    }

    for(int x = pos; x <= n; x += (x ^ (x & (x - 1))))
      aib[x] += val;
  }
  ll query(int pos) {
    ll result = 0;
    for(int x = pos; 0 < x; x = (x & (x - 1)))
      result += aib[x];
    return result + aib[0];
  }
};

int const nmax = 200000;
int const lim = 1000000;

int v[1 + nmax], v2[1 + nmax];

int first_lower(std::multiset<int> &myset, int val) {
  std::multiset<int>::iterator it = myset.upper_bound(val);
  if(it == myset.begin())
    return -lim;
  it--;
  return *it;
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m, q;
  std::cin >> n >> m >> q;
  FenwickTree aib1(lim), aibsum1(lim), aib2(lim), aibsum2(lim);
  std::multiset<int> st1, st2;

  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    aib1.update(v[i], 1);
    aibsum1.update(v[i], v[i]);
    st1.insert(v[i]);
  }
  for(int i = 1;i <= m; i++) {
    std::cin >> v2[i];
    aib2.update(v2[i], 1);
    aibsum2.update(v2[i], v2[i]);
    st2.insert(v2[i]);
  }
  
  int step = 0;

  for(int i = 1;i <= q; i++) {
    int type;
    std::cin >> type;
    if(type == 1) {
      int pos, x;
      std::cin >> pos >> x;
      aib1.update(v[pos], -1);
      aibsum1.update(v[pos], -v[pos]);
      st1.erase(st1.find(v[pos]));

      v[pos] = x;
      aib1.update(v[pos], 1);
      aibsum1.update(v[pos], v[pos]);
      st1.insert(v[pos]);

    } else if(type == 2) {
      int pos, x;
      std::cin >> pos >> x;
      aib2.update(v2[pos], -1);
      aibsum2.update(v2[pos], -v2[pos]);
      st2.erase(st2.find(v2[pos]));

      v2[pos] = x;
      aib2.update(v2[pos], 1);
      aibsum2.update(v2[pos], v2[pos]);
      st2.insert(v2[pos]);

    } else if(type == 3) {
      int k;
      std::cin >> k;
      int smin = std::min(*st1.begin(), *st2.begin());
      int oth = std::max(first_lower(st1, smin + k), first_lower(st2, smin + k));
      
      ll global1 = aibsum1.query(lim), global2 = aibsum2.query(lim);

      ll result = global1 - global2 - std::min(1LL * (smin - k) * (n - m), 1LL * (oth - k) * (n - m));
      ll result2 = result, result3 = result, result4 = result;
      
      if(smin <= *st2.rbegin() - k) {
        int cap = *st2.rbegin() - k;
        result2 = global1 - 1LL * smin * n - (global2 - aibsum2.query(cap) - 1LL * cap * (m - aib2.query(cap)));
      }
      
      std::multiset<int>::iterator it = st1.upper_bound(*st2.rbegin() + k);
      if(it != st1.begin()) 
        it--;
      
      if(smin <= *it - k) {
        int cap = *it - k;
        result3 = global1  - 1LL * smin * n - (*it - smin) + k - (global2 - aibsum2.query(cap) - 1LL * cap * (m - aib2.query(cap)));
        it++;
        if(it != st1.end() && smin <= *it - k) {
          int cap = *it - k;
          result4 = global1  - 1LL * smin * n - (*it - smin) + k - (global2 - aibsum2.query(cap) - 1LL * cap * (m - aib2.query(cap)));
        }
      }
      it = st1.lower_bound(smin + k);
      if(it != st1.end() && smin <= *it - k) {
        int cap = *it - k;
        result4 = std::max(result4, global1  - 1LL * smin * n - (*it - smin) + k - (global2 - aibsum2.query(cap) - 1LL * cap * (m - aib2.query(cap))));
      }

      std::cout << std::max(result, std::max(result2, std::max(result3, result4))) << '\n';

    }
  }
  return 0;
}