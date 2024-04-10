#include <bits/stdc++.h>
using namespace std;

int s (int a) {
  // XOR of 1, 2, ..., a
  int ans = 0;
  if (!(a & 1)) {
    ans += a;
  }
  if (a % 4 == 1 || a % 4 == 2) {
    ans += 1;
  }
  return ans;
}

int main () {
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    int c = s(a-1);
    if (c == b) {
      cout << a << endl;
    }
    else  {
      if ((c^a) == b) {
        cout << a+2 << endl;
      }
      else {
        cout << a+1 << endl;
      }
    }
  }
}