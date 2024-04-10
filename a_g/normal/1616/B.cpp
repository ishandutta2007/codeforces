#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
      cout << s << s << '\n';
      continue;
    }
    if (s[0] == s[1]) {
      cout << s[0] << s[0] << '\n';
      continue;
    }
    int breakpoint = n-1;
    for (int i = 0; i < n-1; i++) {
      if (s[i] < s[i+1]) {
        breakpoint = i;
        break;
      }
    }
    for (int i = 0; i <= breakpoint; i++) {
      cout << s[i];
    }
    for (int i = breakpoint; i >= 0; i--) {
      cout << s[i];
    }
    cout << '\n';
  }
}