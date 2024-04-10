#include <iostream>

using namespace std;

typedef long long llong;

int main () {
  llong n, k;
  cin >> n >> k;

  llong maxa = (k - 1) / 2;
  llong mina = max(k - n, 1LL);

  cout << max(0LL, maxa - mina + 1) << endl;
}