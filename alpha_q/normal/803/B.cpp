#include <bits/stdc++.h> 

using namespace std;

int a[200010], b[200010], n;

int main (int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int last = -100000000;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == 0) {
      last = i;
      b[i] = 0;
    } else {
      b[i] = i - last;
    }
  }
  last = 100000000;
  for (int i = n; i; --i) {
    if (a[i] == 0) {
      last = i;
    } else {
      b[i] = min(b[i], last - i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", b[i]);
  }
  puts("");
  return 0;
}