#include <iostream>
#define int long long
using namespace std;

int pgcd(int a, int b) {
  if(a == 0)
    return b;
  return pgcd(b % a, a);
}

int minDec(int b, int a, int m) {
  int g = pgcd(a, m);
  return (((b % g) + g) % g);
}

signed main() {
  int la, ra, ta;
  cin >> la >> ra >> ta;

  int lb, rb, tb;
  cin >> lb >> rb >> tb;

  int AavB = minDec(lb - la, tb, ta);
  int BavA = minDec(la - lb, ta, tb);

  cout << max(0ll, max(min(ra - la + 1 - AavB, rb - lb + 1), min(rb - lb + 1 - BavA, ra - la + 1))) << endl;
  return 0;
}