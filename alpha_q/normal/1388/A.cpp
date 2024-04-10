#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n >= 45) {
      puts("YES");
      printf("6 10 14 %d\n", n - 30);
      continue;
    }
    if (n <= 30) {
      puts("NO");
      continue;
    }
    if (n <= 35) {
      puts("YES");
      printf("6 10 14 %d\n", n - 30);
      continue;
    }
    if (n <= 40) {
      puts("YES");
      printf("6 14 15 %d\n", n - 35);
      continue;
    }
    assert(n <= 44);
    puts("YES");
    printf("10 14 15 %d\n", n - 39);
  }
  return 0;
}