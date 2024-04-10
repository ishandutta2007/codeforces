#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N, S;
    scanf("%d%d", &N, &S);
    printf("%d\n", S / (N / 2 + 1));
  }
  return 0;
}