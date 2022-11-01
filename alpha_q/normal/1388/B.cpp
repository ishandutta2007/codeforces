#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int rem = n & 3, out = n >> 2;
    int nine = n - out, eight = out;
    if (rem) --nine, ++eight;
    while (nine--) putchar('9');
    while (eight--) putchar('8');
    puts("");
  }
  return 0;
}