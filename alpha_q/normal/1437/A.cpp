#include <bits/stdc++.h>

using namespace std;

int t, l, r;

int main() {
  cin >> t;
  while (t--) {
    cin >> l >> r;
    puts(r < l + l ? "YES" : "NO");
  }
  return 0;
}