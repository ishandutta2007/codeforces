#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n;
char b[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %s", &n, b + 1);
    int last = -1;
    for (int i = 1; i <= n; ++i) {
      if (b[i] == '1') {
        if (last == 2) {
          putchar('0');
          last = 1;
        } else {
          putchar('1');
          last = 2;
        }
      } else {
        if (last == 1) {
          putchar('0');
          last = 0;
        } else {
          putchar('1');
          last = 1;
        }
      }
    }
    puts("");
  }
  return 0;
}