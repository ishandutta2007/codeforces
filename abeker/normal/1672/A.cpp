#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    int sum = 0;
    while (N--) {
      int x;
      scanf("%d", &x);
      sum += x - 1;
    }
    puts(sum % 2 ? "errorgorn" : "maomao90");
  }
  return 0;
}