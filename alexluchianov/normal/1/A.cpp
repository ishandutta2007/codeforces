#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

int const nmax = 100000;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  int a, b , m;
  cin >> a >> b >> m;
  cout << 1LL * ((a + m - 1) / m)  * ((b + m - 1) / m);
  return 0;
}