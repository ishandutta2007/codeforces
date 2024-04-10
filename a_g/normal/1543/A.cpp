#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    if (a == b) {
      cout << "0 0\n";
      continue;
    }
    long long d = abs(a-b);
    long long x = min(a%d, d-a%d);
    cout << d << " " << x << '\n';
  }
}