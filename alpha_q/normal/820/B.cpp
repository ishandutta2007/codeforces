#include <bits/stdc++.h> 

using namespace std;

int main() {
  int n, a;
  cin >> n >> a;
  int minVal = 1000000000, k;
  for (int i = 1; i <= n - 2; ++i) {
    int val = abs(180 * i - n * a);
    if (val < minVal) {
      minVal = val;
      k = i;
    }
  }
  cout << 1 << " " << k + 2 << " " << k + 1 << endl;
  return 0;
}