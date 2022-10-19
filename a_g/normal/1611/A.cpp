#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool even(char c) {
  return (c-'1')&1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string n;
    cin >> n;
    int m = n.size();
    if (even(n[m-1])) {
      cout << 0 << '\n';
    }
    else if (even(n[0])) {
      cout << 1 << '\n';
    }
    else {
      bool good = 0;
      for (char c: n) {
        if (even(c)) {
          cout << 2 << '\n';
          good = 1;
          break;
        }
      }
      if (!good) {
        cout << "-1\n";
      }
    }
  }
}