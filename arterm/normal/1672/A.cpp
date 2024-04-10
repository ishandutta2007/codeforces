#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      sum += x;
    }

    int res = sum - n;

    if (res % 2 == 0) {
      cout << "maomao90\n";
    } else {
      cout << "errorgorn\n";
    }
  }

  return 0;
}