#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int t, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) {
      cout << "9\n";
      continue;
    }
    cout << "98"; n -= 2;
    int at = 9;
    while (n--) {
      putchar('0' + at);
      ++at, at %= 10;
    }
    puts("");
  }
  return 0;
}