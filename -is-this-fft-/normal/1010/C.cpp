#include <iostream>

using namespace std;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

const int MAX_N = 1e5 + 5;

int main () {
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;

  int gc = k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    gc = gcd(gc, x % k);
  }

  cout << k / gc << endl;
  for (int i = 0; i < k; i += gc) {
    cout << i << " ";
  }
  cout << endl;
}