#include <iostream>
using namespace std;

long long pgcd(long long a, long long b) {
  if(b == 0)
    return a;
  return pgcd(b, a % b);
}

int main() {
  long long a, b, x, y;
  cin >> a >> b >> x >> y;

  long long pg = pgcd(x, y);
  x /= pg;
  y /= pg;

  cout << min(a / x, b / y) << endl;
  return 0;
}