#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#define int long long
using namespace std;

set<int> divisors(int nb) {
  set<int> res;
  for(int i = 1;i * i <= nb;i++) {
    if(nb % i == 0) {
      res.insert(i);
      if(nb != i * i) {
	res.insert(nb / i);
      }
    }
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  int nb;
  cin >> nb;

  set<int> divs = divisors(nb);

  set<int> res;

  for(int div : divs) {
    int first = 1;
    int last = 1 + nb - div;
    res.insert((first + last) * (nb / div) / 2);
  }

  for(int val : res) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}