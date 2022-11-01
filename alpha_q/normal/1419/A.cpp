#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int t, n; char s[N];

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> t;
  while (t--) {
    cin >> n;
    scanf("%s", s + 1);
    if (n & 1) {
      bool first = false;
      for (int i = 1; i <= n; i += 2) {
        if (s[i] & 1) {
          first = true;
          break;
        }
      }
      puts(first ? "1" : "2");
    } else {
      bool first = true;
      for (int i = 2; i <= n; i += 2) {
        if (~s[i] & 1) {
          first = false;
          break;
        }
      }
      puts(first ? "1" : "2");
    }
  }
  return 0;
}