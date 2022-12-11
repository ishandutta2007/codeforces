#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;

  cout << max(0ll, min((k - 1) / 2, n - k / 2)) << endl;
  return 0;
}