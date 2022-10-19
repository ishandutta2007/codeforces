#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  printf("%d\n", M & (1 << min(N, 30)) - 1);
  return 0;
}